#pragma once
#include "global.h"
#include "farmer_hall.h"
#include "charater.h"
#include "cow.h"
#include "mower.h"
#include "dart.h"
#include "arrow.h"

void menu_init();
void menu_process(ALLEGRO_EVENT event);
void menu_draw();
void menu_destroy();

void game_scene_init();
void game_scene_process();
void game_scene_draw();
void game_scene_destroy();

void game_barn1_init();
void game_barn1_process();
void game_barn1_draw();
void game_barn1_destroy();

void game_barn2_init();
void game_barn2_process();
void game_barn2_draw();
void game_barn2_destroy();

void game_barn3_init();
void game_barn3_process();
void game_barn3_draw();
void game_barn3_destroy();

void game_end_init();;
void game_end_draw();
void game_end_process();
void game_end_destroy();

void game_limit_init();
void game_limit_draw();
void game_limit_process();
void game_limit_destroy();

void game_introduction_init();
void game_introduction_draw();
void game_introduction_process();
void game_introduction_destroy();


int food_flag;



