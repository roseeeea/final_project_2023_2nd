#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED
#define GAME_TERMINATE -1
#include <stdio.h>
#include <allegro5/allegro.h>
#pragma once
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#define debug(x) if (x){printf("check at line number %d in file %s\n",__LINE__, __FILE__);}

// note that you can't assign initial value here!
extern const float FPS;
extern const int WIDTH;
extern const int HEIGHT;
extern int changewindow;
extern bool key_state[ALLEGRO_KEY_MAX];
extern bool judge_next_window;
extern ALLEGRO_EVENT_QUEUE *event_queue;
extern ALLEGRO_TIMER *fps;

extern int score_chicken;
extern int score_beef;
extern int score_sheep;

extern int add_beef;
extern int add_chicken;
extern int add_sheep;

extern bool chara_direction;
extern bool mower_fire;
extern bool dart_fire;
extern bool arrow_fire;
extern int cow_x_coord;
extern int cow_y_coord;
extern int cow2_x_coord;
extern int cow2_y_coord;
extern int cow3_x_coord;
extern int cow3_y_coord;

extern int scenemode;

#endif


