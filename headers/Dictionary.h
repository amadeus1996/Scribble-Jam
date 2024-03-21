#ifndef OOP_DICTIONARY_H
#define OOP_DICTIONARY_H
#include <iostream>
#include <vector>
#include <map>

class Dictionary {
private:
    std::vector<std::string> dictionary;
    std::map<std::string, bool> word_tracker;
public:
    Dictionary(const std::vector<std::string> &dictionary, const std::map<std::string, bool> &word_tracker);
    Dictionary(const Dictionary &other);
    Dictionary &operator=(const Dictionary &other);
    friend std::ostream& operator<<(std::ostream &os, const Dictionary &dict_object);
    ~Dictionary();

    void loadDictionaryFromFile(const std::string &file);
    void addWords(const std::vector<std::string> &new_words);
    void emptyDictionary();
    [[nodiscard]] const std::map<std::string, bool> &getWordTracker() const;
    [[nodiscard]] const std::vector<std::string> &getDictionary() const;
};

#endif //OOP_DICTIONARY_H
