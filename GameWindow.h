#pragma once
#include "global.h"
#include "farmer_hall.h"
#include "scene.h"
#include "charater.h"
#include"scene.h"
#include"cow.h"
#include"mower.h"
#include"dart.h"
#include"arrow.h"

int Game_establish();
void game_init();
void game_begin();
void game_update();
int process_event();
void game_draw();
int game_run();
void game_destroy();
