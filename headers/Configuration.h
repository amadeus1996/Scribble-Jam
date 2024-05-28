#ifndef OOP_CONFIGURATION_H
#define OOP_CONFIGURATION_H

#include <iostream>
#include <algorithm>


class Configuration {
protected:
    std::string difficulty;
    int timeLimit;
    int startingLives;
    int numOfPlayers;
public:
    /**
     * @brief This is the @ref Configuration class for the current game's settings.
     * @param difficulty
     * @param timeLimit
     * @param startingLives
     * @param numOfPlayers
     */

    virtual ~Configuration();

    virtual void loadSettings() = 0;

//    Configuration(const Configuration &other);

//    Configuration &operator=(const Configuration &other);

    friend std::ostream &operator<<(std::ostream &, const Configuration *);
};


#endif //OOP_CONFIGURATION_H