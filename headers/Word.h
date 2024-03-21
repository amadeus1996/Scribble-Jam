#ifndef OOP_WORD_H
#define OOP_WORD_H
#include "Dictionary.h"
#include <iostream>
#include <string>

class Word {
private:
    std::string letters;
public:
    explicit Word(std::string letters);
    Word(const Word &other);
    Word &operator=(const Word &other);
    friend std::ostream& operator<<(std::ostream &os, const Word &word_object);
    ~Word();

    [[nodiscard]] bool wordAttempt(const std::string &player_word, Dictionary &dict_object);
};

#endif //OOP_WORD_H
