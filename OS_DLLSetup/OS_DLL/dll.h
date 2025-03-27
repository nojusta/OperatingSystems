#pragma once

#include <string>
#include <iostream>
#include <chrono>

/**
 * Matuoja laika
 * 
 * @return Grazina dabartini laiko taska
 */
std::chrono::high_resolution_clock::time_point measureTime();

/**
 * Vykdo ping testa nurodytu adresu
 * 
 * @param ipAddress IP adresas ping testui
 */
void runPingTest(const std::string& ipAddress);

/**
 * Sukuria direktoriju struktura
 * 
 * @param firstName Vartotojo vardas
 * @param lastName Vartotojo pavarde
 */
void createDirectories(const std::string& firstName, const std::string& lastName);

/**
 * Skaiciuoja Tschirnhausen kubines kreives reiksmes
 * 
 * @param funcParam Funkcijos parametras
 * @param param1 Pirmas kreives parametras
 * @param param2 Antras kreives parametras
 * @param param3 Trecias kreives parametras
 */
void calculateCubic(int funcParam, int param1, int param2, double param3);

/**
 * Sujungia failus
 * 
 * @param paramValue Parametras nurodantis, kuriuos failus sujungti
 */
void mergeFiles(int paramValue);

/**
 * Istrina sukurtas direktorijas
 */
void removeDirectories();

/**
 * Pagrindine programos funkcija
 * 
 * @return Programos vykdymo statusas
 */
int main();