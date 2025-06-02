#include <raylib.h>

int main(void) {
  const int screenWidth = 800;
  const int screenHeight = 600;
  Color green = {20, 160, 133, 255};

  Vector2 ballPosition = {screenWidth / 2.0f, screenHeight / 2.0f};
  Vector2 ballVelocity = {300.f, 150.0f};
  float ballRadius = 20.0f;

  InitWindow(screenWidth, screenHeight, "Bouncing Ball");
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    float dt = GetFrameTime(); // delta time

    ballPosition.x += ballVelocity.x * dt;
    ballPosition.y += ballVelocity.y * dt;

    // Bounds Checking
    if (ballPosition.x - ballRadius < 0 ||
        ballPosition.x + ballRadius > screenWidth) {
      ballVelocity.x *= -1;
    }
    if (ballPosition.y - ballRadius < 0 ||
        ballPosition.y + ballRadius > screenHeight) {
      ballVelocity.y *= -1;
    }

    // Objects
    BeginDrawing();
    ClearBackground(green);
    DrawCircleV(ballPosition, ballRadius, WHITE);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
