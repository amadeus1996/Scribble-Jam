#ifndef OOP_GAME_H
#define OOP_GAME_H

#include "Player.h"
#include "ConfigurationFactory.h"
#include "Dictionary.h"


class Game {
private:
    static Game *instance;
    std::vector<Player *> players;
    Configuration *config;
    Dictionary<std::string> dict;
    int playersAlive;

    Game(std::vector<Player *> &, const Dictionary<std::string> &);

public:
    Game(const Game &) = delete;

    Game &operator=(const Game &) = delete;

    ~Game();

    static Game *getInstance(std::vector<Player *> &, Dictionary<std::string> &);

    friend std::ostream &operator<<(std::ostream &, const Game &);

    friend void swap(Game &, Game &);

    void run();
};


#endif //OOP_GAME_H