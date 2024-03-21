#ifndef OOP_CONFIGURATION_H
#define OOP_CONFIGURATION_H
#include <iostream>
#include <algorithm>

class Configuration {
private:
    std::string difficulty;
    int time_limit;
    int starting_lives;
public:
    explicit Configuration(std::string  default_difficulty = "NORMAL", int time_limit = 10, int starting_lives = 3);
    Configuration(const Configuration &other);
    Configuration &operator=(const Configuration &other);
    friend std::ostream &operator<<(std::ostream &os, const Configuration &config);
    ~Configuration();
    void loadSettings();
};


#endif //OOP_CONFIGURATION_H
