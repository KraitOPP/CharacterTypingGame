#include "game.h"
#include "character.h"
#include "graphics.h"
#include "leaderboard.h"
#include <GL/glut.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

// Game state variables
int windowWidth = 800;
int windowHeight = 600;
float characterPositionX = 0.0f;
int score = 0;
int lifeScore = 3;
bool gameover = false;
bool gameStarted = false;
bool showLeaderboard = false;
std::string playerName;
float landscapeOffsetX = -1.0;
float characterFallSpeed = 0.003f;
float difficultyFactor = 1.0f;

// Animation variables
float sunRotation = 0.0f;
float cloudOffsetX = 0.0f;

void initGame() {
    srand(static_cast<unsigned int>(time(0)));
    loadLeaderboard();
}

void getUserName() {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "|     Character Press Game              |" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Enter your name: ";
    std::cin >> playerName;
    
    if (playerName.length() > 20) {
        playerName = playerName.substr(0, 20);
    }
}

void startGame() {
    gameStarted = true;
}

void restartGame() {
    clearCharacters();
    clearParticles();
    characterPositionX = 0.0f;
    score = 0;
    lifeScore = 3;
    gameover = false;
    gameStarted = false;
    showLeaderboard = false;
    characterFallSpeed = 0.003f;
}

void keyboard(unsigned char key, int x, int y) {
    if (!gameStarted) {
        if (key == ' ') {
            startGame();
        }
        return;
    }
    
    if (!gameover) {
        bool matched = processKeypress(key);
        if (matched) {
            score++;
            if (score % 10 == 0 && characterFallSpeed < 0.01f) {
                characterFallSpeed += 0.0005f;
            }
        }
    } else {
        if (key == 'r' || key == 'R') {
            showLeaderboard = false;
            restartGame();
            startGame();
        } else if (key == 'l' || key == 'L') {
            showLeaderboard = !showLeaderboard;
        }
    }
}

void update(int value) {
    // Update animations
    sunRotation += 0.2f;
    if (sunRotation > 360.0f) sunRotation -= 360.0f;
    
    cloudOffsetX += 0.0005f;
    if (cloudOffsetX > 2.0f) cloudOffsetX = -2.0f;
    
    if (landscapeOffsetX >= 1) {
        landscapeOffsetX = -1.0;
    } else {
        landscapeOffsetX += 0.001f;
    }
    
    // Update particles
    updateParticles();
    
    // Update game logic
    if (!gameover && gameStarted) {
        // Update character positions and check for game over
        bool gameOver = updateCharacters(characterFallSpeed);
        if (gameOver) {
            lifeScore--;
            if (lifeScore <= 0) {
                gameover = true;
                addScoreToLeaderboard(playerName, score);
            }
        }
        
        // Generate new characters
        int activeCharacterCount = getActiveCharacterCount();
        if (activeCharacterCount < 3) {
            generateRandomCharacter();
        }

        // Clean up inactive characters
        removeInactiveCharacters();
    }
    
    glutPostRedisplay();
    glutTimerFunc(10, update, 0);
}