#include <utility>

#include "../headers/HumanPlayerBuilder.h"


void HumanPlayerBuilder::setLives(int playerLives) {
    builderLives = playerLives;
}

void HumanPlayerBuilder::setName(std::string playerName) {
    builderName = std::move(playerName);
}

Player *HumanPlayerBuilder::build() {
    Player *p = new HumanPlayer;
    p->lives = builderLives;
    p->name = builderName;
    return p;
}