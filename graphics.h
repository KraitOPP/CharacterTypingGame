#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "character.h"

// Graphics and display functions
void display();
void reshape(int width, int height);

// Drawing functions
void drawCharacter(float posX, float posY, char value, Color color, float rotation, float scale);
void displayTree();
void displayClouds();
void displaySun();
void drawParticles();

// UI Drawing functions
void drawGameInterface();
void drawStartScreen();
void drawGameOverScreen();

#endif // GRAPHICS_H