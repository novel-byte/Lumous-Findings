#include "core.c"

int main(void) {
  Color TEAL = {20, 160, 133, 255};
  Color REDISH = {160, 20, 47, 255};

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Snake Game");
  SetTargetFPS(10); // snake movement speed
  int score = 0;

  snake[0] = (Segment){10, 10};
  food.x = GetRandomValue(0, 19);
  food.y = GetRandomValue(0, 19);

  GameScreen currentScreen = SCREEN_START;
  char *message;
  int fontSize;
  int x;

  while (!WindowShouldClose()) {
    float dt = GetFrameTime(); // delta t

    // Update Position
    if (IsKeyPressed(KEY_UP) && direction.y == 0) {
      direction = (Vector2){0, -1};
    }
    if (IsKeyPressed(KEY_DOWN) && direction.y == 0) {
      direction = (Vector2){0, 1};
    }
    if (IsKeyPressed(KEY_LEFT) && direction.x == 0) {
      direction = (Vector2){-1, 0};
    }
    if (IsKeyPressed(KEY_RIGHT) && direction.x == 0) {
      direction = (Vector2){1, 0};
    }

    BeginDrawing();
    ClearBackground(TEAL);
    switch (currentScreen) {
    case SCREEN_START:
      DrawCenteredText("SNAKE GAME", 200, 60, REDISH);
      DrawCenteredText("Press ENTER to Start", 260, 20, DARKGRAY);
      if (IsKeyPressed(KEY_ENTER)) {
        currentScreen = SCREEN_GAMEPLAY;
      }
      break;

    case SCREEN_GAMEPLAY:
      UpdateSnake();
      CheckFood(&score);
      if (SnakeIsColliding()) {
        currentScreen = SCREEN_GAMEOVER;
      }
      DrawSnake(CELL_SIZE);
      DrawFood(CELL_SIZE);
      DrawText(TextFormat("Score: %d", score), 10, 10, 20, DARKGRAY);
      break;

    case SCREEN_GAMEOVER:
      DrawCenteredText("GAME OVER", 200, 40, REDISH);
      DrawCenteredText(TextFormat("Final Score: %d", score), 260, 20, DARKGRAY);
      DrawCenteredText("Press R or Enter to Restart", 320, 20, DARKGRAY);
      DrawCenteredText("Press ESC to Quit", 350, 20, DARKGRAY);
      if (IsKeyPressed(KEY_R) || IsKeyPressed(KEY_ENTER)) {
        // Reset everything
        score = 0;
        snakeLength = 3;
        snake[0] = (Segment){10, 10};
        direction = (Vector2){1, 0};
        food.x = GetRandomValue(0, GRID_WIDTH - 1);
        food.y = GetRandomValue(0, GRID_HEIGHT - 1);
        currentScreen = SCREEN_GAMEPLAY;
      }
      break;
    }
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
