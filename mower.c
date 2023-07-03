#include "mower.h"
// the state of character
ALLEGRO_SAMPLE *bcow_sound = NULL;
ALLEGRO_SAMPLE *bsheep_sound = NULL;
ALLEGRO_SAMPLE *bchicken_sound = NULL;

enum {STOP = 0, MOVE};//enum 後面這坨從０開始計數 move從1開始，stop從0開始
typedef struct mower
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
}mower;
mower mow;
ALLEGRO_SAMPLE * W_sample = NULL;
void mower_init(){
    // load character images

    bcow_sound = al_load_sample("./sound/1.wav");
    bsheep_sound = al_load_sample("./sound/3.wav");
    bchicken_sound = al_load_sample("./sound/5.wav");

    if(scenemode==1){
        mow.Sound  = al_create_sample_instance(bcow_sound);
    }
    if(scenemode==3){
        mow.Sound  = al_create_sample_instance(bsheep_sound);
    }
    if(scenemode==5){
        mow.Sound  = al_create_sample_instance(bchicken_sound);
    }
    al_set_sample_instance_playmode( mow.Sound, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer( mow.Sound, al_get_default_mixer());

    char temp[50];
    sprintf( temp, "./image/mower_move%d.png", 1 );
    mow.img_move[0] = al_load_bitmap(temp);
    printf("%p", mow.img_move[0]);

    // initial the geometric information of character
    mow.width = al_get_bitmap_width(mow.img_move[0]);
    mow.height = al_get_bitmap_height(mow.img_move[0]);
    mow.x = 240;
    mow.y = 180;
    mow.dir = false;
    mow.live = true;

    // initial the animation component
    mow.state = STOP;
    mow.anime = 0;
    mow.anime_time = 30;
    mow.touch = false;

}
void mower_process(ALLEGRO_EVENT event){
    // process the animation
    if( event.type == ALLEGRO_EVENT_TIMER ){
        if( event.timer.source == fps ){
            mow.anime++;
            mow.anime %= mow.anime_time;
        }
    // process the keyboard event
    }else if( event.type == ALLEGRO_EVENT_KEY_DOWN ){
        key_state[event.keyboard.keycode] = true;
        mow.anime = 0;
    }else if( event.type == ALLEGRO_EVENT_KEY_UP ){
        key_state[event.keyboard.keycode] = false;
    }
}
void mower_destroy(){
    al_destroy_bitmap(mow.img_move[0]);
}
void mower_isCollided(int targetX, int targetY, int s) {
    if (abs(mow.x - targetX) < s && abs(mow.y - targetY) < s){
        mow.touch = true;
        mow.x = 1890;
        al_play_sample_instance(mow.Sound);
    }
}
void mower_update(){
    mow.dir = chara_direction;
    if(mower_fire == true){
        mow.x += 15;
        mow.state = MOVE;
        if (mow.x >= 1890 ){ 
            mow.state = STOP;
            mower_fire = false;
            mow.x = 240;
            mow.y = 190;
            if(mow.touch == true){
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
            mow.touch = false;
        }
        //printf("%d %d %d %d\n", mow.x, mow.y, cow_x_coord, cow_y_coord);
        mower_isCollided(cow_x_coord, cow_y_coord, 100);
        mower_isCollided(cow2_x_coord, cow2_y_coord, 100);
        mower_isCollided(cow3_x_coord, cow3_y_coord, 100);
        al_rest(0.001);
    }
}
void mower_draw(){
    al_draw_bitmap(mow.img_move[0], mow.x, mow.y, 0);
}