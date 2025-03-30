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

    // Nustatome zingsni pagal uzduoti
    double stepSize = studNumber / 1000000000000.0;
    // Apribojame minimalu zingsni, kad programa veiktu efektyviai
    if (stepSize < 0.001) stepSize = 0.001;

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
    std::cout << "Spauskite Enter, kad iseiti...";
    std::cin.get();
    return 0;
}