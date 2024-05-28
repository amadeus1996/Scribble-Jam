#include "../headers/Configuration.h"
#include <iostream>
#include <utility>
#include <fstream>


Configuration::~Configuration() {
    std::cout << "Destructor Configuration\n";
}

//Configuration::Configuration(const Configuration &other) : difficulty{other.difficulty}, timeLimit{other.timeLimit},
//                                                           startingLives{other.startingLives} {
//    std::cout << "Copy constructor Configuration\n";
//}

//Configuration &Configuration::operator=(const Configuration &other) {
//    this->difficulty = other.difficulty;
//    this->timeLimit = other.timeLimit;
//    this->startingLives = other.startingLives;
//    std::cout << "Assignment operator Configuration\n";
//    return *this;
//}

std::ostream &operator<<(std::ostream &os, const Configuration *config) {
    os << "Difficulty: " << config->difficulty << "\n";
    os << "Time limit: " << config->timeLimit << "\n";
    os << "Lives: " << config->startingLives << "\n";
    os << "Maximum number of players: " << config->numOfPlayers << "\n";
    return os;
}