#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <algorithm>

class Dictionary {
private:
    std::vector<std::string> dictionary;
public:
    explicit Dictionary(const std::vector<std::string> &dictionary) : dictionary{dictionary} {
        std::cout<<"Constructor initializare Dictionary\n";
    }
    Dictionary(const Dictionary &other) : dictionary{other.dictionary} {
        std::cout<<"Constructor copiere Dictionary\n";
    }
    Dictionary &operator=(const Dictionary &other) {
        this->dictionary = other.dictionary;
        std::cout<<"operator= copiere Dictionary\n";
        return *this;
    }
    friend std::ostream& operator<<(std::ostream &os, const Dictionary &dict_object) {
        os<<"Legal words: ";
        for (const auto &word : dict_object.dictionary)
            os<<word<<" ";
        os<<"\n";
        return os;
    }
    ~Dictionary() { std::cout<<"Destructor Dictionary\n"; }

    // -----------------------------------------------------------------

    void loadDictionaryFromFile(const std::string &file) {
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
    void addWords(const std::vector<std::string> &new_words) {
        for (auto &word: new_words)
            this->dictionary.push_back(word);
    }
    void emptyDictionary() {
        this->dictionary.clear();
    }
};

class Word {
private:
    std::string letters;
    std::map<std::string, bool> word_tracker;
public:
    Word(const std::string &letters, const std::map<std::string, bool> &word_tracker) : letters{letters}, word_tracker{word_tracker} {
        std::cout<<"Constructor initializare Word\n";
    }
    Word(const Word &other) : letters{other.letters} {
        std::cout<<"Constructor copiere Word\n";
    }
    Word &operator=(const Word &other) {
        this->letters = other.letters;
        std::cout<<"operator= copiere Word\n";
        return *this;
    }
    friend std::ostream& operator<<(std::ostream &os, const Word &word_object) {
        os<<"Letters: "<<word_object.letters<<"\nWords used: ";
        for (const auto &i : word_object.word_tracker)
            os<<i.first<<" ";
        os<<"\n";
        return os;
    }
    ~Word() { std::cout<<"Destructor Word\n"; }

    // -----------------------------------------------------------------

    [[nodiscard]] bool wordAttempt(const std::string &player_word) {
        if (player_word.find(this->letters) != std::string::npos && this->word_tracker.find(player_word) == this->word_tracker.end()) {
            this->word_tracker[player_word] = true;
            return true;
        }
        return false;
    }
};

class Player {
private:
    int lives;
    int score;
public:
    Player(const int lives, const int score) : lives(lives), score(score) {
        std::cout<<"Constructor initializare Player\n";
    }
    Player(const Player &other) : lives{other.lives}, score{other.score} {
        std::cout<<"Constructor copiere Player\n";
    }
    Player &operator=(const Player &other) {
        this->lives = other.lives;
        this->score = other.score;
        std::cout<<"operator= copiere Player\n";
        return *this;
    }
    friend std::ostream &operator<<(std::ostream &os, const Player &player) {
        os<<"Score: "<<player.score<<"\nLives: "<<player.lives<<"\n";
        return os;
    }
    ~Player() { std::cout<<"Destructor Player\n"; }
};

class Configuration {
private:
    std::string difficulty;
    int time_limit;
    int starting_lives;
public:
    Configuration(const std::string &default_difficulty = "NORMAL", const int time_limit = 10, const int starting_lives = 3) : difficulty{default_difficulty}, time_limit{time_limit}, starting_lives{starting_lives} {
        std::cout<<"Constructor initializare Configuration\n";
    }
    Configuration(const Configuration &other) : difficulty{other.difficulty}, time_limit{other.time_limit}, starting_lives{other.starting_lives} {
        std::cout<<"Constructor copiere Configuration\n";
    }
    Configuration &operator=(const Configuration &other) {
        this->difficulty = other.difficulty;
        this->time_limit = other.time_limit;
        this->starting_lives = other.starting_lives;
        std::cout<<"operator= copiere Configuration\n";
        return *this;
    }
    friend std::ostream &operator<<(std::ostream &os, const Configuration &config) {
        os<<"Difficulty: "<<config.difficulty<<"\nTime limit: "<<config.time_limit<<"\n"<<"Lives: "<<config.starting_lives<<"\n";
        return os;
    }
    ~Configuration() { std::cout<<"Destructor Configuration\n"; }

    // -----------------------------------------------------------------

    void loadSettings() {
        std::string user_difficulty;
        std::ifstream f("D:\\cursuri\\Semestrul 2\\OOP\\Lab\\Scribble-Jam\\tastatura.txt");
        if (f.is_open()) {
            f>>user_difficulty;
            std::transform(user_difficulty.begin(), user_difficulty.end(), user_difficulty.begin(), ::toupper);
            if (user_difficulty == "EASY") {
                this->difficulty = user_difficulty, this->time_limit = 15, this->starting_lives = 5;
            }
            else if (user_difficulty == "NORMAL") {
                this->difficulty = user_difficulty, this->time_limit = 10, this->starting_lives = 3;
            }
            else if (user_difficulty == "HARD") {
                this->difficulty = user_difficulty, this->time_limit = 5, this->starting_lives = 2;
            }
            else {
                this->difficulty = "CUSTOM";
                int user_time_limit, user_starting_lives;
                f>>user_time_limit>>user_starting_lives;
                this->time_limit = user_time_limit;
                this->starting_lives = user_starting_lives;
            }
        }
        else
            std::perror("file not found");
    }
};

int main()
{
    /*Dictionary dict1({}), dict2({"pressured", "vanilla", "interrogation"});
    dict1.addWords({"red"});
    dict1.loadDictionaryFromFile("D:\\cursuri\\Semestrul 2\\OOP\\Lab\\Scribble-Jam\\dict_test.txt");
    dict1.addWords({"surprisingly", "forecast", "weathered"});
    operator<<(std::cout, dict1);
    dict1 = dict2;
    operator<<(std::cout, dict1);
    dict2.emptyDictionary();
    operator<<(std::cout, dict2);*/

    /*Dictionary dict({});
    dict.loadDictionaryFromFile("dict_test.txt");
    operator<<(std::cout, dict);
    Word word1("ou", {}), word2("iti", {});
    std::cout<<word1.wordAttempt("house")<<"\n"<<word1.wordAttempt("house")<<"\n";
    std::cout<<word2.wordAttempt("block")<<"\n"<<word2.wordAttempt("overwriting")<<"\n";
    operator<<(std::cout, dict);
    operator<<(std::cout, word2);
    word2 = word1;
    operator<<(std::cout, word2);*/

    /*Player player1(3, 5), player2(1, 4);
    operator<<(operator<<(std::cout, player1), player2);
    player1 = player2;
    operator<<(std::cout, player1);*/

    /*Configuration config1, config2;
    operator<<(std::cout, config1);
    config1.loadSettings();
    operator<<(std::cout, config1);
    config2 = config1;
    operator<<(std::cout, config2);*/
    return 0;
}