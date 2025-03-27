#include "pch.h"
#include "dll.h"
#include <filesystem>
#include <fstream>
#include <vector>
#include <algorithm>

// Laiko matavimo funkcija
std::chrono::high_resolution_clock::time_point measureTime() {
    return std::chrono::high_resolution_clock::now();
}

// Ping testo funkcija (atitinka Stud_ID % 3 + 1 = 2)
void runPingTest(const std::string& ipAddress) {
    // Sukuriamas laikinas failas rezultatui
    std::string tempFile = "temp_ping_results.txt";
    
    // Vykdomas ping komanda su rezultato issaugojimu i faila
    std::string command = "ping " + ipAddress + " > " + tempFile;
    system(command.c_str());
    
    // Atidaro faila ir parodo naudotojui
    command = "notepad " + tempFile;
    system(command.c_str());
    
    // Istriname laikina faila
    std::string deleteCmd = "del " + tempFile;
    system(deleteCmd.c_str());
}

// Apriboti naudotojo laika prie kompiuterio (Stud_ID % 3 + 1 = 1)
void limitUserTime(const std::string& username, const std::string& weekday, const std::string& timeRange) {
    std::string command = "net user " + username + " /time:" + weekday + "," + timeRange;
    system(command.c_str());
}

// Atidaryti valdymo skydeli (Stud_ID % 3 + 1 = 3)
void openControlPanel(const std::string& component) {
    std::string command;
    
    if (component == "Display") {
        command = "start ms-settings:display";
    }
    else if (component == "Security") {
        command = "start ms-settings:windowsdefender";
    }
    else if (component == "Power") {
        command = "start ms-settings:powersleep";
    }
    else if (component == "Storage") {
        command = "start ms-settings:storagesense";
    }
    else if (component == "Update") {
        command = "start ms-settings:windowsupdate";
    }
    
    system(command.c_str());
}

// Sukurti direktoriju struktura pagal varda ir pavarde
void createDirectories(const std::string& firstName, const std::string& lastName) {
    // Sukuriamas pagrindinis aplankalas su pavarde
    std::string mainDir = lastName;
    std::string command = "mkdir " + mainDir;
    system(command.c_str());
    
    // Sukuriami trys "Vardenis" aplankalai
    for (int i = 1; i <= 3; i++) {
        std::string subDir = mainDir + "\\" + firstName + std::to_string(i);
        command = "mkdir " + subDir;
        system(command.c_str());
        
        // Sukuriami trys sub-aplankalai kiekviename "Vardenis" aplankalе
        for (int j = 1; j <= 3; j++) {
            std::string subSubDir = subDir + "\\" + firstName + std::to_string(i) + firstName + std::to_string(j);
            command = "mkdir " + subSubDir;
            system(command.c_str());
            
            // Sukuriamas tuscias .txt failas kiekviename galutiniame aplankalе
            std::string filePath = subSubDir + "\\data.txt";
            std::ofstream file(filePath);
            file.close();
        }
    }
}

// Apskaiciuoti Tschirnhausen kubines kreives reiksmes
void calculateCubic(int F, int x0, int xn, double dx) {
    // Aplankalai ir failai kuriems busime irasyti duomenis
    std::vector<std::string> allFiles;
    
    // Surenkame visus failus is sukurtu aplankalų
    std::string basePath = "Stankevicius";
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            std::string filePath = basePath + "\\Nojus" + std::to_string(i) + "\\Nojus" + 
                                  std::to_string(i) + "Nojus" + std::to_string(j) + "\\data.txt";
            allFiles.push_back(filePath);
        }
    }
    
    // Jei nera failu, nutraukiame
    if (allFiles.empty()) {
        return;
    }
    
    // Failo indeksas duomenu irasymui
    int fileIndex = 0;
    int totalFiles = allFiles.size();
    
    // Apskaiciuojame tasku poras ir irasome i failus
    for (double x = x0; x <= xn; x += dx) {
        // Tšrinhauseno kilpa (angl. Tschirnhausen cubic) F = x3+3x2-y2
        // Isspredziame lygtį F = x³+3x²-y² pagal y
        double underRoot = F - x*x*x - 3*x*x;
        
        // Tikriname ar funkcija egzistuoja siame taske (ar po saknimi teigiamas skaicius)
        if (underRoot >= 0) {
            double y1 = sqrt(underRoot);
            double y2 = -y1;  // Del simetrijos gauname dvi y reiksmes
            
            // Irasome pirma taska
            std::ofstream file1(allFiles[fileIndex], std::ios_base::app);
            file1 << x << " " << y1 << std::endl;
            file1.close();
            
            // Pereiname prie kito failo
            fileIndex = (fileIndex + 1) % totalFiles;
            
            // Irasome antra taska (jei jis skiriasi)
            if (y1 != y2) {
                std::ofstream file2(allFiles[fileIndex], std::ios_base::app);
                file2 << x << " " << y2 << std::endl;
                file2.close();
                
                // Pereiname prie kito failo
                fileIndex = (fileIndex + 1) % totalFiles;
            }
        }
    }
}

// Sujungti visus failus su konkrechiu F parametru
void mergeFiles(int F) {
    // Visų duomenų saugojimui
    std::vector<std::pair<double, double>> allPoints;
    
    // Surenkame failus
    std::vector<std::string> allFiles;
    std::string basePath = "Stankevicius";
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            std::string filePath = basePath + "\\Nojus" + std::to_string(i) + "\\Nojus" + 
                                  std::to_string(i) + "Nojus" + std::to_string(j) + "\\data.txt";
            allFiles.push_back(filePath);
        }
    }
    
    // Nuskaitome visus taškus iš visų failų
    for (const auto& filePath : allFiles) {
        std::ifstream file(filePath);
        double x, y;
        while (file >> x >> y) {
            allPoints.push_back({x, y});
        }
        file.close();
    }
    
    // Surūšiuojame taškus pagal x
    std::sort(allPoints.begin(), allPoints.end(), 
              [](const std::pair<double, double>& a, const std::pair<double, double>& b) {
                  return a.first < b.first;
              });
    
    // Įrašome surūšiuotus taškus į naują failą
    std::string mergedFilePath = "result_F" + std::to_string(F) + ".txt";
    std::ofstream mergedFile(mergedFilePath);
    for (const auto& point : allPoints) {
        mergedFile << point.first << " " << point.second << std::endl;
    }
    mergedFile.close();
    
    // Išvalome pradinius failus
    for (const auto& filePath : allFiles) {
        std::ofstream file(filePath, std::ofstream::trunc);
        file.close();
    }
}

// Ištrinti sukurtas direktorijas
void removeDirectories() {
    std::string command = "rmdir /S /Q Stankevicius";
    system(command.c_str());
}