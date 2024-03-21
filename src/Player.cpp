#include "../headers/Player.h"
#include <iostream>

Player::Player(const int lives, const int score) : lives(lives), score(score) {
    std::cout<<"Constructor initializare Player\n";
}
Player::Player(const Player &other) : lives{other.lives}, score{other.score} {
    std::cout<<"Constructor copiere Player\n";
}
Player& Player::operator=(const Player &other) {
    this->lives = other.lives;
    this->score = other.score;
    std::cout<<"operator= copiere Player\n";
    return *this;
}
std::ostream &operator<<(std::ostream &os, const Player &player) {
    os<<"Score: "<<player.score<<"\nLives: "<<player.lives<<"\n";
    return os;
}
Player::~Player() { std::cout<<"Destructor Player\n"; }