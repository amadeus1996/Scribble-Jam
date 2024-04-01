#include "../headers/Player.h"
#include <iostream>

Player::Player(const int lives, const int score) : lives(lives), score(score) {
    std::cout << "Initialization constructor Player\n";
}

Player::Player(const Player &other) : lives{other.lives}, score{other.score} {
    std::cout << "Copy constructor Player\n";
}

Player &Player::operator=(const Player &other) {
    this->lives = other.lives;
    this->score = other.score;
    std::cout << "Assignment operator Player\n";
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Player &player) {
    os << "Lives: " << player.lives << "\nScore: " << player.score << "\n";
    return os;
}

Player::~Player() { std::cout << "Destructor Player\n"; }