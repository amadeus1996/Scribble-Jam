#ifndef OOP_STATISTICS_H
#define OOP_STATISTICS_H

#include <ostream>


class Statistics {
private:
    int guesses{}, correctGuesses{};
    float accuracy{};
    int score{}, playtime{};

    static int overallGuesses, overallCorrectGuesses, overallScore, overallPlaytime;
    static float overallAccuracy;
public:
    explicit Statistics(int guesses = 0, int correctGuesses = 0, float accuracy = 0, int score = 0, int playtime = 0);

    Statistics(const Statistics &other);

    Statistics &operator=(Statistics const &other);

    friend std::ostream &operator<<(std::ostream &os, const Statistics &statistics);

    ~Statistics();

    static void updateOverallStats(Statistics &stats);

    void resetStats();

    void updateStats(bool ok);
};


#endif //OOP_STATISTICS_H