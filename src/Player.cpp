#include "../headers/Player.h"
#include <iostream>


//Player::Player(const int lives) : lives{lives} {
//    std::cout << "Initialization constructor Player\n";
//}

Player::Player(const Player &other) : stats{other.stats}, lives{other.lives}, name(other.name) {
    std::cout << "Copy constructor Player\n";
}

Player &Player::operator=(const Player &other) {
    this->name = other.name;
    this->lives = other.lives;
    this->stats = other.stats;
    std::cout << "Assignment operator Player\n";
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Player &player) {
    os << "Name: " << player.name << "\n";
    os << "Lives: " << player.lives << "\n";
    os << "Stats: " << player.stats << "\n";
    return os;
}

void Player::updatePlayerStats() {
    Statistics::updateOverallStats(stats);
}

std::string Player::getName() {
    return this->name;
}

bool Player::isEliminated() const {
    if (!lives) return true;
    return false;
}

Player::~Player() {
    std::cout << "Destructor Player\n";
}
