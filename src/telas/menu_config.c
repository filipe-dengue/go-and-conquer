#include "raylib.h"
#include "telas.h"
#include "utils.h"

#include "raygui.h"
#include <stdio.h>
#include <string.h>

void draw_menu_preferencias(EstadoGame *estado){
    static int selecao_combo_box_antigo = 0;
    int selecao_combo_box = selecao_combo_box_antigo;

    static const Rectangle layoutRecs[4] = {
        (Rectangle){ 24, 16, 128, 16 },
        (Rectangle){ 144, 16, 1096, 16 },
        (Rectangle){ 24, 48, 1224, 48 },
        (Rectangle){ 528, 648, 192, 48 },
    };

    static const char opcoes_temas[] = "Default;Jungle;Terminal;Advance;Amber;Ashes;Bluish;Brick;Candy;Cherry;Cyber;Dark;Enefete;Genesis;Lavanda;Pocket;Rltech;Sunny;Turbo;Wisteria";

    GuiLabel(layoutRecs[0], "Preferências Visuais");
    GuiLine(layoutRecs[1], NULL);
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

    if(GuiButton(layoutRecs[3], "VOLTAR")){
        estado->atual = TELA_MENU;
    }
}
