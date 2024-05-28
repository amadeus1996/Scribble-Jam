#ifndef OOP_COMPUTERPLAYER_H
#define OOP_COMPUTERPLAYER_H

#include <iostream>
#include "Player.h"
#include "Statistics.h"


class ComputerPlayer : public Player {
public:
    ComputerPlayer();

    ComputerPlayer &operator=(const ComputerPlayer &);

    friend std::ostream &operator<<(std::ostream &, ComputerPlayer &);

    ~ComputerPlayer() override;

    [[nodiscard]] Player *clone() const override;

    void guessWord(Dictionary<std::string> &, Word &) override;
};


#endif //OOP_COMPUTERPLAYER_H