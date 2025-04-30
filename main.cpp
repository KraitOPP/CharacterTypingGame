#include <GL/glut.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "main.h"
#include "game.h"
#include "graphics.h"
#include "character.h"
#include "leaderboard.h"

void setupOpenGL(int argc, char** argv) {
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Character Press Game v2.0");
    
    // Set clear color
    glClearColor(skyColor.r, skyColor.g, skyColor.b, 1.0f);
    
    // Register callbacks
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    
    // Set up timer for game updates
    glutTimerFunc(10, update, 0);
}

int main(int argc, char** argv) {
    // Display welcome message
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "|     Character Press Game              |" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    
    // Get user name for leaderboard
    getUserName();
    
    // Load leaderboard data
    loadLeaderboard();
    
    // Initialize random seed
    srand(static_cast<unsigned int>(time(0)));
    
    // Set up OpenGL and GLUT
    setupOpenGL(argc, argv);
    
    // Initialize game state
    initGame();
    
    // Enter the main loop
    glutMainLoop();
    
    return 0;
}