#include "pch.h"
#include "dll.h"

int main()
{
    // Pradedam laiko matavima
    auto startTime = measureTime();
    int studNumber = 2314009;  
    
    // Paleidziam ping testa ir fiksuojam rezultatus
    runPingTest("8.8.8.8");  
    
    // Sukuriam direktoriju struktura
    createDirectories("Nojus", "Stankevicius");
    
    // Rodome zinute apie skaiciavima
    std::string cmd = "echo Calculating Tschirnhausen cubic curve...";
    system(cmd.c_str());
    
    // Skaiciuojam kubine kreive su skirtingomis F reiksmemis
    for (int funcParam = -2; funcParam <= 2; funcParam++) 
    {
        calculateCubic(funcParam, 
                      -(studNumber % 19), 
                      studNumber % 25, 
                      static_cast<double>(studNumber) / 1000000000000);
        mergeFiles(funcParam);
    }
    
    // Isvalom sukurtas direktorijas
    removeDirectories();
    
    // Apskaiciuojam ir parodom vykdymo laika
    auto endTime = measureTime();
    auto timeElapsed = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    std::cout << "\nExecution time: " << timeElapsed.count() << " ms\n" << std::endl;
    system("pause");
    
    return 0;
}