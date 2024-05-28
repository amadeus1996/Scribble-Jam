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
     * @param letters
     */
    explicit Word(std::string);

    Word(const Word &);

    Word &operator=(const Word &);

    friend std::ostream &operator<<(std::ostream &, const Word &);

    ~Word();

    /**
     * @brief The function @ref wordAttempt checks if the player guesses the word correctly or not.
     * @param inputWord
     * @param dictObject
     * @retval true - the guess was correct
     * @retval false - the guess was wrong
     */
    bool wordAttempt(const std::string &, Dictionary<std::string> &);
};


#endif //OOP_WORD_H