#include "leaderboard.h"
#include "character.h"
#include "game.h"
#include <GL/glut.h>
#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

const int MAX_LEADERBOARD_ENTRIES = 10;
const string LEADERBOARD_FILE = "leaderboard.txt";

vector<ScoreEntry> leaderboard;

void drawLeaderboard() {
    glColor3f(1.0f, 1.0f, 0.0f);
    glRasterPos2f(-0.3f, 0.5f);
    string title = "LEADERBOARD";
    for (char c : title) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }
    
    glColor3f(textColor.r, textColor.g, textColor.b);
    glRasterPos2f(-0.5f, 0.35f);
    string header = "Rank  Player Name            Score";
    for (char c : header) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
    
    glColor3f(textColor.r, textColor.g, textColor.b);
    glLineWidth(1.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.5f, 0.33f);
    glVertex2f(0.5f, 0.33f);
    glEnd();
    
    float yPos = 0.25f;
    int displayedEntries = min((int)leaderboard.size(), MAX_LEADERBOARD_ENTRIES);
    
    for (int i = 0; i < displayedEntries; i++) {
        if (leaderboard[i].name == playerName && leaderboard[i].score == score) {
            glColor3f(highlightColor.r, highlightColor.g, highlightColor.b);
        } else {
            glColor3f(textColor.r, textColor.g, textColor.b);
        }
        
        glRasterPos2f(-0.5f, yPos);
        string rank = to_string(i + 1) + ".";
        for (char c : rank) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
        }
        
        glRasterPos2f(-0.4f, yPos);
        string name = leaderboard[i].name;
        if (name.length() > 20) name = name.substr(0, 17) + "...";
        for (char c : name) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
        }
        
        glRasterPos2f(0.3f, yPos);
        string scoreStr = to_string(leaderboard[i].score);
        for (char c : scoreStr) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
        }
        
        yPos -= 0.07f;
    }
    
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2f(-0.3f, -0.5f);
    string instructions = "Press R to restart game";
    for (char c : instructions) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}

void saveLeaderboard() {
    ofstream outFile(LEADERBOARD_FILE);
    if (!outFile.is_open()) {
        cerr << "Error: Could not open leaderboard file for writing." << endl;
        return;
    }
    
    for (const ScoreEntry& entry : leaderboard) {
        outFile << entry.name << "," << entry.score << endl;
    }
    
    outFile.close();
}

void loadLeaderboard() {
    leaderboard.clear();
    
    ifstream inFile(LEADERBOARD_FILE);
    if (!inFile.is_open()) {
        cout << "No existing leaderboard found. Creating new leaderboard." << endl;
        return;
    }
    
    string line;
    while (getline(inFile, line)) {
        size_t commaPos = line.find(',');
        if (commaPos != string::npos) {
            string name = line.substr(0, commaPos);
            int score = stoi(line.substr(commaPos + 1));
            leaderboard.push_back(ScoreEntry(name, score));
        }
    }
    
    inFile.close();
    
    sort(leaderboard.begin(), leaderboard.end());
}

void addScoreToLeaderboard(string name, int score) {
    bool playerExists = false;
    
    for (ScoreEntry& entry : leaderboard) {
        if (entry.name == name) {
            if (score > entry.score) {
                entry.score = score;
            }
            playerExists = true;
            break;
        }
    }
    
    if (!playerExists) {
        leaderboard.push_back(ScoreEntry(name, score));
    }
    
    sort(leaderboard.begin(), leaderboard.end());
    
    if (leaderboard.size() > MAX_LEADERBOARD_ENTRIES) {
        leaderboard.resize(MAX_LEADERBOARD_ENTRIES);
    }
    
    saveLeaderboard();
}