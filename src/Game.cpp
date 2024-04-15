#include "../headers/Game.h"


Game::Game(std::vector<Player *> &players, const Configuration &config, const Dictionary &dict) : config{config},
                                                                                                  dict{dict} {
    for (const auto &player: players)
        this->players.emplace_back(player->clone());
    std::cout << "Initialization constructor Game\n";
}

Game::Game(const Game &other) : config(other.config), dict(other.dict) {
    for (const auto &player: other.players)
        players.emplace_back(player->clone());
    std::cout << "Copy constructor Game\n";
}

Game &Game::operator=(Game other) {
    swap(*this, other);
    std::cout << "Assignment operator Game\n";
    return *this;
}

void swap(Game &gameObject1, Game &gameObject2) {
    using std::swap;
    swap(gameObject1.players, gameObject2.players);
    swap(gameObject1.config, gameObject2.config);
    swap(gameObject1.dict, gameObject2.dict);
    std::cout << "Custom swap Game\n";
}

std::ostream &operator<<(std::ostream &os, const Game &gameObject) {
    for (const auto player: gameObject.players)
        os << player;
    os << gameObject.config << gameObject.dict;
    return os;
}

Game::~Game() {
    for (auto &player: players)
        delete player;
    std::cout << "Destructor Game\n";
}

void Game::playerInput() {
    Word word("example");
    for (const auto player: players)
        player->guessWord(dict, word);
}