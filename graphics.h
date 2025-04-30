#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "character.h"

void display();
void reshape(int width, int height);

void drawCharacter(float posX, float posY, char value, Color color, float rotation, float scale);
void displayTree();
void displayClouds();
void displaySun();
void drawParticles();

void drawGameInterface();
void drawStartScreen();
void drawGameOverScreen();

#endif 