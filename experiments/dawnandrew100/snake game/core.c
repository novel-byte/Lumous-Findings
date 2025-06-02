#ifndef GAME_H
#define GAME_H
#include <raylib.h>
#include <stdbool.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define MAX_SNAKE_LENGTH 100
#define CELL_SIZE 20
#define GRID_WIDTH (SCREEN_WIDTH / CELL_SIZE)
#define GRID_HEIGHT (SCREEN_HEIGHT / CELL_SIZE)

typedef enum GameScreen {
  SCREEN_START,
  SCREEN_GAMEPLAY,
  SCREEN_GAMEOVER
} GameScreen;

typedef struct Segment {
  int x, y;
} Segment;

Vector2 direction = {1, 0}; // starts moving right
bool grow = false;
Segment snake[MAX_SNAKE_LENGTH];
int snakeLength = 3;
Segment food;

void DrawCenteredText(const char *text, int y, int fontSize, Color color) {
  int x = (SCREEN_WIDTH - MeasureText(text, fontSize)) / 2;
  DrawText(text, x, y, fontSize, color);
}

void CheckFood(int *food_score) {
  if (snake[0].x == food.x && snake[0].y == food.y) {
    grow = true;
    food.x = GetRandomValue(0, 19);
    food.y = GetRandomValue(0, 19);
    (*food_score)++;
  }
}

void DrawSnake(int cellSize) {
  for (int i = 0; i < snakeLength; i++) {
    DrawRectangle(snake[i].x * cellSize, snake[i].y * cellSize, cellSize,
                  cellSize, DARKGREEN);
  }
}

void DrawFood(int cellSize) {
  DrawRectangle(food.x * cellSize, food.y * cellSize, cellSize, cellSize, RED);
}

void UpdateSnake() {
  // Shift body
  for (int i = snakeLength; i > 0; i--) {
    snake[i] = snake[i - 1];
  }

  // Add new head
  snake[0].x += (int)direction.x;
  snake[0].y += (int)direction.y;

  // Wrap around screen edges
  if (snake[0].x < 0)
    snake[0].x = GRID_WIDTH - 1;
  if (snake[0].x >= GRID_WIDTH)
    snake[0].x = 0;

  if (snake[0].y < 0)
    snake[0].y = GRID_HEIGHT - 1;
  if (snake[0].y >= GRID_HEIGHT)
    snake[0].y = 0;

  // Grow or move
  if (!grow) {
    snakeLength--;
  }
  grow = false;
  snakeLength++;
}

bool SnakeIsColliding() {
  for (int i = 1; i < snakeLength; i++) {
    if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
      return true;
    }
  }
  return false;
}
#endif
