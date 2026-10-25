#include "telas.h"
#include "utils.h"

#include "raylib.h"
#include "raygui.h"

// retorma se a janela deve ser fechada
bool draw_menu_principal(EstadoGame *estado){

    // Defini posição de cada objeto
    static Rectangle layoutRecs[8] = {
        (Rectangle){ 24, 24, 384, 96 },
        (Rectangle){ 24, 152, 384, 520 },
        (Rectangle){ 432, 24, 816, 648 },
        (Rectangle){ 48, 176, 336, 72 },
        (Rectangle){ 48, 272, 336, 72 },
        (Rectangle){ 48, 464, 336, 72 },
        (Rectangle){ 48, 560, 336, 72 },
        (Rectangle){ 48, 368, 336, 72 },
    };

    // Faz o desenho
    GuiGroupBox(layoutRecs[0], NULL);
    GuiGroupBox(layoutRecs[1], "MENU");
    GuiGroupBox(layoutRecs[2], NULL);

    GuiButton(layoutRecs[3], "JOGAR");
    GuiButton(layoutRecs[4], "EDITOR MAPAS");
    GuiButton(layoutRecs[7], "EDITOR NAÇÕES");

    if(GuiButton(layoutRecs[5], "PREFERÊNCIAS")){
        estado->atual = TELA_PREFERENCIAS;
    }

    if(GuiButton(layoutRecs[6], "SAIR")){
        return true;
    }

    return false;
}
