#include "character.h"
#include <cstdlib>
#include <algorithm>

Color skyColor(0.53f, 0.81f, 0.92f);
Color sunColor(1.0f, 0.95f, 0.1f);
Color grassColor(0.0f, 0.8f, 0.0f);
Color roadColor(0.3f, 0.3f, 0.3f);
Color characterColor(1.0f, 1.0f, 1.0f);
Color textColor(1.0f, 1.0f, 1.0f);
Color gameOverColor(1.0f, 0.2f, 0.2f);
Color highlightColor(0.0f, 1.0f, 0.7f);

static std::vector<Character> characters;
static std::vector<Particle> particles;

std::vector<Character>& getCharacters() {
    return characters;
}

std::vector<Particle>& getParticles() {
    return particles;
}

void clearCharacters() {
    characters.clear();
}

void clearParticles() {
    particles.clear();
}

bool processKeypress(unsigned char key) {
    for (Character& character : characters) {
        if (character.active && character.value == key) {
            character.active = false;
            createParticleEffect(character.posX, character.posY, character.color);
            return true;
        }
    }
    return false;
}

bool updateCharacters(float characterFallSpeed) {
    bool characterMissed = false;
    for (Character& character : characters) {
        if (character.active) {
            character.posY -= characterFallSpeed;
            character.rotation += 1.0f;
            
            if (character.posY <= -0.7f && character.active) {
                character.active = false;
                characterMissed = true;
            }
        }
    }
    return characterMissed;
}

int getActiveCharacterCount() {
    int count = 0;
    for (const Character& character : characters) {
        if (character.active)
            count++;
    }
    return count;
}

void generateRandomCharacter() {
    Character newCharacter;
    float positions[] = { -0.9f, -0.8f, -0.7f, -0.6f, -0.5f, -0.4f, -0.3f, -0.2f, -0.1f, 0.0f,
                        0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f };
    int newCharIndex = rand() % 19;
    newCharacter.posX = positions[newCharIndex];
    newCharacter.posY = 1.0f;
    
    if (rand() % 2 == 0) {
        newCharacter.value = static_cast<char>('a' + (rand() % 26));
    } else {
        newCharacter.value = static_cast<char>('A' + (rand() % 26));
    }
    
    newCharacter.color = Color(
        (float)(rand() % 100) / 100.0f + 0.5f,
        (float)(rand() % 100) / 100.0f + 0.5f,
        (float)(rand() % 100) / 100.0f + 0.5f
    );
    
    newCharacter.active = true;
    newCharacter.rotation = 0.0f;
    newCharacter.scale = 1.0f;
    characters.push_back(newCharacter);
}

void removeInactiveCharacters() {
    characters.erase(
        std::remove_if(characters.begin(), characters.end(),
            [](const Character& character) { return !character.active; }),
        characters.end()
    );
}

void createParticleEffect(float x, float y, Color color) {
    for (int i = 0; i < 15; i++) {
        Particle p;
        p.posX = x;
        p.posY = y;
        p.velocityX = (float)(rand() % 100 - 50) / 500.0f;
        p.velocityY = (float)(rand() % 100) / 500.0f;
        p.lifeTime = 1.0f;
        p.maxLifeTime = 1.0f;
        p.color = color;
        particles.push_back(p);
    }
}

void updateParticles() {
    for (int i = 0; i < particles.size(); i++) {
        particles[i].posX += particles[i].velocityX;
        particles[i].posY += particles[i].velocityY;
        particles[i].lifeTime -= 0.02f;
        
        if (particles[i].lifeTime <= 0) {
            particles.erase(particles.begin() + i);
            i--;
        }
    }
}