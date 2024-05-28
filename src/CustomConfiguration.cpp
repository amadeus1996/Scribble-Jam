#include "../headers/CustomConfiguration.h"
#include <fstream>

CustomConfiguration::~CustomConfiguration() {
    std::cout << "Destructor CustomConfiguration\n";
}

void CustomConfiguration::loadSettings() {
    std::string inputDifficulty;
    std::ifstream f(R"(D:\cursuri\Semestrul 2\OOP\Lab\Scribble-Jam\tastatura.txt)");
    this->difficulty = "CUSTOM";

    int inputTimeLimit, inputStartingLives, inputNumOfPlayers;
    f >> inputTimeLimit >> inputStartingLives >> inputNumOfPlayers;

    this->timeLimit = inputTimeLimit;
    this->startingLives = inputStartingLives;
    this->numOfPlayers = inputNumOfPlayers;
}