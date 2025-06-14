#include <raylib.h>
#include <time.h>
#include <stdlib.h>

#define COLS 288
#define ROWS 162
#define MAX_NUM_ANTS 5

int sq = 8;

Color colors[] = {WHITE, BLACK};
int grid[ROWS][COLS] = {0};  // 0: white, 1: black
int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int currentDirection[MAX_NUM_ANTS] = {0};  // ants' current direction index
int antLoc[MAX_NUM_ANTS][2];
int n;  // number of ants

void init() {
    srand(time(NULL));
    n = (int) ((rand() / (float) RAND_MAX) * MAX_NUM_ANTS) + 1; // number of ants random [1, 5]
    for (int i = 0; i < n; i++) {
        antLoc[i][0] = (int) ((rand() / (float) RAND_MAX) * ROWS);
        antLoc[i][1] = (int) ((rand() / (float) RAND_MAX) * COLS);
    }
}

void move(int ant) {
    int currentAntLoc[2] = {antLoc[ant][0], antLoc[ant][1]};
    grid[currentAntLoc[0]][currentAntLoc[1]] = !grid[currentAntLoc[0]][currentAntLoc[1]];  // flip the color
    antLoc[ant][0] = (currentAntLoc[0] + directions[currentDirection[ant]][0] + ROWS) % ROWS;
    antLoc[ant][1] = (currentAntLoc[1] + directions[currentDirection[ant]][1] + COLS) % COLS;
}

void whiteSquare(int ant) {
    currentDirection[ant] = (currentDirection[ant] + 1) % 4;  // 90° clockwise
    move(ant);
}

void blackSquare(int ant) {
    currentDirection[ant] = (currentDirection[ant] + 3) % 4;  // 90° counter-clockwise
    move(ant);
}

void update() {
    for (int i = 0; i < n; i++) {
        if (grid[antLoc[i][0]][antLoc[i][1]] == 0) whiteSquare(i);
        else blackSquare(i);
    }
}

void drawGrid(){
    for (size_t i = 0; i < ROWS; i++) {
        for (size_t j = 0; j < COLS; j++) {
            DrawRectangleV((Vector2){j * sq, i * sq}, (Vector2){sq, sq}, colors[grid[i][j]]);
        }
    }
}

void delay(int n) {
    int tn = 1000 * n;
    clock_t start_time = clock();
 
    while (clock() < start_time + tn);
}

int main() {
    int screenWidth = COLS * sq;
    int screenHeight = ROWS * sq;
    init();
    InitWindow(screenWidth, screenHeight, "langton's art");

    while (!WindowShouldClose()) {
        // delay(10);
        ClearBackground(MAGENTA);
        BeginDrawing();
            drawGrid();
            update();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}