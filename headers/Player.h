#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H
#include <iostream>

class Player {
private:
    int lives;
    int score;
public:
    Player(int lives, int score);
    Player(const Player &other);
    Player &operator=(const Player &other);
    friend std::ostream &operator<<(std::ostream &os, const Player &player);
    ~Player();
};

#endif //OOP_PLAYER_H
