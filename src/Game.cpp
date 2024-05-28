#include "../headers/Game.h"
#include "../headers/HumanPlayer.h"
#include "../headers/DefaultConfiguration.h"
#include "../headers/CustomConfiguration.h"
#include "../headers/HumanPlayerBuilder.h"


//void Game::setConfig(std::unique_ptr<ConfigurationFactory> configFactory) {
//    config = configFactory->createConfig();
//}

Game *Game::instance = nullptr;

Game::Game(std::vector<Player *> &players, const Dictionary<std::string> &dict) : dict{dict} {
    try {
        std::cout << "Select the game's settings (DEFAULT/CUSTOM): ";
        std::string inputDifficulty;
        std::cin >> inputDifficulty;
        if (inputDifficulty == "DEFAULT") {
            ConfigurationFactory<DefaultConfiguration> defaultFactory;
            config = defaultFactory.createConfig();
            config->loadSettings();
        } else if (inputDifficulty == "CUSTOM") {
            ConfigurationFactory<CustomConfiguration> customFactory;
            config = customFactory.createConfig();
            config->loadSettings();
            std::cout<<config;
        } else throw std::invalid_argument("INVALID INPUT");
    }
    catch (const std::exception &err) {
        std::cerr << "ERROR: " << err.what() << "\n";
        return;
    }

    HumanPlayerBuilder builder;
    for (const auto &player: players) {

        this->players.push_back(player->clone());
    }


    playersAlive = static_cast<int>(players.size());

    std::cout << "Initialization constructor Game\n";
}

//Game::Game(const Game &other) : config(other.config), dict(other.dict) {
//    for (const auto &player: other.players)
//        players.emplace_back(player->clone());
//    std::cout << "Copy constructor Game\n";
//}
//
//Game &Game::operator=(Game other) {
//    swap(*this, other);
//    std::cout << "Assignment operator Game\n";
//    return *this;
//}

Game *Game::getInstance(std::vector<Player *> &playerVector, Dictionary<std::string> &dictObject) {
    if (!instance) instance = new Game(playerVector, dictObject);
    return instance;
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
        os << "\n" << *dynamic_cast<HumanPlayer *>(player) << "\n";
    os << gameObject.config << "\n" << gameObject.dict << "\n";
    return os;
}

Game::~Game() {
    for (auto &player: players)
        delete player;
    std::cout << "Destructor Game\n";
}

void Game::run() {
    bool ok = true;
    while (ok) {
        Word wordObj = Word(Dictionary<std::string>::getRandomHint());
        operator<<(std::cout, wordObj) << "\n";
        for (const auto &player: players) {
            std::cout << player->getName() << "'s turn: ";
            player->guessWord(dict, wordObj);
            if (player->isEliminated()) {
                --playersAlive;
                if (playersAlive == 1) {
                    ok = false;
                    break;
                }
            }
        }
    }
    unsigned int count = 0;
    unsigned int winnerIndex;
    for (const auto &player: players) {
        player->updatePlayerStats();
        std::cout<<*dynamic_cast<HumanPlayer*>(player)<<"\n";
        if (!player->isEliminated()) {
            winnerIndex = count;
            break;
        }
        ++count;
    }
    std::cout<<"WINNER: "<<players[winnerIndex]->getName()<<"\n";
}
