#include "../headers/Word.h"
#include <iostream>
#include <string>
#include <map>
#include <utility>

Word::Word(std::string letters) : letters{std::move(letters)} {
    std::cout<<"Constructor initializare Word\n";
}
Word::Word(const Word &other) : letters{other.letters} {
    std::cout<<"Constructor copiere Word\n";
}
Word& Word::operator=(const Word &other) {
    this->letters = other.letters;
    std::cout<<"operator= copiere Word\n";
    return *this;
}
std::ostream& operator<<(std::ostream &os, const Word &word_object) {
    os<<"Letters: "<<word_object.letters<<"\n";
    return os;
}
Word::~Word() { std::cout<<"Destructor Word\n"; }

[[nodiscard]] bool Word::wordAttempt(const std::string &player_word, Dictionary &dict_object) {
    std::map<std::string, bool> word_tracker = dict_object.getWordTracker();
    std::vector<std::string> dictionary = dict_object.getDictionary();
    if (player_word.find(letters) != std::string::npos && word_tracker.find(player_word) == word_tracker.end()) {
        word_tracker[player_word] = true;
        dict_object = *new Dictionary(dictionary, word_tracker);
        return true;
    }
    return false;
}