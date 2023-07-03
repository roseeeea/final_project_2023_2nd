#include "cow.h"
#include <allegro5/allegro.h>



// the state of character
enum {STOP = 0, MOVE}; //enum 後面這坨從０開始計數 move從1開始，stop從0開始
typedef struct animal_cow
{
    int x, y; // the position of image
    int width, height; // the width and height of image
    bool dir; // down: false, up: true
    int state; // the state of character
    bool live, lr_dir;
    ALLEGRO_BITMAP *img_move[2];
    int anime; // counting the time of animation
    int anime_time; // indicate how long the animation
}animal_cow;
animal_cow cow;
animal_cow cow2;
animal_cow cow3;
void cow_init(){

    char temp1[50];
    char temp2[50];
    sprintf(temp1, "./image/animal_move%d.png", scenemode);
    sprintf(temp2, "./image/animal_move%d.png", scenemode+1);
    cow.img_move[0] = al_load_bitmap(temp1);
    printf("%p", cow.img_move[0]);
    cow.img_move[1] = al_load_bitmap(temp2);
    printf("%p", cow.img_move[1]);

    // initial the geometric information of character
    cow.width = 1000; //al_get_bitmap_width(cow.img_move[0]);
    cow.height = 1000; //al_get_bitmap_height(cow.img_move[0]);
    cow.x = rand()%1400+400;
    cow.y = rand()%1400+1;
    cow.dir = false;
    cow.lr_dir = false; //false = left, true = right

    // initial the animation component
    cow.anime = 0;
    cow.anime_time = 30;
    cow.live = true;

}

void cow_destroy(){
    al_destroy_bitmap(cow.img_move[0]);
    al_destroy_bitmap(cow.img_move[1]);
}
void cow_process(ALLEGRO_EVENT event){
    // process the animation
    if( event.type == ALLEGRO_EVENT_TIMER ){
        if( event.timer.source == fps ){
            cow.anime++;
            cow.anime %= cow.anime_time;
        }
    // process the keyboard event
    }else if( event.type == ALLEGRO_EVENT_KEY_DOWN ){
        key_state[event.keyboard.keycode] = true;
        cow.anime = 0;
    }else if( event.type == ALLEGRO_EVENT_KEY_UP ){
        key_state[event.keyboard.keycode] = false;
    }
}
void cow_update(){
    if(cow.live == true){//if(key_state[ALLEGRO_KEY_P])
        if (cow.dir == false) { 
            cow.y += scenemode*(rand()%10+1);
        }
        if (cow.dir == true) { 
            cow.y -= scenemode*(rand()%10+1);
        }
        if (cow.y >= 1100){
            cow.dir = true;
        }
        if (cow.y <= 50){
            cow.dir = false;
        }
        if (cow.lr_dir == false) { 
            cow.x -= scenemode*(rand()%10+1);
        }
        if (cow.lr_dir == true) { 
            cow.x += scenemode*(rand()%10+1);
        }
        if(cow.x <= 692){
            cow.lr_dir = true;
        }
        if(cow.x >= 1650){
            cow.lr_dir = false;
        }
    }
    al_rest(0.001);
    cow_x_coord = cow.x;
    cow_y_coord = cow.y;
}

void cow_draw(){
    // with the state, draw corresponding image
    if( cow.lr_dir ){
        if( cow.anime < cow.anime_time/2 ){
            al_draw_bitmap(cow.img_move[0], cow.x, cow.y, ALLEGRO_FLIP_HORIZONTAL);
        }else{
            al_draw_bitmap(cow.img_move[1], cow.x, cow.y, ALLEGRO_FLIP_HORIZONTAL);
        }
    }else{
        if( cow.anime < cow.anime_time/2 ){
            al_draw_bitmap(cow.img_move[0], cow.x, cow.y, 0);
        }else{
            al_draw_bitmap(cow.img_move[1], cow.x, cow.y, 0);
        }
    }
}
//------------------------------------------------------------------------------------------
void cow2_init(){
    char temp1[50];
    char temp2[50];
    sprintf(temp1, "./image/animal_move%d.png", scenemode);
    sprintf(temp2, "./image/animal_move%d.png", scenemode+1);
    cow2.img_move[0] = al_load_bitmap(temp1);
    printf("%p", cow2.img_move[0]);
    cow2.img_move[1] = al_load_bitmap(temp2);
    printf("%p", cow2.img_move[1]);

    // initial the geometric information of character
    cow2.width = 1000; //al_get_bitmap_width(cow2.img_move[0]);
    cow2.height = 1000; //al_get_bitmap_height(cow2.img_move[0]);
    cow2.x = rand()%1400+400;
    cow2.y = rand()%1400+1;
    cow2.dir = false;
    cow2.lr_dir = true; //false = left, true = right

    // initial the animation component
    cow2.anime = 0;
    cow2.anime_time = 30;
    cow2.live = true;

}

