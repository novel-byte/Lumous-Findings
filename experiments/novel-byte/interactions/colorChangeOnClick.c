#include "raylib.h"
#include <math.h>

int main() {
    InitWindow(800, 600, "Interaction Test");
    SetTargetFPS(60);

    Vector2 player = {100, 100};
    Vector2 object = {400, 300};
    float radius = 30.0f;
    Color objectColor = RED;

    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_RIGHT)) player.x += 4.0f;
        if (IsKeyDown(KEY_LEFT)) player.x -= 4.0f;
        if (IsKeyDown(KEY_UP)) player.y -= 4.0f;
        if (IsKeyDown(KEY_DOWN)) player.y += 4.0f;

        float dist = Vector2Distance(player, object);
        if (dist < 60.0f && IsKeyPressed(KEY_E)) {
            objectColor = (objectColor.r == RED.r) ? BLUE : RED;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Move close to object and press [E] to change color", 10, 10, 20, DARKGRAY);
        DrawCircleV(player, radius, SKYBLUE);
        DrawCircleV(object, radius, objectColor);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
