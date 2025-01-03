#include <raylib.h>
#include <ctime>

int main(){

    SetRandomSeed(static_cast<unsigned int>(time(nullptr)));
    
    const int screenWidth = 800;
    const int screenHeight = 600;
    Vector2 ballPos = {static_cast<float>(GetRandomValue(4, 700)), static_cast<float>(GetRandomValue(4, 500))};
    Vector2 ballSpeed = {300.0f, 300.0f};
    int ballRadius = 15;

    InitWindow(screenWidth, screenHeight, "Template");
    SetExitKey(KEY_ESCAPE);

    while (!WindowShouldClose()){
        float dt = GetFrameTime();

        BeginDrawing();
        ClearBackground(BLACK);

        ballPos.x += ballSpeed.x * dt;
        ballPos.y += ballSpeed.y * dt;

        if(ballPos.x + ballRadius >= screenWidth || ballPos.x - ballRadius <= 0){
            ballSpeed.x *= -1;
        };
        
        if(ballPos.y + ballRadius >= screenHeight || ballPos.y - ballRadius <= 0){
            ballSpeed.y *= -1;
        };

        DrawCircleV(ballPos, ballRadius, WHITE);
        EndDrawing();
        
    }

    CloseWindow();
    return 0;
}