#ifndef OOP_HUMANPLAYER_H
#define OOP_HUMANPLAYER_H

#include <iostream>
#include <string>
#include "Player.h"
#include "Statistics.h"


class HumanPlayer : public Player {
public:
    HumanPlayer() = default;

    HumanPlayer &operator=(const HumanPlayer &);

    friend std::ostream &operator<<(std::ostream &, const HumanPlayer &);

    ~HumanPlayer() override;

    void guessWord(Dictionary<std::string> &, Word &) override;

    [[nodiscard]] Player *clone() const override;
};


#endif //OOP_HUMANPLAYER_H