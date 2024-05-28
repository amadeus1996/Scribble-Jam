#ifndef OOP_DICTIONARY_H
#define OOP_DICTIONARY_H

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <random>


template<typename T>
class Dictionary {
private:
    static std::vector<T> hints;
    std::vector<T> dictionary;
    std::map<T, bool> wordTracker;
    int length{};
public:
    /**
     * @brief This is the @ref Dictionary class for the words available in the dictionary and the words used so far.
     * @param hints
     * @param dictionary
     * @param wordTracker
     * @param length
     */
    Dictionary() = default;

    Dictionary(const std::vector<T> &dictionary, const std::map<T, bool> &wordTracker) : dictionary{dictionary},
                                                                                         wordTracker{wordTracker},
                                                                                         length{static_cast<int>(dictionary.size())} {
        std::cout << "Initialization constructor Dictionary\n";
    }

    Dictionary(const Dictionary &other) : dictionary{other.dictionary}, wordTracker{other.wordTracker},
                                          length{other.length} {
        std::cout << "Copy constructor Dictionary\n";
    }

    Dictionary &operator=(const Dictionary &other) {
        this->dictionary = other.dictionary;
        this->wordTracker = other.wordTracker;
        this->length = other.length;
        std::cout << "Assignment operator Dictionary\n";
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const Dictionary &dictObject) {
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

    ~Dictionary() { std::cout << "Destructor Dictionary\n"; }

    /**
     * @param file
     */
    void loadDictionaryFromFile(const std::string &file) {
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
     * @param newWords
     */
    void addWords(const std::vector<T> &newWords) {
        for (const auto &word: newWords) {
            this->dictionary.push_back(word);
            this->length++;
        }
    }

    void emptyDictionary() {
        this->dictionary.clear();
        this->wordTracker.clear();
        length = 0;
    }

    /**
     * @brief The @ref getWordTracker function is a getter used in the @ref wordAttempt function from the @ref Word
     * class.
     * @return The words used so far in the current game.
     */
    [[nodiscard]] const std::map<T, bool> &getWordTracker() const {
        return wordTracker;
    }

    [[nodiscard]] const std::vector<T> &getDictionary() const {
        return dictionary;
    }

    /**
     * @brief The @ref updateWordTracker function adds a new word to wordTracker.
     * @param dict
     * @param word
     */
    static void updateWordTracker(Dictionary &dictObject, const T &word) {
        dictObject.wordTracker[word] = true;
    }

    static T getRandomHint() {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> randomIndex(0, hints.size() - 1);
        return hints[randomIndex(rng)];
    }
};

template<typename T>
std::vector<T> Dictionary<T>::hints = {"an", "the", "iti", "ou", "som", "gri", "li", "sal", "dw", "ntr"};


#endif //OOP_DICTIONARY_H