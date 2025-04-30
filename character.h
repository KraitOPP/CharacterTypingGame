#ifndef CHARACTER_H
#define CHARACTER_H

#include <vector>

// Color structure
struct Color {
    float r, g, b;
    Color(float red = 1.0f, float green = 1.0f, float blue = 1.0f) : r(red), g(green), b(blue) {}
};

// Color constants
extern Color skyColor;
extern Color sunColor;
extern Color grassColor;
extern Color roadColor;
extern Color characterColor;
extern Color textColor;
extern Color gameOverColor;
extern Color highlightColor;

// Character structure
struct Character {
    float posX;
    float posY;
    char value;
    bool active;
    Color color;
    float rotation;
    float scale;
};

// Particle structure for effects
struct Particle {
    float posX, posY;
    float velocityX, velocityY;
    float lifeTime;
    float maxLifeTime;
    Color color;
};

// Character and particle management functions
void clearCharacters();
void clearParticles();
bool processKeypress(unsigned char key);
bool updateCharacters(float characterFallSpeed);
int getActiveCharacterCount();
void generateRandomCharacter();
void removeInactiveCharacters();
void createParticleEffect(float x, float y, Color color);
void updateParticles();

// Get character and particle vectors (for rendering)
std::vector<Character>& getCharacters();
std::vector<Particle>& getParticles();

#endif // CHARACTER_H