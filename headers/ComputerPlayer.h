#ifndef OOP_COMPUTERPLAYER_H
#define OOP_COMPUTERPLAYER_H

#include <iostream>
#include "Player.h"
#include "Statistics.h"


class ComputerPlayer : public Player {
public:
    ComputerPlayer();

    ComputerPlayer &operator=(const ComputerPlayer &other);

    friend std::ostream &operator<<(std::ostream &os, ComputerPlayer &computerPlayer);

    ~ComputerPlayer() override;

    [[nodiscard]] Player *clone() const override;

    void guessWord(Dictionary &dictObject, Word &wordObject) override;
};


#endif //OOP_COMPUTERPLAYER_H