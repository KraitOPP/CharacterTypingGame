#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include "character.h"

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

extern float sunRotation;
extern float cloudOffsetX;

void startGame();
void restartGame();
void update(int value);
void keyboard(unsigned char key, int x, int y);

void initGame();

void getUserName();

#endif 