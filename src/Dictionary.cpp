#include "../headers/Dictionary.h"
#include <iostream>
#include <vector>
#include <map>
#include <fstream>

Dictionary::Dictionary(const std::vector<std::string> &dictionary, const std::map<std::string, bool> &word_tracker) : dictionary{dictionary}, word_tracker{word_tracker} {
    std::cout<<"Constructor initializare Dictionary\n";
}
Dictionary::Dictionary(const Dictionary &other) : dictionary{other.dictionary}, word_tracker{other.word_tracker} {
    std::cout<<"Constructor copiere Dictionary\n";
}
Dictionary& Dictionary::operator=(const Dictionary &other) {
    this->dictionary = other.dictionary;
    this->word_tracker = other.word_tracker;
    std::cout<<"operator= copiere Dictionary\n";
    return *this;
}
std::ostream& operator<<(std::ostream &os, const Dictionary &dict_object) {
    os<<"Legal words: ";
    for (const auto &word : dict_object.dictionary)
        os<<word<<" ";
    os<<"\nWords used: ";
    for (const auto &i : dict_object.word_tracker)
        os<<i.first<<" ";
    os<<"\n";
    return os;
}
Dictionary::~Dictionary() { std::cout<<"Destructor Dictionary\n"; }

void Dictionary::loadDictionaryFromFile(const std::string &file) {
    std::ifstream f(file);
    if (f.is_open()) {
        std::string word;
        while (f>>word)
            this->dictionary.push_back(word);
        f.close();
    }
    else
        std::perror("Error");
}
void Dictionary::addWords(const std::vector<std::string> &new_words) {
    for (auto &word: new_words)
        this->dictionary.push_back(word);
}
void Dictionary::emptyDictionary() {
    this->dictionary.clear();
    this->word_tracker.clear();
}
[[nodiscard]] const std::map<std::string, bool> &Dictionary::getWordTracker() const {
    return word_tracker;
}
[[nodiscard]] const std::vector<std::string> &Dictionary::getDictionary() const {
    return dictionary;
}