#include "headers/Dictionary.h"
#include "headers/Word.h"
#include "headers/Player.h"
#include "headers/Configuration.h"
#include "headers/HumanPlayer.h"
#include "headers/ComputerPlayer.h"
#include "headers/Game.h"
#include "headers/HumanPlayerBuilder.h"
#include "headers/DefaultConfiguration.h"
#include "headers/CustomConfiguration.h"
#include <iostream>
#include <random>
#include <typeinfo>

int main() {
//    Dictionary dict1({}, {}), dict2({"pressured", "vanilla", "interrogation"}, {});
//    dict1.addWords({"red"});
//    dict1.loadDictionaryFromFile(R"(D:\cursuri\Semestrul 2\OOP\Lab\Scribble-Jam\dict_test.txt)");
//    dict1.addWords({"surprisingly", "forecast", "weathered"});
//    operator<<(std::cout, dict1);
//    dict1 = dict2;
//    operator<<(std::cout, dict1);
//    dict2.emptyDictionary();
//    operator<<(std::cout, dict2);
//    std::cout << "\n";
//
//    Dictionary dict({}, {});
//    dict.loadDictionaryFromFile(R"(D:\cursuri\Semestrul 2\OOP\Lab\Scribble-Jam\dict_test.txt)");
//    operator<<(std::cout, dict);
//    Word word1("ou"), word2("iti"), word3("ess"), word4("it"), word5("pen");
//    std::cout << word1.wordAttempt("house", dict) << "\n";
//    std::cout << word1.wordAttempt("house", dict) << "\n";
//    std::cout << word2.wordAttempt("block", dict) << "\n";
//    std::cout << word2.wordAttempt("overwriting", dict) << "\n";
//    std::cout << word3.wordAttempt("quintessence", dict) << "\n";
//    std::cout << word4.wordAttempt("overwriting", dict) << "\n";
//    std::cout << word4.wordAttempt("white", dict) << "\n";
//    std::cout << word5.wordAttempt("suspend", dict) << "\n";
//    operator<<(std::cout, dict);
//    dict.emptyDictionary();
//    operator<<(std::cout, dict);
//    operator<<(std::cout, word2);
//    word2 = word1;
//    operator<<(std::cout, word2);
//    std::cout << "\n";
//
//    Player player1(3, 5), player2(1, 4);
//    operator<<(operator<<(std::cout, player1), player2);
//    player1 = player2;
//    operator<<(std::cout, player1);
//    std::cout << "\n";
//
//    Configuration config1, config2;
//    operator<<(std::cout, config1);
//    config1.inputSettings();
//    operator<<(std::cout, config1);
//    config2 = config1;
//    operator<<(std::cout, config2);
//    std::cout << "\n";

//    Statistics s1;
//    HumanPlayer p1("Mihail", s1, 3, 0);
//    Dictionary d1({}, {});
//    d1.loadDictionaryFromFile(R"(D:\cursuri\Semestrul 2\OOP\Lab\Scribble-Jam\dict_test.txt)");
//    Word w1("ou");
//
//    p1.guessWord(d1, w1);

//    Statistics s;
//    Dictionary d({}, {});
//    Word w("a");
//
//    Player* test1 = new HumanPlayer("Traiciu", s, 3, 0);
//    Player* test2 = test1->clone();
//    test1->guessWord(d, w);
//    test2->guessWord(d, w);
//
//    Player* test3 = new ComputerPlayer(3, 0);
//    test3->guessWord(d, w);
//    Player* test4 = test3->clone();
//    test4->guessWord(d, w);
//    test3->guessWord(d, w);
//
//    delete test1;
//    delete test2;
//    delete test3;
//    delete test4;

//    Statistics s;
//    std::vector<Player*> players1;
//    Player *human1 = new HumanPlayer("Traiciu", s, 3);
//    Player *computer = new ComputerPlayer(3, s);
//    players1.push_back(human1);
//    players1.push_back(computer);
//    std::cout<<"\n";
//
//    std::vector<Player*> players2;
//    Player *human2 = new HumanPlayer("Miloi", s, 3);
//    Player *human3 = new HumanPlayer("Iordache", s, 3);
//    players2.push_back(human2);
//    players2.push_back(human3);
//    std::cout<<"\n";
//
//    Configuration config1, config2;
//    config2.inputSettings();
//
//    Dictionary dict1, dict2;
//    dict1.addWords({"water", "overpopulated"});
//    dict2.loadDictionaryFromFile(R"(D:\cursuri\Semestrul 2\OOP\Lab\Scribble-Jam\dict_test.txt)");
//
//    Game game1(players1, config1, dict1);
//    Game game2(players2, config2, dict2);
//
//    operator<<(std::cout, game1);
//
//    delete human3;
//    delete human2;
//    delete computer;
//    delete human1;

//    std::cout << d.getLength() << "\n";
//    d.addWords({"test"});
//    std::cout << d.getLength() << "\n";
//    d.emptyDictionary();
//    std::cout << d.getLength() << "\n";
//    d.loadDictionaryFromFile(R"(D:\cursuri\Semestrul 2\OOP\Lab\Scribble-Jam\dict_test.txt)");
//    std::cout << d.getLength() << "\n";

//    Dictionary d;
//    d.loadDictionaryFromFile(R"(D:\cursuri\Semestrul 2\OOP\Lab\Scribble-Jam\dict_test.txt)");
//    operator<<(std::cout, d);
//    std::cout << "\n";

//    Player *p = new HumanPlayer("Player");
//    std::cout << *dynamic_cast<HumanPlayer *>(p);
//    std::cout << "\n";

//    {
//        for (int i = 0; i < 3; i++) {
//            Word w(Dictionary::getRandomHint());
//            operator<<(std::cout, w);
//            std::cout << "\n";
//            p->guessWord(d, w);
//            std::cout << *dynamic_cast<HumanPlayer *>(p);
//            std::cout << "\n";
//            operator<<(std::cout, d);
//            std::cout << "\n";
//        }
//    }
//
//    p->updatePlayerStats();
//    std::cout << *dynamic_cast<HumanPlayer *>(p);
//
//    {
//        for (int i = 0; i < 3; i++) {
//            Word w(Dictionary::getRandomHint());
//            operator<<(std::cout, w);
//            std::cout << "\n";
//            p->guessWord(d, w);
//            std::cout << *dynamic_cast<HumanPlayer *>(p);
//            std::cout << "\n";
//            operator<<(std::cout, d);
//            std::cout << "\n";
//        }
//    }
//
//    p->updatePlayerStats();
//    std::cout << *dynamic_cast<HumanPlayer *>(p);
//
//    delete p;

//    Player* p1 = new HumanPlayer;
//    Player* p2 = new HumanPlayer;
//    HumanPlayerBuilder builder;
//    builder.setLives(4);
//    builder.setName("Player 1");
//    p1 = builder.build();
//    builder.setName("Player 2");
//    p2 = builder.build();
//    std::cout << *dynamic_cast<HumanPlayer *>(p1)<<"\n";
//    std::cout << *dynamic_cast<HumanPlayer *>(p2);

//    std::vector<Player*> players;
//    players.push_back(p1);
//    players.push_back(p2);
//    for (const auto player : players)
//        std::cout << *dynamic_cast<HumanPlayer *>(player);

//    std::cout<<*dynamic_cast<HumanPlayer*>(p1);

//    Dictionary dict;
//    dict.addWords({"water", "overpopulated"});
//    dict.loadDictionaryFromFile(R"(D:\cursuri\Semestrul 2\OOP\Lab\Scribble-Jam\dict_test.txt)");

//    ConfigurationFactory<DefaultConfiguration> defaultConfig;
//    ConfigurationFactory<CustomConfiguration> customConfig;
//    Configuration* c = defaultConfig.createConfig();
//    c->loadSettings();
//    std::cout<<c;
//    c = customConfig.createConfig();
//    c->loadSettings();
//    std::cout<<c;
//    delete c;
//    delete p1;
//    delete p2;

    ConfigurationFactory<DefaultConfiguration> defaultFactory;
    ConfigurationFactory<CustomConfiguration> customFactory;
    Configuration* c = defaultFactory.createConfig();
//    c->loadSettings();
//    std::cout<<c;
//    c = customFactory.createConfig();
//    c->loadSettings();
//    std::cout<<c;



//    auto& x = Game::getGame(players, dict);

//    x.playerInput();

//    delete p1;
//    delete p2;

//    Statistics s;
//    HumanPlayerBuilder builder;
//
//    HumanPlayer p = builder.setStats(s).setLives(5).build();
//    Dictionary dict;
//    dict.loadDictionaryFromFile(R"(D:\cursuri\Semestrul 2\OOP\Lab\Scribble-Jam\dict_test.txt)");
//    Word hint = Word(Dictionary::getRandomHint());
//    std::cout<<"Hint: "<<hint<<"\n";
//    p.guessWord(dict, hint);
//    operator<<(std::cout, p);
//    p = builder.setName("Test").build();
//    operator<<(std::cout, p);
//    p = builder.setLives(3).setName("Test").setStats(s).build();
//    operator<<(std::cout, p);

    // ---------------------------------------------------------------------------------------------------------

    Player* p1 = new HumanPlayer;
    Player* p2 = new HumanPlayer;
    HumanPlayerBuilder builder;
    builder.setLives(2);
    builder.setName("Player 1");
    p1 = builder.build();
    builder.setName("Player 2");
    p2 = builder.build();

    std::vector<Player*> players;
    players.push_back(p1);
    players.push_back(p2);

    Dictionary<std::string> dict;
    dict.addWords({"water", "overpopulated"});
    dict.loadDictionaryFromFile(R"(D:\cursuri\Semestrul 2\OOP\Lab\Scribble-Jam\dict_test.txt)");

    Game* game = Game::getInstance(players, dict);
//    std::cout<<*game;

//    builder.setLives(0);
//    builder.setName("TEST");
//    players[0] = builder.build();
//    players[1] = builder.build();

//    Game* game2 = Game::getInstance(players, dict);
//    std::cout<<*game2;

    game->run();

    delete p1;
    delete p2;
//    delete game;
    return 0;
}