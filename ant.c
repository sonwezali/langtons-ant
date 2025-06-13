#include <raylib.h>
#include <time.h>

#define COLS 288
#define ROWS 162

int sq = 8;

Color colors[] = {WHITE, BLACK};
int grid[ROWS][COLS] = {0};  // 0: white, 1: black
int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int currentDirection;  // ant's current direction index
int antLoc[2];

void init() {
    antLoc[0] = ROWS / 2, antLoc[1] = COLS / 2;
    currentDirection = 0;
}

void move() {
    grid[antLoc[0]][antLoc[1]] = !grid[antLoc[0]][antLoc[1]];  // flip the color
    antLoc[0] = (antLoc[0] + directions[currentDirection][0] + ROWS) % ROWS;
    antLoc[1] = (antLoc[1] + directions[currentDirection][1] + COLS) % COLS;
}

void whiteSquare() {
    currentDirection = (currentDirection + 1) % 4;  // 90° clockwise
    move();
}

void blackSquare() {
    currentDirection = (currentDirection + 3) % 4;  // 90° counter-clockwise
    move();
}

void update() {
    if (grid[antLoc[0]][antLoc[1]] == 0) whiteSquare();
    else blackSquare();
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