#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

#include <iostream>
#include "Dictionary.h"
#include "Word.h"
#include "Statistics.h"


class HumanPlayerBuilder;


class Player {
protected:
    Statistics stats;
    int lives{};
    std::string name;

    Player(const Player &);

    Player &operator=(const Player &);

public:
    /**
     * @brief This is the @ref Player class to keep track of the player's progress.
     * @param lives
     */
//    explicit Player(int);
    Player() = default;

    friend std::ostream &operator<<(std::ostream &, const Player &);

    virtual ~Player();

    virtual void guessWord(Dictionary<std::string> &, Word &) = 0;

    void updatePlayerStats();

    [[nodiscard]] virtual Player *clone() const = 0;

    std::string getName();

    [[nodiscard]] bool isEliminated() const;

    friend class HumanPlayerBuilder;
};


#endif //OOP_PLAYER_H