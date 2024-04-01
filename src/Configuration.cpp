#include "../headers/Configuration.h"
#include <iostream>
#include <utility>
#include <fstream>

Configuration::Configuration(std::string defaultDifficulty, const int defaultTimeLimit, const int defaultStartingLives)
        : difficulty{std::move(defaultDifficulty)}, timeLimit{defaultTimeLimit}, startingLives{defaultStartingLives} {
    std::cout << "Initialization constructor Configuration\n";
}

Configuration::Configuration(const Configuration &other) : difficulty{other.difficulty}, timeLimit{other.timeLimit},
                                                           startingLives{other.startingLives} {
    std::cout << "Copy constructor Configuration\n";
}

Configuration &Configuration::operator=(const Configuration &other) {
    this->difficulty = other.difficulty;
    this->timeLimit = other.timeLimit;
    this->startingLives = other.startingLives;
    std::cout << "Assignment operator Configuration\n";
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Configuration &config) {
    os << "Difficulty: " << config.difficulty << "\nTime limit: " << config.timeLimit << "\n" << "Lives: "
       << config.startingLives << "\n";
    return os;
}

Configuration::~Configuration() { std::cout << "Destructor Configuration\n"; }

/**
 * @details
 * The player inputs a difficulty; if it doesn't match any of the game's default difficulties, it will be considered
 * "CUSTOM", and the player will be able to edit both the amount of starting lives and time limit. If the file cannot
 * be opened, the program will throw an error.
 */
void Configuration::inputSettings() {
    std::string inputDifficulty;
    std::ifstream f(R"(D:\cursuri\Semestrul 2\OOP\Lab\Scribble-Jam\tastatura.txt)");
    if (f.is_open()) {
        f >> inputDifficulty;
        std::transform(inputDifficulty.begin(), inputDifficulty.end(), inputDifficulty.begin(),
                       ::toupper);
        if (inputDifficulty == "EASY") {
            this->difficulty = inputDifficulty, this->timeLimit = 15, this->startingLives = 5;
        } else if (inputDifficulty == "NORMAL") {
            this->difficulty = inputDifficulty, this->timeLimit = 10, this->startingLives = 3;
        } else if (inputDifficulty == "HARD") {
            this->difficulty = inputDifficulty, this->timeLimit = 5, this->startingLives = 2;
        } else {
            this->difficulty = "CUSTOM";
            int inputTimeLimit, inputStartingLives;
            f >> inputTimeLimit >> inputStartingLives;
            this->timeLimit = inputTimeLimit;
            this->startingLives = inputStartingLives;
        }
    } else
        std::perror("file not found");
}