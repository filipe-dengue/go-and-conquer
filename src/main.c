#include "telas.h"
#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include "utils.h"
#include "save_and_load.h"

Menu_Nacoes_Data menu_nacoes_data = {0};

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
                case INIT_EDITOR_NACOES: 
                    menu_nacoes_data.nacoes_vec = carregar_nacao();
                    printar_nacoes(menu_nacoes_data.nacoes_vec);
                    estado.atual = TELA_EDITOR_NACOES;
                    break;

                case TELA_PREFERENCIAS: draw_menu_preferencias(&estado); break;

                case TELA_EDITOR_NACOES: draw_menu_nacoes(&estado); break;

                case SAIR_EDITOR_NACOES: 
                    limpar_vec_nacoes(&menu_nacoes_data.nacoes_vec); 
                    estado.atual = TELA_MENU;
                    break;

                default: fechar_janela = draw_menu_principal(&estado); break;
            }

        EndDrawing();

        //printf("%ld\n", sizeof(Nacao));
    }

    CloseWindow();
    return 0;
}
