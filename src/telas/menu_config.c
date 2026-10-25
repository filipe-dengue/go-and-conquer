#include "raylib.h"
#include "telas.h"
#include "utils.h"

#include "raygui.h"
#include <stdio.h>
#include <string.h>

void draw_menu_preferencias(EstadoGame *estado){
    static int selecao_combo_box_antigo = 0;
    static int selecao_combo_box = 0;

    static Rectangle layoutRecs[6] = {
        (Rectangle){ 24, 24, 384, 648 },
        (Rectangle){ 432, 24, 824, 648 },
        (Rectangle){ 48, 72, 336, 48 },
        (Rectangle){ 48, 48, 48, 16 },
        (Rectangle){ 96, 48, 280, 16 },
        (Rectangle){ 48, 600, 336, 48 },
    };

    static const char opcoes_temas[] = "Default;Jungle;Terminal;Advance;Amber;Ashes;Bluish;Brick;Candy;Cherry;Cyber;Dark;Enefete;Genesis;Lavanda;Pocket;Rltech;Sunny;Turbo;Wisteria";

    GuiGroupBox(layoutRecs[0], "OPÇÕES");
    GuiGroupBox(layoutRecs[1], NULL);
    GuiLabel(layoutRecs[3], "TEMAS");
    GuiLine(layoutRecs[4], NULL);

    GuiComboBox(layoutRecs[2], opcoes_temas, &selecao_combo_box);

    if(selecao_combo_box != selecao_combo_box_antigo){
        char caminho_temas[150] = "raylib/raygui/styles/";
        const char nomes_temas[][10] = {
            "default",
            "jungle",
            "terminal",
            "advance",
            "amber",
            "ashes",
            "bluish",
            "brick",
            "candy",
            "cherry",
            "cyber",
            "dark",
            "enefete",
            "genesis",
            "lavanda",
            "pocket",
            "rltech",
            "sunny",
            "turbo",
            "wisteria"
        };

        if(strcmp(nomes_temas[selecao_combo_box], "default") == 0){
            GuiLoadStyleDefault();
        }else{
            // Resolve problema de vazamento de mémoria da biblioteca
            UnloadFont(GuiGetFont());

            sprintf(caminho_temas, "%s%s/style_%s.rgs", caminho_temas, nomes_temas[selecao_combo_box], nomes_temas[selecao_combo_box]);

            GuiLoadStyle(caminho_temas);
        }

        selecao_combo_box_antigo = selecao_combo_box;
    }

    if(GuiButton(layoutRecs[5], "VOLTAR")){
        estado->atual = TELA_MENU;
    }
}
