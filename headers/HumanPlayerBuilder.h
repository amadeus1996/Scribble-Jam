#ifndef OOP_HUMANPLAYERBUILDER_H
#define OOP_HUMANPLAYERBUILDER_H

#include "Player.h"
#include "HumanPlayer.h"


class HumanPlayerBuilder {
    std::string builderName;
    int builderLives{};
public:
    HumanPlayerBuilder() = default;

    void setLives(int);

    void setName(std::string);

    Player *build();
};


#endif //OOP_HUMANPLAYERBUILDER_H
