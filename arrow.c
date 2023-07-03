#include "arrow.h"
// the state of character
ALLEGRO_SAMPLE *cow_sound = NULL;
ALLEGRO_SAMPLE *sheep_sound = NULL;
ALLEGRO_SAMPLE *chicken_sound = NULL;

enum {STOP = 0, MOVE};//enum 後面這坨從０開始計數 move從1開始，stop從0開始
typedef struct arrow
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
}arrow;
arrow arw;
ALLEGRO_SAMPLE * R_sample = NULL;
void arrow_init(){
    // load character images

    cow_sound = al_load_sample("./sound/1.wav");
    sheep_sound = al_load_sample("./sound/3.wav");
    chicken_sound = al_load_sample("./sound/5.wav");

    if(scenemode==1){
        arw.Sound  = al_create_sample_instance(cow_sound);
    }
    if(scenemode==3){
        arw.Sound  = al_create_sample_instance(sheep_sound);
    }
    if(scenemode==5){
        arw.Sound  = al_create_sample_instance(chicken_sound);
    }
    al_set_sample_instance_playmode( arw.Sound, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer( arw.Sound, al_get_default_mixer());

    char temp[50];
    sprintf( temp, "./image/arrow_move%d.png", 1 );
    arw.img_move[0] = al_load_bitmap(temp);
    printf("%p", arw.img_move[0]);

    // initial the geometric information of character
    arw.width = al_get_bitmap_width(arw.img_move[0]);
    arw.height = al_get_bitmap_height(arw.img_move[0]);
    arw.x = 200;
    arw.y = 1050;
    arw.dir = false;
    arw.live = true;

    // initial the animation component
    arw.state = STOP;
    arw.anime = 0;
    arw.anime_time = 30;
    arw.touch = false;

}
void arrow_process(ALLEGRO_EVENT event){
    // process the animation
    if( event.type == ALLEGRO_EVENT_TIMER ){
        if( event.timer.source == fps ){
            arw.anime++;
            arw.anime %= arw.anime_time;
        }
    // process the keyboard event
    }else if( event.type == ALLEGRO_EVENT_KEY_DOWN ){
        key_state[event.keyboard.keycode] = true;
        arw.anime = 0;
    }else if( event.type == ALLEGRO_EVENT_KEY_UP ){
        key_state[event.keyboard.keycode] = false;
    }
}
void arrow_destroy(){
    al_destroy_bitmap(arw.img_move[0]);
}
void arrow_isCollided(int targetX, int targetY, int s) {
    if (abs(arw.x - targetX) < s && abs(arw.y - targetY) < s){
        arw.touch = true;
        arw.x = 1890;
        al_play_sample_instance(arw.Sound);
    }
}
void arrow_update(){
    arw.dir = chara_direction;
    if(arrow_fire == true){
        arw.x += 30;
        arw.state = MOVE;
        if (arw.x >= 1890 ){ 
            arw.state = STOP;
            arrow_fire = false;
            arw.x = 200;
            arw.y = 1050;
            if(arw.touch == true){
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
            arw.touch = false;
            //printf("score_beef = %d", score_beef);
        }
        arrow_isCollided(cow_x_coord, cow_y_coord, 300);
        arrow_isCollided(cow2_x_coord, cow2_y_coord, 300);
        arrow_isCollided(cow3_x_coord, cow3_y_coord, 300);
        al_rest(0.001);
    }
}
void arrow_draw(){
    al_draw_bitmap(arw.img_move[0], arw.x, arw.y, 0);
}