#include "telas.h"

#include "raylib.h"
#include "raygui.h"
#include "utils.h"
#include <string.h>

void draw_menu_nacoes(EstadoGame *estado){
    static Rectangle layoutRecs[] = {
        (Rectangle){ 24, 24, 384, 648 },
        (Rectangle){ 432, 24, 824, 648 },
        (Rectangle){ 864, 376, 360, 48 },
        (Rectangle){ 48, 120, 336, 24 },
        (Rectangle){ 456, 48, 240, 144 },
        (Rectangle){ 456, 216, 192, 264 },
        (Rectangle){ 728, 48, 96, 24 },
        (Rectangle){ 864, 48, 360, 24 },
        (Rectangle){ 728, 96, 88, 24 },
        (Rectangle){ 864, 96, 360, 24 },
        (Rectangle){ 728, 144, 112, 24 },
        (Rectangle){ 864, 144, 360, 24 },
        (Rectangle){ 728, 192, 120, 24 },
        (Rectangle){ 864, 192, 360, 24 },
        (Rectangle){ 728, 240, 120, 24 },
        (Rectangle){ 864, 240, 336, 104 },
        (Rectangle){ 24, 40, 384, 648 },
    };

    static bool txb_nomeEditMode;
    static char txb_nomeText[MAX_STRING] = "";
    static bool txb_lider_EditMode = false;
    static char txb_lider_Text[MAX_STRING] = "";
    static bool txb_bandeira_EditMode = false;
    static char txb_bandeira_Text[MAX_STRING] = "";
    static bool txb_png_lider_EditMode = false;
    static char txb_png_lider_Text[MAX_STRING] = "";
    static Color cor_pais = { 0, 0, 0, 0 };
    static Rectangle Sp_ScrollView = { 0, 0, 0, 0 };
    static Vector2 Sp_ScrollOffset = { 0, 0 };
    static Vector2 Sp_BoundsOffset = { 0, 0 };
    static int id = -1;

    // Offset entre botões y += 12
    static Rectangle btns_rec = (Rectangle){ 48, 64, 336, 24 };

    static int y = 200;
    GuiScrollPanel((Rectangle){layoutRecs[16].x, layoutRecs[16].y, layoutRecs[16].width - Sp_BoundsOffset.x, layoutRecs[16].height - Sp_BoundsOffset.y }, NULL, (Rectangle){btns_rec.x, btns_rec.y, btns_rec.width, y - btns_rec.y},  &Sp_ScrollOffset,  &Sp_ScrollView);

    //GuiGroupBox(layoutRecs[0], "NAÇÕES");
    GuiGroupBox(layoutRecs[1], NULL);

    y = btns_rec.y + Sp_ScrollOffset.y;
    #define OFSSET_BTN 12

    BeginScissorMode(layoutRecs[16].x + 12, layoutRecs[16].y, layoutRecs[16].width, layoutRecs[16].height - 12);

    // Btn nova nação
    if(GuiButton((Rectangle){btns_rec.x, y, btns_rec.width, btns_rec.height * 2}, "CRIAR NOVA NAÇÃO")){
        strcpy(txb_nomeText, "");
        strcpy(txb_lider_Text, "");
        strcpy(txb_bandeira_Text, "");
        strcpy(txb_png_lider_Text, "");
        id = -1;
    }
    y +=  btns_rec.height * 2 + OFSSET_BTN;

    // Btn voltar
    if(GuiButton((Rectangle){btns_rec.x, y, btns_rec.width, btns_rec.height * 2}, "VOLTAR")){
        estado->atual = TELA_MENU;
    }
    y +=  btns_rec.height * 2 + OFSSET_BTN;

    // Outros btns
    for(int i = 0; i < 30; i++){
        GuiButton((Rectangle){btns_rec.x, y, btns_rec.width, btns_rec.height}, "TESTE");
        y += btns_rec.height + OFSSET_BTN;
    }

    y += btns_rec.height;

    EndScissorMode();

    GuiPanel(layoutRecs[4], NULL);
    GuiPanel(layoutRecs[5], NULL);

    GuiLabel(layoutRecs[6], "NOME:");
    if (GuiTextBox(layoutRecs[7], txb_nomeText, MAX_STRING, txb_nomeEditMode)) txb_nomeEditMode = !txb_nomeEditMode;

    GuiLabel(layoutRecs[8], "LIDER:");
    if (GuiTextBox(layoutRecs[9], txb_lider_Text, MAX_STRING, txb_lider_EditMode)) txb_lider_EditMode = !txb_lider_EditMode;

    GuiLabel(layoutRecs[10], "CAMINHO BANDEIRA:");
    if (GuiTextBox(layoutRecs[11], txb_bandeira_Text, MAX_STRING, txb_bandeira_EditMode)) txb_bandeira_EditMode = !txb_bandeira_EditMode;

    GuiLabel(layoutRecs[12], "CAMINHO PNG LIDER:");
    if (GuiTextBox(layoutRecs[13], txb_png_lider_Text, MAX_STRING, txb_png_lider_EditMode)) txb_png_lider_EditMode = !txb_png_lider_EditMode;

    GuiLabel(layoutRecs[14], "COR:");
    GuiColorPicker(layoutRecs[15], NULL, &cor_pais);

    GuiButton(layoutRecs[2], "SALVAR");
}
