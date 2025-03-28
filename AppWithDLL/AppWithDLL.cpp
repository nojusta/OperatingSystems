#include "../Dll/dll.h"
#include <iostream>

int main() {
    std::cout << "Pradedama programa..." << std::endl;
    long long startTime = measureTime();
    int studNumber = 2314099;
    //std::cout << studNumber % 3 + 1 << std::endl;

    std::cout << "Kuriama katalogu struktura..." << std::endl;
    createDirectories("Nojus", "Stankevicius");

    // Stud_ID % 3 + 1 = 2314099 % 3 + 1 = 2 (Ping testas)
    runPingTest("8.8.8.8");

    std::string command = "echo Skaiciuojama Tschirnhausen kubine kreive...";
    system(command.c_str());

    double stepSize = 0.1;

    for (int funcParam = -2; funcParam <= 2; funcParam++) {
        std::cout << "\nSkaiciuojama kreive su F=" << funcParam << std::endl;
        calculateCubic(funcParam,
            -(studNumber % 19), 
            studNumber % 25,    
            stepSize);
        std::cout << "Sujungiami failai su F=" << funcParam << std::endl;
        mergeFiles(funcParam);
    }

    std::cout << "Valomi katalogai..." << std::endl;
    removeDirectories();

    long long endTime = measureTime();

    std::cout << "\nProgramos vykdymo laikas: " << (endTime - startTime) << " ms\n" << std::endl;
    system("pause");
    return 0;
}