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
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Character Press Game v2.0");
    
    glClearColor(skyColor.r, skyColor.g, skyColor.b, 1.0f);
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    
    glutTimerFunc(10, update, 0);
}

int main(int argc, char** argv) {
    getUserName();
    
    loadLeaderboard();
    
    srand(static_cast<unsigned int>(time(0)));
    
    setupOpenGL(argc, argv);
    
    initGame();
    
    glutMainLoop();
    
    return 0;
}