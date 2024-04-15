#ifndef OOP_DICTIONARY_H
#define OOP_DICTIONARY_H

#include <iostream>
#include <vector>
#include <map>


class Dictionary {
private:
    static std::vector<std::string> hints;
    std::vector<std::string> dictionary;
    std::map<std::string, bool> wordTracker;
    int length{};
public:
    /**
     * @brief This is the @ref Dictionary class for the words available in the dictionary and the words used so far.
     * @param dictionary
     * @param wordTracker
     */
    Dictionary() = default;

    Dictionary(const std::vector<std::string> &dictionary, const std::map<std::string, bool> &wordTracker);

    Dictionary(const Dictionary &other);

    Dictionary &operator=(const Dictionary &other);

    friend std::ostream &operator<<(std::ostream &os, const Dictionary &dictObject);

    ~Dictionary();

    /**
     * @param file
     */
    void loadDictionaryFromFile(const std::string &file);

    /**
     * @param newWords
     */
    void addWords(const std::vector<std::string> &newWords);

    void emptyDictionary();

    /**
     * @brief The @ref getWordTracker function is a getter used in the @ref wordAttempt function from the @ref Word
     * class.
     * @return The words used so far in the current game.
     */
    [[nodiscard]] const std::map<std::string, bool> &getWordTracker() const;

    [[nodiscard]] const std::vector<std::string> &getDictionary() const;

    /**
     * @brief The @ref updateWordTracker function adds a new word to wordTracker.
     * @param dict
     * @param word
     */
    static void updateWordTracker(Dictionary &dictObject, const std::string &word);

//    static std::string getRandomWord(Dictionary &dictObject);

    static std::string getRandomHint();
};


#endif //OOP_DICTIONARY_H