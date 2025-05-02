#include <raylib.h>

#define WINDOW_NAME "Game"

#define SCR_WIDTH 800
#define SCR_HEIGHT 600

#define SCALE_MOD 5
#define VIR_WIDTH (SCR_WIDTH  / SCALE_MOD)
#define VIR_HEIGHT (SCR_HEIGHT / SCALE_MOD)

#define SPEED 50 // Pixels/sec

int main(void) {
  InitWindow(SCR_WIDTH, SCR_HEIGHT, WINDOW_NAME);
  SetTargetFPS(120);

  Texture2D sprite = LoadTexture("player.png");
  Vector2 pos = {
    (VIR_WIDTH  - sprite.width )/2,
    (VIR_HEIGHT - sprite.height)/2
  };

  RenderTexture2D target = LoadRenderTexture(VIR_WIDTH, VIR_HEIGHT);

  while (!WindowShouldClose()) {
    float dt = GetFrameTime();
    if (IsKeyDown(KEY_UP))    pos.y -= SPEED*dt;
    if (IsKeyDown(KEY_DOWN))  pos.y += SPEED*dt;
    if (IsKeyDown(KEY_LEFT))  pos.x -= SPEED*dt;
    if (IsKeyDown(KEY_RIGHT)) pos.x += SPEED*dt;

    BeginTextureMode(target);
    ClearBackground(RAYWHITE);
    DrawTextureEx(sprite, pos, 0, 1, WHITE);
    EndTextureMode();

    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawTexturePro(
      target.texture,
      (Rectangle){ 0, 0, target.texture.width, -target.texture.height },
      (Rectangle){ 0, 0, SCR_WIDTH, SCR_HEIGHT },
      (Vector2){ 0, 0 },
      0, WHITE
    );
    EndDrawing();
  }

  UnloadTexture(sprite);
  UnloadRenderTexture(target);
  CloseWindow();
  return 0;
}
