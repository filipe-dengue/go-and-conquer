#include "telas.h"
#include "raylib.h"
#include <stdio.h>

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include "utils.h"

int main()
{
    InitWindow(1280, 720, "Go and Conquer! - By Dengue Schausst");
    SetTargetFPS(60);

    EstadoGame estado = { 0 };
    bool fechar_janela = false;

    while (!WindowShouldClose() && !fechar_janela)
    {
        BeginDrawing();
            ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

            switch (estado.atual) {
                case TELA_PREFERENCIAS: draw_menu_preferencias(&estado); break;

                case TELA_EDITOR_NACOES: draw_menu_nacoes(&estado); break;

                default: fechar_janela = draw_menu_principal(&estado); break;
            }

        EndDrawing();

        //printf("%ld\n", sizeof(Nacao));
    }

    CloseWindow();
    return 0;
}
