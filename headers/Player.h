#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

#include <iostream>
#include "Dictionary.h"
#include "Word.h"
#include "Statistics.h"


class Player {
protected:
    Statistics stats;
    int lives{};

    Player(const Player &other);

    Player &operator=(const Player &other);

public:
    /**
     * @brief This is the @ref Player class to keep track of the player's progress.
     * @param lives
     */
    explicit Player(int lives);

    friend std::ostream &operator<<(std::ostream &os, const Player &player);

    virtual ~Player();

    virtual void guessWord(Dictionary &dictObject, Word &wordObject) = 0;

    void updatePlayerStats();

    [[nodiscard]] virtual Player *clone() const = 0;
};


#endif //OOP_PLAYER_H