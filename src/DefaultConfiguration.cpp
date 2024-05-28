#include "../headers/DefaultConfiguration.h"

DefaultConfiguration::~DefaultConfiguration() {
    std::cout << "Destructor DefaultConfiguration\n";
}

void DefaultConfiguration::loadSettings() {
    difficulty = "NORMAL";
    timeLimit = 10;
    startingLives = 3;
    numOfPlayers = 8;
}