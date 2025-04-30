#include "graphics.h"
#include "game.h"
#include "character.h"
#include "leaderboard.h"
#include <GL/glut.h>
#include <string>
#include <cmath>

using namespace std;

void drawCharacter(float posX, float posY, char value, Color color, float rotation, float scale) {
    glPushMatrix();
    glTranslatef(posX, posY, 0.0f);
    glRotatef(rotation, 0.0f, 0.0f, 1.0f);
    glScalef(scale, scale, 1.0f);
    
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_QUADS);
    glVertex2f(-0.05f, -0.05f);
    glVertex2f(0.05f, -0.05f);
    glVertex2f(0.05f, 0.05f);
    glVertex2f(-0.05f, 0.05f);
    glEnd();
    
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1.5f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.05f, -0.05f);
    glVertex2f(0.05f, -0.05f);
    glVertex2f(0.05f, 0.05f);
    glVertex2f(-0.05f, 0.05f);
    glEnd();
    
    glColor3f(0.0f, 0.0f, 0.0f);
    glRasterPos2f(-0.015f, -0.015f);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, value);
    
    glPopMatrix();
}

void displayTree() {
    glColor3f(0.5f, 0.35f, 0.05f);
    glLineWidth(8);
    glBegin(GL_LINES);
    glVertex2f(0.3f + landscapeOffsetX, -0.7f);
    glVertex2f(0.3f + landscapeOffsetX, -0.3f);
    glEnd();
    
    glColor3f(0.0f, 0.6f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.3f + landscapeOffsetX, -0.1f);
    glVertex2f(0.1f + landscapeOffsetX, -0.3f);
    glVertex2f(0.5f + landscapeOffsetX, -0.3f);
    glEnd();
    
    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.3f + landscapeOffsetX, -0.0f);
    glVertex2f(0.15f + landscapeOffsetX, -0.2f);
    glVertex2f(0.45f + landscapeOffsetX, -0.2f);
    glEnd();
    
    glColor3f(0.8f, 0.7f, 0.6f);  
    glBegin(GL_POLYGON);
    glVertex2f(0.55f + landscapeOffsetX, -0.3);  
    glVertex2f(0.55f + landscapeOffsetX, -0.1);
    glVertex2f(0.1f + landscapeOffsetX, -0.1);
    glVertex2f(0.1f + landscapeOffsetX, -0.3);
    glEnd();
    
    glColor3f(0.6f, 0.4f, 0.2f);
    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.55f + landscapeOffsetX, -0.3);  
    glVertex2f(0.55f + landscapeOffsetX, -0.1);
    glVertex2f(0.1f + landscapeOffsetX, -0.1);
    glVertex2f(0.1f + landscapeOffsetX, -0.3);
    glEnd();
    
    glColor3f(0.0f, 0.0f, 0.0f);  
    glRasterPos2f(0.11f + landscapeOffsetX, -0.2f);
    string signText = "Char Press Game";
    for (char c : signText) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }
}

