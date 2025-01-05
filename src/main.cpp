#include <raylib.h>

Vector2 GetRandomPos() {
    float x = static_cast<float>(GetRandomValue(0, GetScreenWidth() - 1));
    float y = static_cast<float>(GetRandomValue(0, GetScreenHeight() - 1));
    return Vector2{x, y};
}

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Bouncing Ball");
    SetExitKey(KEY_ESCAPE);

    Vector2 ballPos = GetRandomPos();
    Vector2 ballSpeed = {300.0f, 300.0f};
    float ballRadius = 15.0f;

    while (!WindowShouldClose()) {
        float Δtime = GetFrameTime(); // Δ is the symbol for delta in mathematics :)

        ballPos.x += ballSpeed.x * Δtime;
        ballPos.y += ballSpeed.y * Δtime;

        if (ballPos.x + ballRadius >= screenWidth || ballPos.x - ballRadius <= 0) {
            ballSpeed.x *= -1;
        }

        if (ballPos.y + ballRadius >= screenHeight || ballPos.y - ballRadius <= 0) {
            ballSpeed.y *= -1;
        }

        BeginDrawing();
        ClearBackground(BLACK);
        DrawCircleV(ballPos, ballRadius, WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
