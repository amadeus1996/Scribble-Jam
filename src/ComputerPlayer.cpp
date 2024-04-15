#include "../headers/ComputerPlayer.h"


ComputerPlayer::ComputerPlayer() : Player{3} {
    std::cout << "Initialization constructor ComputerPlayer\n";
}

ComputerPlayer &ComputerPlayer::operator=(const ComputerPlayer &other) {
    this->lives = other.lives;
    this->stats = other.stats;
    std::cout << "Assignment operator ComputerPlayer\n";
    return *this;
}

std::ostream &operator<<(std::ostream &os, ComputerPlayer &computerPlayer) {
    os << "Lives: " << computerPlayer.lives << "\nSTATS\n" << computerPlayer.stats << "\n";
    return os;
}

ComputerPlayer::~ComputerPlayer() {
    std::cout << "Destructor ComputerPlayer\n";
}

Player *ComputerPlayer::clone() const {
    std::cout << "Clone ComputerPlayer\n";
    return new ComputerPlayer(*this);
}

void ComputerPlayer::guessWord(Dictionary &dictObject, Word &wordObject) {
    std::cout << "ComputerPlayer guessWord\n";
}