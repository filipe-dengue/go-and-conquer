#pragma once
#include "utils.h"
#include "game_struct.h"

typedef struct
{
    Nacao_vec nacoes_vec;
}Menu_Nacoes_Data;


bool draw_menu_principal(EstadoGame *estado);
void draw_menu_preferencias(EstadoGame *estado);
void draw_menu_nacoes(EstadoGame *estado);
