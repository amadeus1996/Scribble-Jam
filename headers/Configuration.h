#ifndef OOP_CONFIGURATION_H
#define OOP_CONFIGURATION_H

#include <iostream>
#include <algorithm>

class Configuration {
private:
    std::string difficulty;
    int timeLimit;
    int startingLives;
public:
    /**
     * @brief This is the @ref Configuration class for the current game's settings.
     *
     * @param defaultDifficulty
     * @param defaultTimeLimit
     * @param defaultStartingLives
     */
    explicit Configuration(std::string defaultDifficulty = "NORMAL", int defaultTimeLimit = 10,
                           int defaultStartingLives = 3);

    Configuration(const Configuration &other);

    Configuration &operator=(const Configuration &other);

    friend std::ostream &operator<<(std::ostream &os, const Configuration &config);

    ~Configuration();

    /**
     * @brief The @ref inputSettings function receives input from the player to change the difficulty of the game.
     */
    void inputSettings();
};


#endif //OOP_CONFIGURATION_H
