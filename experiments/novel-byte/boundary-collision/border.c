#include "raylib.h"

int main() {
    InitWindow(800, 600, "Boundary Collision");
    SetTargetFPS(60);

    Rectangle rect = {400, 300, 50, 50};
    float speed = 5.0f;

    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_RIGHT) && rect.x + rect.width < GetScreenWidth()) rect.x += speed;
        if (IsKeyDown(KEY_LEFT) && rect.x > 0) rect.x -= speed;
        if (IsKeyDown(KEY_UP) && rect.y > 0) rect.y -= speed;
        if (IsKeyDown(KEY_DOWN) && rect.y + rect.height < GetScreenHeight()) rect.y += speed;

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Rectangle stays inside window", 10, 10, 20, DARKGRAY);
        DrawRectangleRec(rect, GREEN);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
