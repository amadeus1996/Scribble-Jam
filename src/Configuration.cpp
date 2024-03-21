#include "../headers/Configuration.h"
#include <iostream>
#include <utility>
#include <fstream>

Configuration::Configuration(std::string default_difficulty, const int time_limit, const int starting_lives) : difficulty{std::move(default_difficulty)}, time_limit{time_limit}, starting_lives{starting_lives} {
    std::cout<<"Constructor initializare Configuration\n";
}
Configuration::Configuration(const Configuration &other) : difficulty{other.difficulty}, time_limit{other.time_limit}, starting_lives{other.starting_lives} {
    std::cout<<"Constructor copiere Configuration\n";
}
Configuration& Configuration::operator=(const Configuration &other) {
    this->difficulty = other.difficulty;
    this->time_limit = other.time_limit;
    this->starting_lives = other.starting_lives;
    std::cout<<"operator= copiere Configuration\n";
    return *this;
}
std::ostream &operator<<(std::ostream &os, const Configuration &config) {
    os<<"Difficulty: "<<config.difficulty<<"\nTime limit: "<<config.time_limit<<"\n"<<"Lives: "<<config.starting_lives<<"\n";
    return os;
}
Configuration::~Configuration() { std::cout<<"Destructor Configuration\n"; }

void Configuration::loadSettings() {
    std::string user_difficulty;
    std::ifstream f(R"(D:\cursuri\Semestrul 2\OOP\Lab\Scribble-Jam\tastatura.txt)");
    if (f.is_open()) {
        f>>user_difficulty;
        std::transform(user_difficulty.begin(), user_difficulty.end(), user_difficulty.begin(), ::toupper);
        if (user_difficulty == "EASY") {
            this->difficulty = user_difficulty, this->time_limit = 15, this->starting_lives = 5;
        }
        else if (user_difficulty == "NORMAL") {
            this->difficulty = user_difficulty, this->time_limit = 10, this->starting_lives = 3;
        }
        else if (user_difficulty == "HARD") {
            this->difficulty = user_difficulty, this->time_limit = 5, this->starting_lives = 2;
        }
        else {
            this->difficulty = "CUSTOM";
            int user_time_limit, user_starting_lives;
            f>>user_time_limit>>user_starting_lives;
            this->time_limit = user_time_limit;
            this->starting_lives = user_starting_lives;
        }
    }
    else
        std::perror("file not found");
}