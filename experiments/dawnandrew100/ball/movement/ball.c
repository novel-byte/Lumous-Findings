#include <raylib.h>

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 600;
    Color green = {20, 160, 133, 255};

    Vector2 ballPosition = {screenWidth/2.0f, screenHeight/2.0f};
    float ballRadius = 20.0f;
    float speed = 300.0f;

    InitWindow(screenWidth, screenHeight, "Move the Ball");
    SetTargetFPS(60);

    while(!WindowShouldClose()) {
        float dt = GetFrameTime(); // delta t
        // Update Position
        if (IsKeyDown(KEY_RIGHT)) ballPosition.x += speed * dt;
        if (IsKeyDown(KEY_LEFT))  ballPosition.x -= speed * dt;
        if (IsKeyDown(KEY_UP))    ballPosition.y -= speed * dt;
        if (IsKeyDown(KEY_DOWN))  ballPosition.y += speed * dt;

        // Bounds Checking
        if (ballPosition.x - ballRadius < 0) ballPosition.x = ballRadius;
        if (ballPosition.x + ballRadius > screenWidth) ballPosition.x = screenWidth - ballRadius;
        if (ballPosition.y - ballRadius < 0) ballPosition.y = ballRadius;
        if (ballPosition.y + ballRadius > screenHeight) ballPosition.y = screenHeight - ballRadius;

        BeginDrawing();
            ClearBackground(green);
            DrawCircleV(ballPosition, ballRadius, WHITE);
            DrawText("Use arrow keys to move the ball", 10, 10, 20, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
