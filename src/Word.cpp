#include "../headers/Word.h"
#include <iostream>
#include <string>
#include <map>
#include <utility>

Word::Word(std::string letters) : letters{std::move(letters)} {
    std::cout << "Initialization constructor Word\n";
}

Word::Word(const Word &other) : letters{other.letters} {
    std::cout << "Copy constructor Word\n";
}

Word &Word::operator=(const Word &other) {
    this->letters = other.letters;
    std::cout << "Assignment operator Word\n";
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Word &word) {
    os << "Letters: " << word.letters << "\n";
    return os;
}

Word::~Word() { std::cout << "Destructor Word\n"; }

/**
 * @details
 * There are two getters from the @ref Dictionary class, used for updating the list of guessed words and the current
 * @ref Dictionary object.
 */
[[nodiscard]] bool Word::wordAttempt(const std::string &inputWord, Dictionary &dictObject) {
    std::map<std::string, bool> wordTracker = dictObject.getWordTracker();
    std::vector<std::string> dictionary = dictObject.getDictionary();
    if (inputWord.find(letters) != std::string::npos && wordTracker.find(inputWord) == wordTracker.end()) {
        wordTracker[inputWord] = true;
        dictObject = *new Dictionary(dictionary, wordTracker);
        return true;
    }
    return false;
}