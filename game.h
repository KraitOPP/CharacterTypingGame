#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include "character.h"

// Game state and core functionality
extern int windowWidth;
extern int windowHeight;
extern float characterPositionX;
extern int score;
extern int lifeScore;
extern bool gameover;
extern bool gameStarted;
extern bool showLeaderboard;
extern std::string playerName;
extern float landscapeOffsetX;
extern float characterFallSpeed;
extern float difficultyFactor;

// Animation variables
extern float sunRotation;
extern float cloudOffsetX;

// Function declarations
void startGame();
void restartGame();
void update(int value);
void keyboard(unsigned char key, int x, int y);

// Initialize the game
void initGame();

// Get player name from console
void getUserName();

#endif // GAME_H