void cow2_destroy(){
    al_destroy_bitmap(cow2.img_move[0]);
    al_destroy_bitmap(cow2.img_move[1]);
}
void cow2_process(ALLEGRO_EVENT event){
    // process the animation
    if( event.type == ALLEGRO_EVENT_TIMER ){
        if( event.timer.source == fps ){
            cow2.anime++;
            cow2.anime %= cow2.anime_time;
        }
    // process the keyboard event
    }else if( event.type == ALLEGRO_EVENT_KEY_DOWN ){
        key_state[event.keyboard.keycode] = true;
        cow2.anime = 0;
    }else if( event.type == ALLEGRO_EVENT_KEY_UP ){
        key_state[event.keyboard.keycode] = false;
    }
}
void cow2_update(){
    if(cow2.live == true){//if(key_state[ALLEGRO_KEY_P])
        if (cow2.dir == false) { 
            cow2.y += scenemode*(rand()%10+1);
        }
        if (cow2.dir == true) { 
            cow2.y -= scenemode*(rand()%10+1);
        }
        if (cow2.y >= 1100){
            cow2.dir = true;
        }
        if (cow2.y <= 50){
            cow2.dir = false;
        }
        if (cow2.lr_dir == false) { 
            cow2.x -= scenemode*(rand()%10+1);
        }
        if (cow2.lr_dir == true) { 
            cow2.x += scenemode*(rand()%10+1);
        }
        if(cow2.x <= 692){
            cow2.lr_dir = true;
        }
        if(cow2.x >= 1650){
            cow2.lr_dir = false;
        }
    }
    al_rest(0.001);
    cow2_x_coord = cow2.x;
    cow2_y_coord = cow2.y;
}

void cow2_draw(){
    // with the state, draw corresponding image
    if( cow2.lr_dir ){
        if( cow2.anime < cow2.anime_time/2 ){
            al_draw_bitmap(cow2.img_move[0], cow2.x, cow2.y, ALLEGRO_FLIP_HORIZONTAL);
        }else{
            al_draw_bitmap(cow2.img_move[1], cow2.x, cow2.y, ALLEGRO_FLIP_HORIZONTAL);
        }
    }else{
        if( cow2.anime < cow2.anime_time/2 ){
            al_draw_bitmap(cow2.img_move[0], cow2.x, cow2.y, 0);
        }else{
            al_draw_bitmap(cow2.img_move[1], cow2.x, cow2.y, 0);
        }
    }
}
//------------------------------------------------------------------------------------------
void cow3_init(){
    char temp1[50];
    char temp2[50];
    sprintf(temp1, "./image/animal_move%d.png", scenemode);
    sprintf(temp2, "./image/animal_move%d.png", scenemode+1);
    cow3.img_move[0] = al_load_bitmap(temp1);
    printf("%p", cow3.img_move[0]);
    cow3.img_move[1] = al_load_bitmap(temp2);
    printf("%p", cow3.img_move[1]);

    // initial the geometric information of character
    cow3.width = 1000; //al_get_bitmap_width(cow3.img_move[0]);
    cow3.height = 1000; //al_get_bitmap_height(cow3.img_move[0]);
    cow3.x = 600;
    cow3.y = 600;
    cow3.dir = true;
    cow3.lr_dir = true; //false = left, true = right

    // initial the animation component
    cow3.anime = 0;
    cow3.anime_time = 30;
    cow3.live = true;

}

void cow3_destroy(){
    al_destroy_bitmap(cow3.img_move[0]);
    al_destroy_bitmap(cow3.img_move[1]);
}
void cow3_process(ALLEGRO_EVENT event){
    // process the animation
    if( event.type == ALLEGRO_EVENT_TIMER ){
        if( event.timer.source == fps ){
            cow3.anime++;
            cow3.anime %= cow3.anime_time;
        }
    // process the keyboard event
    }else if( event.type == ALLEGRO_EVENT_KEY_DOWN ){
        key_state[event.keyboard.keycode] = true;
        cow3.anime = 0;
    }else if( event.type == ALLEGRO_EVENT_KEY_UP ){
        key_state[event.keyboard.keycode] = false;
    }
}
void cow3_update(){
    if(cow3.live == true){//if(key_state[ALLEGRO_KEY_P])
        if (cow3.dir == false) { 
            cow3.y += scenemode*(rand()%10+1);
        }
        if (cow3.dir == true) { 
            cow3.y -= scenemode*(rand()%10+1);
        }
        if (cow3.y >= 1100){
            cow3.dir = true;
        }
        if (cow3.y <= 50){
            cow3.dir = false;
        }
        if (cow3.lr_dir == false) { 
            cow3.x -= scenemode*(rand()%10+1);
        }
        if (cow3.lr_dir == true) { 
            cow3.x += scenemode*(rand()%10+1);
        }
        if(cow3.x <= 692){
            cow3.lr_dir = true;
        }
        if(cow3.x >= 1650){
            cow3.lr_dir = false;
        }
    }
    al_rest(0.001);
    cow3_x_coord = cow3.x;
    cow3_y_coord = cow3.y;
}

void cow3_draw(){
    // with the state, draw corresponding image
    if( cow3.lr_dir ){
        if( cow3.anime < cow3.anime_time/2 ){
            al_draw_bitmap(cow3.img_move[0], cow3.x, cow3.y, ALLEGRO_FLIP_HORIZONTAL);
        }else{
            al_draw_bitmap(cow3.img_move[1], cow3.x, cow3.y, ALLEGRO_FLIP_HORIZONTAL);
        }
    }else{
        if( cow3.anime < cow3.anime_time/2 ){
            al_draw_bitmap(cow3.img_move[0], cow3.x, cow3.y, 0);
        }else{
            al_draw_bitmap(cow3.img_move[1], cow3.x, cow3.y, 0);
        }
    }
}