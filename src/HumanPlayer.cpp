#include <utility>
#include <fstream>
#include <algorithm>
#include "../headers/HumanPlayer.h"
#include "../headers/Configuration.h"


HumanPlayer::HumanPlayer(std::string name) : Player{3}, name{std::move(name)} {
    std::cout << "Initialization constructor HumanPlayer\n";
}

HumanPlayer &HumanPlayer::operator=(const HumanPlayer &other) {
    this->lives = other.lives;
    this->name = other.name;
    this->stats = other.stats;
    std::cout << "Assignment operator HumanPlayer\n";
    return *this;
}

std::ostream &operator<<(std::ostream &os, const HumanPlayer &player) {
    os << "Name: " << player.name << "\nLives: " << player.lives << "\nSTATS\n" << player.stats;
    return os;
}

HumanPlayer::~HumanPlayer() {
    std::cout << "Destructor HumanPlayer\n";
}

void HumanPlayer::guessWord(Dictionary &dictObject, Word &wordObject) {
    bool ok = false;
    std::string inputWord;
    std::cin >> inputWord;
    std::transform(inputWord.begin(), inputWord.end(), inputWord.begin(), ::tolower);
    if (wordObject.wordAttempt(inputWord, dictObject)) {
        ok = true;
        std::cout << "Correct\n";
    } else std::cout << "Incorrect\n";
    stats.updateStats(ok);
}

Player *HumanPlayer::clone() const {
    std::cout << "Clone HumanPlayer\n";
    return new HumanPlayer(*this);
}