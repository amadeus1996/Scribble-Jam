#include <iostream>
#include "../headers/Statistics.h"


int Statistics::overallGuesses = 0;
int Statistics::overallCorrectGuesses = 0;
float Statistics::overallAccuracy = 0;
int Statistics::overallScore = 0;
int Statistics::overallPlaytime = 0;

Statistics::Statistics(int guesses, int correctGuesses, float accuracy, int score, int playtime) : guesses{guesses},
                                                                                                   correctGuesses{
                                                                                                           correctGuesses},
                                                                                                   accuracy{accuracy},
                                                                                                   score{score},
                                                                                                   playtime{playtime} {
    std::cout << "Initialization constructor Statistics\n";
}

Statistics::Statistics(const Statistics &other) : guesses{other.guesses}, correctGuesses{other.correctGuesses},
                                                  accuracy{other.accuracy},
                                                  score{other.score}, playtime{other.playtime} {
    std::cout << "Copy constructor\n";
}

Statistics &Statistics::operator=(const Statistics &other) {
    this->guesses = other.guesses;
    this->correctGuesses = other.correctGuesses;
    this->accuracy = other.accuracy;
    this->score = other.score;
    this->playtime = other.playtime;
    std::cout << "Assignment operator Statistics\n";
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Statistics &statistics) {
    os << "Guesses: " << statistics.guesses << " (total: " << Statistics::overallGuesses << ")\nCorrect guesses: "
       << statistics.correctGuesses << " (total: " << Statistics::overallCorrectGuesses << ")\nAccuracy: "
       << statistics.accuracy << "% (total: " << Statistics::overallAccuracy << "%)\nScore: " << statistics.score
       << " (total: " << Statistics::overallScore << ")\n";
    return os;
}

Statistics::~Statistics() {
    std::cout << "Destructor Statistics\n";
}

void Statistics::updateOverallStats(Statistics &stats) {
    overallGuesses += stats.guesses;
    overallCorrectGuesses += stats.correctGuesses;
    overallScore += stats.score;
    overallPlaytime += stats.playtime;
    if (overallAccuracy > 0)
        overallAccuracy = (overallAccuracy + stats.accuracy) / 2;
    else overallAccuracy = stats.accuracy;
    stats.resetStats();
}

void Statistics::resetStats() {
    this->guesses = 0;
    this->correctGuesses = 0;
    this->score = 0;
    this->playtime = 0;
    this->accuracy = 0;
}

void Statistics::updateStats(bool ok) {
    if (ok) {
        correctGuesses++;
        guesses++;
    } else guesses++;
    try {
        if (!guesses)
            throw std::invalid_argument("Division by zero");
        accuracy = static_cast<float>(correctGuesses) / static_cast<float>(guesses) * 100;
    }
    catch (const std::invalid_argument &err) {
        std::cerr << err.what() << "\n";
    }
}