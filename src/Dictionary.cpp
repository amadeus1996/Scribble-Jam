#include "../headers/Dictionary.h"
#include <iostream>
#include <vector>
#include <map>
#include <fstream>

Dictionary::Dictionary(const std::vector<std::string> &dictionary, const std::map<std::string, bool> &wordTracker)
        : dictionary{dictionary}, wordTracker{wordTracker} {
    std::cout << "Initialization constructor Dictionary\n";
}

Dictionary::Dictionary(const Dictionary &other) : dictionary{other.dictionary}, wordTracker{other.wordTracker} {
    std::cout << "Copy constructor Dictionary\n";
}

Dictionary &Dictionary::operator=(const Dictionary &other) {
    this->dictionary = other.dictionary;
    this->wordTracker = other.wordTracker;
    std::cout << "Assignment operator Dictionary\n";
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Dictionary &dictObject) {
    os << "Legal words: ";
    for (const auto &word: dictObject.dictionary)
        os << word << " ";
    os << "\nWords used: ";
    for (const auto &i: dictObject.wordTracker)
        os << i.first << " ";
    os << "\n";
    return os;
}

Dictionary::~Dictionary() { std::cout << "Destructor Dictionary\n"; }

/**
 * @details
 * The @ref loadDictionaryFromFile function loads the words for the dictionary from a file, unless there's an error and
 * the file cannot be opened.
 */
void Dictionary::loadDictionaryFromFile(const std::string &file) {
    std::ifstream f(file);
    if (f.is_open()) {
        std::string word;
        while (f >> word)
            this->dictionary.push_back(word);
        f.close();
    } else
        std::perror("Error");
}

/**
 * @details
 * The @ref addWords function allows for other extra words to be added to the dictionary.
 */
void Dictionary::addWords(const std::vector<std::string> &newWords) {
    for (const auto &word: newWords)
        this->dictionary.push_back(word);
}

/**
 * @details
 * the @ref emptyDictionary function empties the current dictionary, as well as all of the words guessed so far.
 */
void Dictionary::emptyDictionary() {
    this->dictionary.clear();
    this->wordTracker.clear();
}

const std::vector<std::string> &Dictionary::getDictionary() const {
    return dictionary;
}

const std::map<std::string, bool> &Dictionary::getWordTracker() const {
    return wordTracker;
}
