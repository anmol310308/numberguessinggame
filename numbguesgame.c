#include "raylib.h"
#include <stdlib.h> // Needed for atoi()

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "My Number Guessing Game");

    // --- YOUR EXACT VARIABLES ---
    int r = GetRandomValue(1, 100); // Picks random number between 1 and 100
    int n = 0;

    // Fixed array syntax so it compiles cleanly
    char inputBuffer[4] = ""; 
    int letterCount = 0;
    const char *feedback = "guess the number(between 1 to 100)";
    bool gameOver = false;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        
        // --- 1. HANDLE INPUT ---
        if (!gameOver) {
            int key = GetCharPressed();

            // Store digits typed from keyboard
            while (key > 0) {
                if ((key >= '0') && (key <= '9') && (letterCount < 3)) {
                    inputBuffer[letterCount] = (char)key;
                    inputBuffer[letterCount + 1] = '\0';
                    letterCount++;
                }
                key = GetCharPressed();
            }

            // Backspace deletes characters
            if (IsKeyPressed(KEY_BACKSPACE)) {
                letterCount--;
                if (letterCount < 0) letterCount = 0;
                inputBuffer[letterCount] = '\0';
            }

            // --- YOUR LOGIC FROM THE TERMINAL PROGRAM ---
            if (IsKeyPressed(KEY_ENTER) && letterCount > 0) {
                n = atoi(inputBuffer); // Convert typed text to integer 'n'

                if (n > 100 || n < 1) {
                    feedback = "invalid input";
                } 
                else if (n > r) {
                    feedback = "number is greater than actual number try again";
                } 
                else if (n < r) {
                    feedback = "number is less than actual number try again";
                } 
                else {
                    feedback = "correct guess";
                    gameOver = true;
                }

                // Clear the input box correctly
                inputBuffer[0] = '\0';
                letterCount = 0;
            }
        } else {
            // Press R to restart
            if (IsKeyPressed(KEY_R)) {
                r = GetRandomValue(1, 100);
                n = 0;
                feedback = "guess the number(between 1 to 100)";
                gameOver = false;
            }
        }

        // --- 2. DRAWING ---
        BeginDrawing();
            ClearBackground(DARKGRAY);

            // Title Banner
            DrawRectangle(50, 40, 700, 60, BLUE);
            DrawText("MY NUMBER GUESSING GAME", 230, 55, 26, WHITE);

            // Your exact text feedback string
            DrawText(feedback, 100, 160, 22, gameOver ? GREEN : ORANGE);

            // Typing input box (No more Higher/Lower buttons!)
            DrawRectangle(350, 230, 100, 50, LIGHTGRAY);
            DrawRectangleLines(350, 230, 100, 50, BLACK);
            
            if (letterCount > 0) {
                DrawText(inputBuffer, 385, 240, 30, BLACK);
            }

            // Help cues
            if (!gameOver) {
                DrawText("Type your guess and press ENTER", 260, 310, 16, LIGHTGRAY);
            } else {
                DrawText("Press [R] to start a new game!", 265, 340, 20, RAYWHITE);
            }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
