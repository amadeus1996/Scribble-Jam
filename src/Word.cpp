#include "../headers/Word.h"
#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <algorithm>


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

Word::~Word() {
    std::cout << "Destructor Word\n";
}

/**
 * @details
 * The @ref getWordTracker getter is used to get the list of words guessed so far.
 * If the inputted word contains the necessary letters and has not been guessed so far, the @ref updateWordTracker
 * function is called to update the @ref wordTracker of the current dictionary object.
 */
[[nodiscard]] bool Word::wordAttempt(const std::string &inputWord, Dictionary &dictObject) {
    std::map<std::string, bool> wordTracker = dictObject.getWordTracker();
    std::vector<std::string> dictionary = dictObject.getDictionary();

    if (inputWord.find(letters) != std::string::npos && wordTracker.find(inputWord) == wordTracker.end() &&
        std::count(dictionary.begin(), dictionary.end(), inputWord) > 0) {
        Dictionary::updateWordTracker(dictObject, inputWord);
        return true;
    }
    return false;
}