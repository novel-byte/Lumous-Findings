#include "raylib.h"

int main() {
    InitWindow(800, 600, "Basic Movement");
    SetTargetFPS(60);

    Vector2 position = {400, 300};
    float speed = 5.0f;

    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_RIGHT)) position.x += speed;
        if (IsKeyDown(KEY_LEFT)) position.x -= speed;
        if (IsKeyDown(KEY_UP)) position.y -= speed;
        if (IsKeyDown(KEY_DOWN)) position.y += speed;

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Use arrow keys to move the circle", 10, 10, 20, DARKGRAY);
        DrawCircleV(position, 30, SKYBLUE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
