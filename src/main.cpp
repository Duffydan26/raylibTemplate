#include <raylib.h>

int main(){
    
    const int screenWidth = 800;
    const int screenHeight = 600;
    Vector2 ballPos = {100.0f, 100.0f};
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