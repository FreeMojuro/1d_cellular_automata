#include <array>
#include <memory>
#include <raylib.h>
#include "rules.hpp"

bool paused{false};

int main(){
    InitWindow(window_width, window_height, "");
    SetTargetFPS(120);
    
    std::array<Cell, window_width/cell_size> neighborhood;

    neighborhood[0].state = 1;
    neighborhood[neighborhood.size()-1].state = 1;
    for(int i{1}; i < neighborhood.size()-1; ++i){
        neighborhood[i].state = GetRandomValue(0, 1);
    }
    

    RenderTexture2D target = LoadRenderTexture(window_width, window_height);
    BeginTextureMode(target);
        ClearBackground(WHITE);
    EndTextureMode();

    static int ypos = 0;
    while(!WindowShouldClose()){ 

        if(IsKeyPressed(KEY_SPACE))paused=!paused;
        for(int i{0}; i < num_presets;++i){
            if(IsKeyPressed(KEY_ZERO+i)) current_preset = i;
        }

        auto new_neighborhood = std::make_unique<std::array<Cell, window_width/cell_size>>();
        if(!paused){
        for(int i{0}; i < neighborhood.size(); ++i){
            const Cell& currentcell = neighborhood[i];
            const Cell& leftcell = neighborhood[((i-1) + neighborhood.size()) % neighborhood.size()];
            const Cell& rightcell = neighborhood[((i+1) + neighborhood.size()) % neighborhood.size()];
            Check(i,leftcell, currentcell, rightcell,new_neighborhood);


        }}

        BeginDrawing();
        ClearBackground(BLACK);
        DrawTextureRec(target.texture, (Rectangle){ 0, 0, (float)target.texture.width, (float)-target.texture.height }, (Vector2){ 0, 0 }, WHITE);
        
        BeginTextureMode(target);
        for(int i{0}; i < neighborhood.size(); ++i){
            if(!paused){
            Color col = (neighborhood[i].state == 1) ? WHITE : BLACK;    
            DrawRectangle(cell_size*i, ypos, cell_size, cell_size, col);
            }
            
        }
        EndTextureMode();
        EndDrawing();

        if(ypos == window_height)ypos=0;

        if(!paused){
        ypos+=cell_size;
        neighborhood = *new_neighborhood;}

    }
    CloseWindow();
    return 0;
}
