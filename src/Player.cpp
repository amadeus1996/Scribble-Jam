#include "../headers/Player.h"
#include <iostream>


Player::Player(const int lives) : lives{lives} {
    std::cout << "Initialization constructor Player\n";
}

Player::Player(const Player &other) : lives{other.lives} {
    std::cout << "Copy constructor Player\n";
}

Player &Player::operator=(const Player &other) {
    this->lives = other.lives;
    std::cout << "Assignment operator Player\n";
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Player &player) {
    os << "Lives: " << player.lives << "\n";
    return os;
}

void Player::updatePlayerStats() {
    Statistics::updateOverallStats(stats);
}

Player::~Player() {
    std::cout << "Destructor Player\n";
}
