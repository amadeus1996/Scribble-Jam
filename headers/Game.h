#ifndef OOP_GAME_H
#define OOP_GAME_H

#include "../headers/Player.h"
#include "../headers/Configuration.h"
#include "../headers/Dictionary.h"


class Game {
private:
    std::vector<Player *> players;
    Configuration config;
    Dictionary dict;
public:
    Game(std::vector<Player *> &players, const Configuration &config, const Dictionary &dict);

    Game(const Game &other);

    Game &operator=(Game other);

    friend std::ostream &operator<<(std::ostream &os, const Game &gameObject);

    friend void swap(Game &gameObject1, Game &gameObject2);

    ~Game();

    void playerInput();
};


#endif //OOP_GAME_H