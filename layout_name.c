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
    bool BtnJogarPressed = false;
    bool BtnEditorPressed = false;
    bool BtnConfigPressed = false;
    bool BtnSairPressed = false;
    bool Button008Pressed = false;

    Rectangle layoutRecs[8] = {
        (Rectangle){ 192, 184, 384, 96 },
        (Rectangle){ 24, 152, 384, 520 },
        (Rectangle){ 432, 24, 816, 648 },
        (Rectangle){ 48, 176, 336, 72 },
        (Rectangle){ 216, 424, 336, 72 },
        (Rectangle){ 48, 464, 336, 72 },
        (Rectangle){ 48, 560, 336, 72 },
        (Rectangle){ 48, 368, 336, 72 },
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
            GuiGroupBox(layoutRecs[0], NULL);
            GuiGroupBox(layoutRecs[1], "MENU");
            GuiGroupBox(layoutRecs[2], NULL);
            BtnJogarPressed = GuiButton(layoutRecs[3], "JOGAR"); 
            BtnEditorPressed = GuiButton(layoutRecs[4], "EDITOR MAPAS"); 
            BtnConfigPressed = GuiButton(layoutRecs[5], "PREFERÊNCIAS"); 
            BtnSairPressed = GuiButton(layoutRecs[6], "SAIR"); 
            Button008Pressed = GuiButton(layoutRecs[7], "EDITOR NAÇÕES"); 
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

