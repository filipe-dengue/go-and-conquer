#include "telas.h"
#include "utils.h"

#include "raylib.h"
#include "raygui.h"

// retorma se a janela deve ser fechada
bool draw_menu_principal(EstadoGame *estado){

    // Defini posição de cada objeto
    static Rectangle layoutRecs[8] = {
        (Rectangle){ 0, 0, 1280, 720 },
        (Rectangle){ 24, 25, 264, 119 },
        (Rectangle){ 24, 168, 264, 528 },
        (Rectangle){ 312, 25, 936, 671 },
        (Rectangle){ 48, 192, 216, 72 },
        (Rectangle){ 48, 288, 216, 72 },
        (Rectangle){ 48, 384, 216, 72 },
        (Rectangle){ 48, 480, 216, 72 },
    };

    // Faz o desenho
    GuiGroupBox(layoutRecs[1], NULL);
    GuiGroupBox(layoutRecs[2], "MENU");
    GuiGroupBox(layoutRecs[3], NULL);

    GuiButton(layoutRecs[4], "JOGAR");
    GuiButton(layoutRecs[5], "EDITOR");
    if(GuiButton(layoutRecs[6], "PREFERÊNCIAS")){
        estado->atual = TELA_PREFERENCIAS;
    }

    if(GuiButton(layoutRecs[7], "SAIR")){
        return true;
    }

    return false;
}
