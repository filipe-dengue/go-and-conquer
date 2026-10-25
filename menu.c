/*******************************************************************************************
*
*   LayoutName v1.0.0 - Tool Description
*
*   LICENSE: Propietary License
*
*   Copyright (c) 2022 raylib technologies. All Rights Reserved.
*
*   Unauthorized copying of this file, via any medium is strictly prohibited
*   This project is proprietary and confidential unless the owner allows
*   usage in any other form by expresely written permission.
*
**********************************************************************************************/

#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

//----------------------------------------------------------------------------------
// Controls Functions Declaration
//----------------------------------------------------------------------------------


//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //---------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "layout_name");

    // layout_name: controls initialization
    //----------------------------------------------------------------------------------
    bool WindowBox000Active = true;
    bool BtnJogarPressed = false;
    bool BtnEditorPressed = false;
    bool BtnConfigPressed = false;
    bool BtnSairPressed = false;

    Rectangle layoutRecs[8] = {
        (Rectangle){ 0, 0, 1280, 720 },
        (Rectangle){ 24, 48, 264, 96 },
        (Rectangle){ 24, 168, 264, 528 },
        (Rectangle){ 312, 48, 936, 648 },
        (Rectangle){ 48, 192, 216, 72 },
        (Rectangle){ 48, 288, 216, 72 },
        (Rectangle){ 48, 384, 216, 72 },
        (Rectangle){ 48, 480, 216, 72 },
    };
    //----------------------------------------------------------------------------------

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Implement required update logic
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR))); 

            // raygui: controls drawing
            //----------------------------------------------------------------------------------
            if (WindowBox000Active)
            {
                WindowBox000Active = !GuiWindowBox(layoutRecs[0], "SAMPLE TEXT");
                GuiGroupBox(layoutRecs[2], "MENU");
                GuiGroupBox(layoutRecs[3], NULL);
                BtnJogarPressed = GuiButton(layoutRecs[4], "JOGAR"); 
                BtnEditorPressed = GuiButton(layoutRecs[5], "EDITOR"); 
                BtnConfigPressed = GuiButton(layoutRecs[6], "PREFERÊNCIAS"); 
                BtnSairPressed = GuiButton(layoutRecs[7], "SAIR"); 
            }
            GuiGroupBox(layoutRecs[1], NULL);
            //----------------------------------------------------------------------------------

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

//------------------------------------------------------------------------------------
// Controls Functions Definitions (local)
//------------------------------------------------------------------------------------

