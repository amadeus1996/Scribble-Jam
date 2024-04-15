#ifndef OOP_HUMANPLAYER_H
#define OOP_HUMANPLAYER_H

#include <iostream>
#include <string>
#include "Player.h"
#include "Statistics.h"


class HumanPlayer : public Player {
private:
    std::string name;
public:
    explicit HumanPlayer(std::string name = "noname");

    HumanPlayer &operator=(const HumanPlayer &other);

    friend std::ostream &operator<<(std::ostream &os, const HumanPlayer &player);

    ~HumanPlayer() override;

    void guessWord(Dictionary &dictObject, Word &wordObject) override;

    [[nodiscard]] Player *clone() const override;
};


#endif //OOP_HUMANPLAYER_H