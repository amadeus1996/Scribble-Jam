#include "headers/Dictionary.h"
#include "headers/Word.h"
#include "headers/Player.h"
#include "headers/Configuration.h"
#include <iostream>

int main() {
    Dictionary dict1({}, {}), dict2({"pressured", "vanilla", "interrogation"}, {});
    dict1.addWords({"red"});
    dict1.loadDictionaryFromFile(R"(D:\cursuri\Semestrul 2\OOP\Lab\Scribble-Jam\dict_test.txt)");
    dict1.addWords({"surprisingly", "forecast", "weathered"});
    operator<<(std::cout, dict1);
    dict1 = dict2;
    operator<<(std::cout, dict1);
    dict2.emptyDictionary();
    operator<<(std::cout, dict2);
    std::cout << "\n";

    Dictionary dict({}, {});
    dict.loadDictionaryFromFile(R"(D:\cursuri\Semestrul 2\OOP\Lab\Scribble-Jam\dict_test.txt)");
    operator<<(std::cout, dict);
    Word word1("ou"), word2("iti"), word3("ess"), word4("it"), word5("pen");
    std::cout << word1.wordAttempt("house", dict) << "\n";
    std::cout << word1.wordAttempt("house", dict) << "\n";
    std::cout << word2.wordAttempt("block", dict) << "\n";
    std::cout << word2.wordAttempt("overwriting", dict) << "\n";
    std::cout << word3.wordAttempt("quintessence", dict) << "\n";
    std::cout << word4.wordAttempt("overwriting", dict) << "\n";
    std::cout << word4.wordAttempt("white", dict) << "\n";
    std::cout << word5.wordAttempt("suspend", dict) << "\n";
    operator<<(std::cout, dict);
    dict.emptyDictionary();
    operator<<(std::cout, dict);
    operator<<(std::cout, word2);
    word2 = word1;
    operator<<(std::cout, word2);
    std::cout << "\n";

    Player player1(3, 5), player2(1, 4);
    operator<<(operator<<(std::cout, player1), player2);
    player1 = player2;
    operator<<(std::cout, player1);
    std::cout << "\n";

    Configuration config1, config2;
    operator<<(std::cout, config1);
    config1.inputSettings();
    operator<<(std::cout, config1);
    config2 = config1;
    operator<<(std::cout, config2);
    std::cout << "\n";
    return 0;
}