#include "../headers/Dictionary.h"
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <random>


std::vector<std::string> Dictionary::hints = {"an", "the", "iti", "ou", "som", "gri", "li", "sal", "dw", "ntr"};

Dictionary::Dictionary(const std::vector<std::string> &dictionary, const std::map<std::string, bool> &wordTracker)
        : dictionary{dictionary}, wordTracker{wordTracker}, length{static_cast<int>(dictionary.size())} {
    std::cout << "Initialization constructor Dictionary\n";
}

Dictionary::Dictionary(const Dictionary &other) : dictionary{other.dictionary}, wordTracker{other.wordTracker},
                                                  length{other.length} {
    std::cout << "Copy constructor Dictionary\n";
}

Dictionary &Dictionary::operator=(const Dictionary &other) {
    this->dictionary = other.dictionary;
    this->wordTracker = other.wordTracker;
    this->length = other.length;
    std::cout << "Assignment operator Dictionary\n";
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Dictionary &dictObject) {
    os << "Legal words: ";
    for (const auto &word: dictObject.dictionary)
        os << word << " ";
    os << "\nWords used: ";
    for (const auto &word: dictObject.wordTracker)
        os << word.first << " ";
    os << "\nLength: " << dictObject.length << "\nHints: ";
    for (const auto &hint: Dictionary::hints)
        std::cout << hint << " ";
    std::cout << "\n";
    return os;
}

Dictionary::~Dictionary() {
    std::cout << "Destructor Dictionary\n";
}

/**
 * @details
 * The @ref loadDictionaryFromFile function loads the words for the dictionary from a file, unless there's an error and
 * the file cannot be opened.
 */
void Dictionary::loadDictionaryFromFile(const std::string &file) {
    try {
        std::ifstream f(file);
        std::string word;
        while (f >> word) {
            this->dictionary.push_back(word);
            this->length++;
        }
        f.close();
    }
    catch (const std::ifstream::failure &err) {
        std::cerr << err.what() << "\n";
    }
}

/**
 * @details
 * The @ref addWords function allows for other extra words to be added to the dictionary.
 */
void Dictionary::addWords(const std::vector<std::string> &newWords) {
    for (const auto &word: newWords) {
        this->dictionary.push_back(word);
        this->length++;
    }
}

/**
 * @details
 * the @ref emptyDictionary function empties the current dictionary, as well as all of the words guessed so far.
 */
void Dictionary::emptyDictionary() {
    this->dictionary.clear();
    this->wordTracker.clear();
    length = 0;
}

const std::map<std::string, bool> &Dictionary::getWordTracker() const {
    return wordTracker;
}

const std::vector<std::string> &Dictionary::getDictionary() const {
    return dictionary;
}

void Dictionary::updateWordTracker(Dictionary &dictObject, const std::string &word) {
    dictObject.wordTracker[word] = true;
}

//std::string Dictionary::getRandomWord(Dictionary &dictObject) {
//    std::random_device dev;
//    std::mt19937 rng(dev());
//    std::uniform_int_distribution<std::mt19937::result_type> randomIndex(0, dictObject.length - 1);
//    return dictObject.dictionary[randomIndex(rng)];
//}

std::string Dictionary::getRandomHint() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> randomIndex(0, hints.size() - 1);
    return hints[randomIndex(rng)];
}