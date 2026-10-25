#include "menu_principal.h"
#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include "utils.h"

int main()
{
    InitWindow(1280, 720, "Go and Conquer! - By Dengue Schausst");
    SetTargetFPS(60);

    EstadoGame estado = { 0 };

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

            switch (estado.atual) {
                default: draw_menu_principal(&estado); break;
            }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
