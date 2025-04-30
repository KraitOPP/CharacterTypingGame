#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <string>
#include <vector>

// ScoreEntry structure for leaderboard
struct ScoreEntry {
    std::string name;
    int score;
    
    ScoreEntry(std::string n = "", int s = 0) : name(n), score(s) {}
    
    bool operator<(const ScoreEntry& other) const {
        return score > other.score; // Sort in descending order
    }
};

// Leaderboard constants
extern const int MAX_LEADERBOARD_ENTRIES;
extern const std::string LEADERBOARD_FILE;

// Global leaderboard vector
extern std::vector<ScoreEntry> leaderboard;

// Leaderboard functions
void saveLeaderboard();
void loadLeaderboard();
void addScoreToLeaderboard(std::string name, int score);
void drawLeaderboard();

#endif // LEADERBOARD_H