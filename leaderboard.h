#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <string>
#include <vector>

struct ScoreEntry {
    std::string name;
    int score;
    
    ScoreEntry(std::string n = "", int s = 0) : name(n), score(s) {}
    
    bool operator<(const ScoreEntry& other) const {
        return score > other.score; 
    }
};

extern const int MAX_LEADERBOARD_ENTRIES;
extern const std::string LEADERBOARD_FILE;

extern std::vector<ScoreEntry> leaderboard;

void saveLeaderboard();
void loadLeaderboard();
void addScoreToLeaderboard(std::string name, int score);
void drawLeaderboard();

#endif 