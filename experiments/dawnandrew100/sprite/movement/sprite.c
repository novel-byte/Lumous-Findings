#include <raylib.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
int main(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Moving Sprite");
  /* Sprite is from https://opengameart.org/content/classic-hero */
  Texture2D sprite = LoadTexture("mr_man.png");
  Vector2 spritePosition = {SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f};
  float ballRadius = 20.0f;
  float speed = 300.0f;

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    float dt = GetFrameTime(); // delta t
    // Update Position
    if (IsKeyDown(KEY_RIGHT))
      spritePosition.x += speed * dt;
    if (IsKeyDown(KEY_LEFT))
      spritePosition.x -= speed * dt;
    if (IsKeyDown(KEY_UP))
      spritePosition.y -= speed * dt;
    if (IsKeyDown(KEY_DOWN))
      spritePosition.y += speed * dt;

    // Bounds Checking
    if (spritePosition.x < 0)
      spritePosition.x = 0;
    if (spritePosition.x + sprite.width > SCREEN_WIDTH)
      spritePosition.x = SCREEN_WIDTH - sprite.width;
    if (spritePosition.y < 0)
      spritePosition.y = 0;
    if (spritePosition.y + sprite.height > SCREEN_HEIGHT)
      spritePosition.y = SCREEN_HEIGHT - sprite.height;
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawTexture(sprite, spritePosition.x, spritePosition.y, RAYWHITE);
    EndDrawing();
  }
  UnloadTexture(sprite);
  CloseWindow();
  return 0;
}
