#include "dart.h"
// the state of character

ALLEGRO_SAMPLE *acow_sound = NULL;
ALLEGRO_SAMPLE *asheep_sound = NULL;
ALLEGRO_SAMPLE *achicken_sound = NULL;


enum {STOP = 0, MOVE};//enum 後面這坨從０開始計數 move從1開始，stop從0開始
typedef struct dart
{
    int x, y; // the position of image
    int width, height; // the width and height of image
    bool dir; // left: false, right: true
    int state; // the state of character
    ALLEGRO_BITMAP *img_move[1];
    int anime; // counting the time of animation
    int anime_time; // indicate how long the animation
    bool live;
    bool touch;
    ALLEGRO_SAMPLE_INSTANCE *Sound;
}dart;
dart drt;
ALLEGRO_SAMPLE * Q_sample = NULL;
void dart_init(){
    // load character images

    acow_sound = al_load_sample("./sound/1.wav");
    asheep_sound = al_load_sample("./sound/3.wav");
    achicken_sound = al_load_sample("./sound/5.wav");

    if(scenemode==1){
        drt.Sound  = al_create_sample_instance(acow_sound);
    }
    if(scenemode==3){
        drt.Sound = al_create_sample_instance(asheep_sound);
    }
    if(scenemode==5){
        drt.Sound  = al_create_sample_instance(achicken_sound);
    }
    al_set_sample_instance_playmode( drt.Sound, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer( drt.Sound, al_get_default_mixer());

    char temp[50];
    sprintf( temp, "./image/dart_move%d.png", 1 );
    drt.img_move[0] = al_load_bitmap(temp);
    printf("%p", drt.img_move[0]);

    // initial the geometric information of character
    drt.width = al_get_bitmap_width(drt.img_move[0]);
    drt.height = al_get_bitmap_height(drt.img_move[0]);
    drt.x = 550;
    drt.y = 680;
    drt.dir = false;
    drt.live = true;

    // initial the animation component
    drt.state = STOP;
    drt.anime = 0;
    drt.anime_time = 30;
    drt.touch = false;

}
void dart_process(ALLEGRO_EVENT event){
    // process the animation
    if( event.type == ALLEGRO_EVENT_TIMER ){
        if( event.timer.source == fps ){
            drt.anime++;
            drt.anime %= drt.anime_time;
        }
    // process the keyboard event
    }else if( event.type == ALLEGRO_EVENT_KEY_DOWN ){
        key_state[event.keyboard.keycode] = true;
        drt.anime = 0;
    }else if( event.type == ALLEGRO_EVENT_KEY_UP ){
        key_state[event.keyboard.keycode] = false;
    }
}
void dart_destroy(){
    al_destroy_bitmap(drt.img_move[0]);
}

void dart_isCollided(int targetX, int targetY, int s) {
    if (abs(drt.x - targetX) < s && abs(drt.y - targetY) < s){
        drt.touch = true;
        drt.x = 1890;
        al_play_sample_instance(drt.Sound);
    }
}

void dart_update(){
    drt.dir = chara_direction;
    if(dart_fire == true){
        drt.x += 20;
        drt.state = MOVE;
        if (drt.x >= 1890 ){ 
            drt.state = STOP;
            dart_fire = false;
            drt.x = 550;
            drt.y = 680;
            if(drt.touch == true){
                if(scenemode == 1){
                    add_beef++;
                }
                if(scenemode == 3){
                    add_sheep++;
                }
                if(scenemode == 5){
                    add_chicken++;
                }
            }
            drt.touch = false;
        }
        //printf("%d %d %d %d\n", drt.x, drt.y, cow_x_coord, cow_y_coord);
        dart_isCollided(cow_x_coord,cow_y_coord, 100);
        dart_isCollided(cow2_x_coord,cow2_y_coord, 100);
        dart_isCollided(cow3_x_coord,cow3_y_coord, 100);
        //dart_isCollided(cow3_x_coord,cow3_y_coord, 100);
        al_rest(0.001);
    }
}
void dart_draw(){
    al_draw_bitmap(drt.img_move[0], drt.x, drt.y, 0);
}