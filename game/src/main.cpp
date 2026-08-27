#include <raylib.h>
#include <cmath>

//temporal
#include "camera.hpp"
#include "raycasting.hpp"


constexpr int BASE_W = 800;
constexpr int BASE_H = 600; 

int main(){
    int width = 400;
    int height = 300;

    float max_distance = 24;

    InitWindow(BASE_W, BASE_H, "RayCasting");
    SetTargetFPS(60);

    EngineCamera cam;
    cam.SetPosition({5, 3});
    cam.Rotate(PI/2);

    float speed = 5.0f;

    RenderRayCaster ray;


    RenderTexture2D canvas = LoadRenderTexture(width, height);
    SetTextureFilter(canvas.texture, TEXTURE_FILTER_POINT);

    while (!WindowShouldClose()){
        float dt = GetFrameTime();

        //input
        if (IsKeyDown(KEY_W)){
            cam.MoveForward(speed*dt);
        }
        if (IsKeyDown(KEY_A)){
            cam.MoveRight(-speed*dt);
        }
        if (IsKeyDown(KEY_S)){
            cam.MoveForward(-speed*dt);
        }
        if (IsKeyDown(KEY_D)){
            cam.MoveRight(speed*dt);
        }
        if (IsKeyDown(KEY_LEFT)){
            cam.Rotate(speed * dt);
        }
        if (IsKeyDown(KEY_RIGHT)){
            cam.Rotate(-speed * dt);
        }


        BeginTextureMode(canvas);
        ClearBackground(BLACK);

        for (int i = 0; i < width; i++){
            float cameraX = 2.0 * i / width - 1.0;

            vector2f direction = cam.forward + ((cam.right * (PI/4)) * cameraX);

            direction = direction.normalize();

            RayResult result = ray.Cast(cam.GetPosition(), direction, max_distance);
            
            Color color = BLACK;
            switch (result.side)
            {
            case 0:
                color = GREEN;
                break;
            case 1:
                color = PINK;
                break;
            case 2:
                color = DARKBLUE;
                break;
            case 3:
                color = YELLOW;
                break;
            default:
                break;
            }

            if (result.hit_blocked && result.distance > 0){
                
                float distance = result.distance * (direction.dot(cam.forward));

                int line_height = (int)(height / distance);

                int draw_start = -line_height / 2 + height / 2;
                int draw_end   =  line_height / 2 + height / 2;

                if (draw_start < 0) draw_start = 0;
                if (draw_end >= height) draw_end = height - 1;

                float shade = distance / max_distance - 0.2; 

                if (shade > 1) shade = 1;
                else if (shade < 0) shade = 0;


                DrawLine(i, draw_start, i, draw_end, ColorLerp(color, BLACK, shade));
            }

            
        }

        EndTextureMode();

        Rectangle src = {0, 0, (float)width, -(float) height};
        Rectangle dest = {0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()};


        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexturePro(canvas.texture, src, dest, {0, 0}, 0, WHITE);
        EndDrawing();
    }
}