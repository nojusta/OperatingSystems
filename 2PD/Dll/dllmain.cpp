#include "pch.h"
#include "dll.h"
#include <filesystem>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <windows.h>
#include <limits>
#include <ShlObj.h> 

// Laiko matavimas
long long measureTime() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::high_resolution_clock::now().time_since_epoch()
    ).count();
}

// Ping testas
void runPingTest(const std::string& ipAddress) {
    std::string tempFile = "mano.txt";
    std::string command = "ping " + ipAddress + " > " + tempFile;
    system(command.c_str());
    system(("notepad " + tempFile).c_str());

    std::cout << "Ping test baigtas." << std::endl;
    system("pause"); 

    system(("del " + tempFile).c_str());
}

std::string g_basePath;

void createDirectories(const std::string& firstName, const std::string& lastName) {
    std::string root = lastName;
    
    bool success = false;
    try {
        std::filesystem::create_directory(root);
        success = true;
    } 
    catch (const std::filesystem::filesystem_error&) {
        success = false;
    }
    
    if (!success) {
        char appDataPath[MAX_PATH];
        if (SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_LOCAL_APPDATA, NULL, 0, appDataPath))) {
            g_basePath = std::string(appDataPath) + "\\KubineKreive\\";
            std::filesystem::create_directory(g_basePath);
            root = g_basePath + lastName;
            std::filesystem::create_directory(root);
        }
    }

    for (int i = 1; i <= 3; i++) {
        std::string subdir = root + "\\" + firstName + std::to_string(i);
        std::filesystem::create_directory(subdir);

        for (int j = 1; j <= 3; j++) {
            std::string subsubdir = subdir + "\\" + firstName + std::to_string(i) + firstName + std::to_string(j);
            std::filesystem::create_directory(subsubdir);
        }
    }
}

// Kubinės kreivės skaičiavimas
void calculateCubic(int F, int x0, int xn, double dx) {
    if (dx <= 0) return;

    // Patikrinti zingsni - apsaugoti nuo per mazu zingsniu
    if (dx < 0.001) {
        dx = 0.001; // Apribojam minimalu zingsni, kad isvengtume per ilgu skaiciavimu
    }

    // Sukuriame vektori visiem failams, planuosim irasyti i visa failystema
    std::vector<std::string> filePaths;
    std::string lastName = "Stankevicius";
    std::string firstName = "Nojus";

    // Sudarom failu keliu sarasa pagal sukurta direktoriju struktura
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            std::string path;
            if (!g_basePath.empty()) {
                path = g_basePath + lastName + "\\" + firstName + std::to_string(i) + "\\" +
                    firstName + std::to_string(i) + firstName + std::to_string(j) + "\\data.txt";
            } else {
                path = lastName + "\\" + firstName + std::to_string(i) + "\\" +
                    firstName + std::to_string(i) + firstName + std::to_string(j) + "\\data.txt";
            }
            filePaths.push_back(path);
        }
    }

    // Tikriname ar turim failus
    if (filePaths.empty()) {
        std::cout << "Nerasta failu kreives duomenims" << std::endl;
        return;
    }

    int fileIndex = 0;
    size_t totalFiles = filePaths.size();
    int totalPoints = 0;

    // Pereiti per nurodyta x intervala
    for (double x = x0; x <= xn; x += dx) {
        // Tschirnhausen kubine kreive: F = x³ + 3x² - y²
        // Issprestu pagal y: y² = x³ + 3x² - F
        double underRoot = x * x * x + 3 * x * x - F;

        // Tikriname ar po saknim teigiamas skaicius (ar funkcija siame taske egzistuoja)
        if (underRoot >= 0) {
            double y1 = sqrt(underRoot);
            double y2 = -y1;  // Del simetrijos turime dvi reiksmes

            // Atidarome faila ir irasome pirma taska
            std::ofstream file1(filePaths[fileIndex], std::ios::app);
            if (file1.is_open()) {
                file1 << x << " " << y1 << std::endl;
                file1.close();
                totalPoints++;
            }

            // Pereiti prie kito failo
            fileIndex = (fileIndex + 1) % totalFiles;

            // Irasome antra taska tik jei jis skirtingas
            if (y1 != y2) {
                std::ofstream file2(filePaths[fileIndex], std::ios::app);
                if (file2.is_open()) {
                    file2 << x << " " << y2 << std::endl;
                    file2.close();
                    totalPoints++;
                }

                // Pereiti prie kito failo
                fileIndex = (fileIndex + 1) % totalFiles;
            }
        }
    }

    std::cout << "Baigti skaiciavimai su F=" << F << ", is viso tasku: " << totalPoints << std::endl;
}

// Duomenų sujungimas
void mergeFiles(int F) {
    // Sudarom tas pacias direktoriju strukturas kaip calculateCubic
    std::vector<std::string> filePaths;
    std::string lastName = "Stankevicius";
    std::string firstName = "Nojus";

    // Sudarom failu keliu sarasa pagal sukurta direktoriju struktura
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            std::string path;
            if (!g_basePath.empty()) {
                path = g_basePath + lastName + "\\" + firstName + std::to_string(i) + "\\" +
                    firstName + std::to_string(i) + firstName + std::to_string(j) + "\\data.txt";
            } else {
                path = lastName + "\\" + firstName + std::to_string(i) + "\\" +
                    firstName + std::to_string(i) + firstName + std::to_string(j) + "\\data.txt";
            }
            filePaths.push_back(path);
        }
    }

    std::ofstream outFile("merged_F" + std::to_string(F) + ".txt");
    std::vector<std::pair<double, double>> points;

    // Nuskaitome visus taškus iš failų
    for (const auto& file : filePaths) {
        std::ifstream inFile(file);
        if (inFile.is_open()) {
            double x, y;
            while (inFile >> x >> y) {
                points.emplace_back(x, y);
                //std::cout << "Nuskaitytas taskas: " << x << " " << y << " is " << file << std::endl;
            }
            inFile.close();

            // Isvalome faila (bet nepasaliname)
            std::ofstream clearFile(file, std::ios::trunc);
            clearFile.close();
        }
    }

    // Surusiuojame taskus pagal x
    std::sort(points.begin(), points.end());

    // Irasome surusiuotus taskus
    for (const auto& p : points) {
        outFile << p.first << " " << p.second << "\n";
    }

    outFile.close();
    std::cout << "Sukurtas " << "merged_F" + std::to_string(F) + ".txt" << " su " << points.size() << " tasku" << std::endl;
}

// Aplankų pašalinimas
void removeDirectories() {
    std::string lastName = "Stankevicius";
    
    if (!g_basePath.empty()) {
        std::filesystem::remove_all(g_basePath + lastName);
        std::cout << "Sekmingai pasalintos direktorijos is " << g_basePath << std::endl;
    } else {
        std::filesystem::remove_all(lastName);
        std::cout << "Sekmingai pasalintos direktorijos" << std::endl;
    }
}