void displayClouds() {
    float cloud1X = -0.7f + cloudOffsetX;
    glColor3f(0.95f, 0.95f, 0.95f);
    
    glPushMatrix();
    glTranslatef(cloud1X, 0.6f, 0.0f);
    glutSolidSphere(0.08, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(cloud1X + 0.07f, 0.63f, 0.0f);
    glutSolidSphere(0.06, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(cloud1X - 0.07f, 0.62f, 0.0f);
    glutSolidSphere(0.06, 20, 20);
    glPopMatrix();
    
    float cloud2X = 0.3f + cloudOffsetX * 0.7f;
    
    glPushMatrix();
    glTranslatef(cloud2X, 0.7f, 0.0f);
    glutSolidSphere(0.07, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(cloud2X + 0.06f, 0.72f, 0.0f);
    glutSolidSphere(0.05, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(cloud2X - 0.06f, 0.69f, 0.0f);
    glutSolidSphere(0.05, 20, 20);
    glPopMatrix();
}

void displaySun() {
    glPushMatrix();
    glTranslatef(0.7f + landscapeOffsetX * 0.2f, 0.7f, 0.0f);
    glRotatef(sunRotation, 0.0f, 0.0f, 1.0f);
    
    glColor3f(sunColor.r, sunColor.g, sunColor.b);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f);
    for (int i = 0; i <= 360; i += 10) {
        float angle = 3.14159f * i / 180.0f;
        float x = 0.09f * cos(angle);
        float y = 0.09f * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
    
    glColor3f(sunColor.r, sunColor.g, sunColor.b);
    for (int i = 0; i < 12; i++) {
        float angle = 3.14159f * i * 30 / 180.0f;
        float x1 = 0.09f * cos(angle);
        float y1 = 0.09f * sin(angle);
        float x2 = 0.15f * cos(angle);
        float y2 = 0.15f * sin(angle);
        
        glLineWidth(3.0f);
        glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glEnd();
    }
    
    glPopMatrix();
}

void drawParticles() {
    glPointSize(3.0f);
    glBegin(GL_POINTS);
    for (const Particle& p : getParticles()) {
        float alpha = p.lifeTime / p.maxLifeTime;
        glColor4f(p.color.r, p.color.g, p.color.b, alpha);
        glVertex2f(p.posX, p.posY);
    }
    glEnd();
}

void drawGameInterface() {
    // Display life hearts
    glColor3f(textColor.r, textColor.g, textColor.b);
    glRasterPos2f(-0.98f, -0.8f);
    string livesText = "Lives: ";
    for (char c : livesText) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }
    
    for (int i = 0; i < lifeScore; i++) {
        float heartX = -0.70f + i * 0.08f;
        float heartY = -0.8f;
        float heartSize = 0.025f;
        
        glColor3f(1.0f, 0.2f, 0.2f);
        
        glBegin(GL_POLYGON);
        for (int j = 0; j <= 180; j++) {
            float angle = j * 3.14159f / 180.0f;
            float x = heartX - heartSize/2 + heartSize/2 * cos(angle);
            float y = heartY + heartSize/2 * sin(angle);
            glVertex2f(x, y);
        }
        glEnd();
        
        glBegin(GL_POLYGON);
        for (int j = 0; j <= 180; j++) {
            float angle = j * 3.14159f / 180.0f;
            float x = heartX + heartSize/2 + heartSize/2 * cos(angle);
            float y = heartY + heartSize/2 * sin(angle);
            glVertex2f(x, y);
        }
        glEnd();
        
        glBegin(GL_TRIANGLES);
        glVertex2f(heartX - heartSize, heartY);
        glVertex2f(heartX + heartSize, heartY);
        glVertex2f(heartX, heartY - heartSize);
        glEnd();
    }

    // Display player name
    glColor3f(textColor.r, textColor.g, textColor.b);
    glRasterPos2f(-0.98f, -0.9f);
    string textToDisplay = "Player: " + playerName;
    for (char c : textToDisplay) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }

    // Display score
    glColor3f(highlightColor.r, highlightColor.g, highlightColor.b);
    glRasterPos2f(0.75f, -0.8f);
    string scoreText = "Score: " + to_string(score);
    for (char c : scoreText) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }
}

void drawStartScreen() {
    glColor4f(0.0f, 0.0f, 0.0f, 0.7f); 
    glBegin(GL_QUADS);
    glVertex2f(-0.7f, 0.5f);
    glVertex2f(0.7f, 0.5f);
    glVertex2f(0.7f, -0.5f);
    glVertex2f(-0.7f, -0.5f);
    glEnd();
    
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2f(-0.6f, 0.3f);
    string title = "Character Press Game";
    for (char c : title) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }
    
    glRasterPos2f(-0.6f, 0.1f);
    string instr1 = "Press the keyboard keys that match the falling letters";
    for (char c : instr1) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
    
    glRasterPos2f(-0.6f, 0.0f);
    string instr2 = "Each correct key press earns you 1 point";
    for (char c : instr2) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
    
    glRasterPos2f(-0.6f, -0.1f);
    string instr3 = "Miss 3 letters and the game is over!";
    for (char c : instr3) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
    
    glRasterPos2f(-0.6f, -0.3f);
    string instr4 = "Press SPACE to start";
    for (char c : instr4) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}

