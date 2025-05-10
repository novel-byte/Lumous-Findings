#include <raylib.h>
#include <stdio.h>
#include <math.h>

// Initial window stats
const char *window_title = "test";
const int window_width = 800;
const int window_height = 600;

// Virtual Screen Dimensions
const int virtual_width = 1600;
const int virtual_height = 900;

int main(void) {
  InitWindow(window_width, window_height, window_title);
  SetWindowState(FLAG_WINDOW_RESIZABLE);
  SetTargetFPS(120);
  Color virtual_screen_bg = {80, 80, 80, 255};

  while (!WindowShouldClose()) {
    float screen_width = GetScreenWidth();
    float screen_height = GetScreenHeight();
    
    // Calculate scaling and position
    float scale = fminf(screen_width/virtual_width, screen_height/virtual_height);
    int render_width = virtual_width * scale;
    int render_height = virtual_height * scale;
    int pos_x = (screen_width - render_width) / 2;
    int pos_y = (screen_height - render_height) / 2;

    BeginDrawing();
    ClearBackground(BLACK);

    Camera2D camera = {
      .offset = (Vector2){pos_x, pos_y},
      .target = (Vector2){0, 0},
      .rotation = 0.0f,
      .zoom = scale
    };

    BeginMode2D(camera);
    
    DrawRectangle(0, 0, virtual_width, virtual_height, virtual_screen_bg);
    
    DrawText("Virtual Screen Content", 200, 200, 40, WHITE);
    DrawCircle(virtual_width/2, virtual_height/2, 200, RED);
    DrawText(TextFormat("Virtual: %dx%d", virtual_width, virtual_height), 10, 10, 50, GREEN);
    DrawText(TextFormat("Window: %dx%d", (int)screen_width, (int)screen_height), 10, 70, 50, PURPLE);
    DrawRectangleLines(0, 0, virtual_width, virtual_height, WHITE);
    
    EndMode2D();
    DrawFPS(10, 10);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
