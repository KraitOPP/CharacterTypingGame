# Character Typing Game

A simple C++ GLUT/OpenGL-based arcade-style typing game. Letters fall from the top of the screen, and the player must press the matching key before they hit the ground. The faster and more accurately you type, the higher your score!

---

## 🎮 Features
- Real-time falling letters in three lanes  
- Score tracking and lives (health) system  
- Smooth OpenGL rendering with background, sun, scenery, and UI  
- Game Over and restart functionality  

## 🚀 New Enhancements
1. **Leaderboard of Highest Scorers**  
   - Top 5 high scores saved to a local file (`scores.txt`).  
   - Displays at game over and on the main menu.  
2. **Dynamic Difficulty Levels**  
   - As your score increases, letters fall faster.  
   - Every 50 points moves you up one difficulty level.  
   - Maximum of 5 difficulty levels, each increasing fall speed by 20%.  

## 🎮 Controls
- **Type letters**: Press the corresponding key to "catch" a falling letter.  
- **Restart**: When **Game Over** appears, press **R** to reset.  
- **Quit**: Close the window or press **Esc**.  

## 🏗 Architecture & Flow
1. **Initialization**  
   - Seed RNG with `srand(time(0))`.  
   - Create an 800×600 GLUT window.  
   - Register callbacks: `display()`, `reshape()`, `keyboard()`, `update()`.  
2. **Main Loop** (`glutMainLoop`)  
   1. **Input** via `keyboard()`  
   2. **Update** via `update()` every 10 ms  
   3. **Render** via `display()` each frame  

## 💾 Data Structures
```cpp
struct Character {
    float posX;       // Horizontal [-1,1]
    float posY;       // Vertical position
    char  value;      // ASCII letter
    bool  active;     // Falling or caught?
};

// Globals:
int score;
int lifeScore;
bool gameover, gameStarted;
float landscapeOffsetX;
std::vector<Character> letters;
std::string playerName;
