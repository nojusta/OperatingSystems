#pragma once

#include <string>

#ifdef _WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif

extern "C" {
    DLL_EXPORT long long measureTime();
    DLL_EXPORT void runPingTest(const std::string& ipAddress);
    DLL_EXPORT void createDirectories(const std::string& firstName, const std::string& lastName);
    DLL_EXPORT void calculateCubic(int funcParam, int param1, int param2, double param3);
    DLL_EXPORT void mergeFiles(int paramValue);
    DLL_EXPORT void removeDirectories();
}