void drawGameOverScreen() {
    glColor4f(0.0f, 0.0f, 0.0f, 0.7f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();
    
    if (showLeaderboard) {
        drawLeaderboard();
    } else {
        glColor3f(gameOverColor.r, gameOverColor.g, gameOverColor.b);
        glRasterPos2f(-0.4f, 0.2f);
        string gameOverText = "Game Over!";
        for (char c : gameOverText) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
        }
        
        glColor3f(highlightColor.r, highlightColor.g, highlightColor.b);
        glRasterPos2f(-0.25f, 0.0f);
        string finalScoreText = "Final Score: " + to_string(score);
        for (char c : finalScoreText) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
        }
        
        glColor3f(textColor.r, textColor.g, textColor.b);
        glRasterPos2f(-0.45f, -0.2f);
        string instructions = "Press L to view leaderboard";
        for (char c : instructions) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
        }
        
        glRasterPos2f(-0.3f, -0.3f);
        string restartText = "Press R to restart";
        for (char c : restartText) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Sky and background
    glBegin(GL_QUADS);
    glColor3f(skyColor.r, skyColor.g, skyColor.b);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glColor3f(skyColor.r * 0.8f, skyColor.g * 0.9f, skyColor.b);
    glVertex2f(1.0f, -0.7f);
    glVertex2f(-1.0f, -0.7f);
    glEnd();

    displaySun();
    displayClouds();

    // Draw hills
    glColor3f(grassColor.r, grassColor.g, grassColor.b);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.6f + landscapeOffsetX, -0.7f);
    glVertex2f(-0.9f + landscapeOffsetX, -0.7f);
    glVertex2f(-0.75f + landscapeOffsetX, -0.3f);
    glVertex2f(-0.1f + landscapeOffsetX, -0.7f);
    glVertex2f(-0.4f + landscapeOffsetX, -0.7f);
    glVertex2f(-0.25f + landscapeOffsetX, -0.4f);
    glVertex2f(0.7f + landscapeOffsetX, -0.7f);
    glVertex2f(0.4f + landscapeOffsetX, -0.7f);
    glVertex2f(0.55f + landscapeOffsetX, -0.5f);
    glEnd();

    // Draw road
    glBegin(GL_POLYGON);
    glColor3f(roadColor.r, roadColor.g, roadColor.b);
    glVertex2f(-1.0, -0.7);
    glVertex2f(1.0, -0.7);
    glVertex2f(1.0, -1.0);
    glVertex2f(-1.0, -1.0);
    glEnd();
    
    // Draw road markings
    glColor3f(1.0f, 1.0f, 0.0f);
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    for (float x = -0.9f; x < 1.0f; x += 0.3f) {
        glVertex2f(x, -0.85f);
        glVertex2f(x + 0.15f, -0.85f);
    }
    glEnd();

    displayTree();

    // Draw UI background
    glColor4f(0.0f, 0.0f, 0.0f, 0.6f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.7f);
    glVertex2f(1.0f, -0.7f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();

    // Draw game UI elements
    drawGameInterface();

    // Draw characters
    for (const Character& character : getCharacters()) {
        if (character.active)
            drawCharacter(character.posX, character.posY, character.value, character.color, character.rotation, character.scale);
    }
    
    drawParticles();

    // Draw game state overlays
    if (gameover) {
        drawGameOverScreen();
    } else if (!gameStarted) {
        drawStartScreen();
    }

    glutSwapBuffers();
}

void reshape(int width, int height) {
    windowWidth = width;
    windowHeight = height;
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}