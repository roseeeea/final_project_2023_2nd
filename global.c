#include "global.h"

// variables for global usage
const float FPS = 60.0;
const int WIDTH = 1890;
const int HEIGHT = 1417;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *fps = NULL;
bool key_state[ALLEGRO_KEY_MAX] = {false};
bool judge_next_window = false;
int changewindow=0;

int score_chicken=30;
int score_sheep=30;
int score_beef=30;

int add_chicken=0;
int add_sheep=0;
int add_beef=0;

bool chara_direction = false;
bool mower_fire = false;
bool dart_fire = false;
bool arrow_fire = false;
int cow_x_coord;
int cow_y_coord;
int cow2_x_coord;
int cow2_y_coord;
int cow3_x_coord;
int cow3_y_coord;

int scenemode=0;



