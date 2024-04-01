#ifndef OOP_WORD_H
#define OOP_WORD_H

#include "Dictionary.h"
#include <iostream>
#include <string>

class Word {
private:
    std::string letters;
public:
    /**
     * @brief This is the @ref Word class for the hints.
     *
     * @param letters
     */
    explicit Word(std::string letters);

    Word(const Word &other);

    Word &operator=(const Word &other);

    friend std::ostream &operator<<(std::ostream &os, const Word &word);

    ~Word();

    /**
     * @brief The function @ref wordAttempt checks if the player guesses the word correctly or not.
     *
     * @param inputWord
     * @param dictObject
     *
     * @retval true - the guess was correct
     * @retval false - the guess was wrong
     */
    [[nodiscard]] bool wordAttempt(const std::string &inputWord, Dictionary &dictObject);
};

#endif //OOP_WORD_H
