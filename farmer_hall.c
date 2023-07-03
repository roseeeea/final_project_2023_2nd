#include "farmer_hall.h"

// the state of character
enum {STOP = 0, MOVE, ATK};
typedef struct fcharacter
{
    int x, y; // the position of image
    int width, height; // the width and height of image
    bool dir; // left: false, right: true
    int state; // the state of character
    ALLEGRO_BITMAP *img_move[2];
    //ALLEGRO_BITMAP *img_atk[2];
    //ALLEGRO_SAMPLE_INSTANCE *atk_Sound;
    int anime; // counting the time of animation
    int anime_time; // indicate how long the animation
}fCharacter;
fCharacter fchara;
ALLEGRO_SAMPLE *sample = NULL;
void fcharacter_init(){
    // load character images
    for(int i = 1 ; i <= 2 ; i++){
        char temp[50];
        sprintf( temp, "./image/farmer_walk_%d.png", i );
        fchara.img_move[i-1] = al_load_bitmap(temp);
    }
    //debug(1);
    /*
    for(int i = 1 ; i <= 2 ; i++){
        char temp[50];
        sprintf( temp, "./image/char_atk%d.png", i );
        chara.img_atk[i-1] = al_load_bitmap(temp);
    }
    */
    // load effective sound
    //sample = al_load_sample("./sound/atk_sound.wav");
    //chara.atk_Sound  = al_create_sample_instance(sample);
    //al_set_sample_instance_playmode(chara.atk_Sound, ALLEGRO_PLAYMODE_ONCE);
    //al_attach_sample_instance_to_mixer(chara.atk_Sound, al_get_default_mixer());

    // initial the geometric information of character
    fchara.width = al_get_bitmap_width(fchara.img_move[0]);
    fchara.height = al_get_bitmap_height(fchara.img_move[0]);
    fchara.x = WIDTH/2-20;
    fchara.y = HEIGHT/2-100;
    fchara.dir = false;
    //debug(1);

    // initial the animation component
    fchara.state = STOP;
    fchara.anime = 0;
    fchara.anime_time = 30;
    //debug(1);

}
void fcharater_process(ALLEGRO_EVENT event){
    // process the animation
    if( event.type == ALLEGRO_EVENT_TIMER ){
        if( event.timer.source == fps ){
            fchara.anime++;
            fchara.anime %= fchara.anime_time;
        }
    // process the keyboard event
    }else if( event.type == ALLEGRO_EVENT_KEY_DOWN ){
        key_state[event.keyboard.keycode] = true;
        fchara.anime = 0;
    }else if( event.type == ALLEGRO_EVENT_KEY_UP ){
        key_state[event.keyboard.keycode] = false;
    }
}
void fcharater_update(){
    // use the idea of finite state machine to deal with different state
    if( key_state[ALLEGRO_KEY_W] ){
        fchara.y -= 5;
        fchara.state = MOVE;
    }else if( key_state[ALLEGRO_KEY_A] ){
        fchara.dir = false;
        fchara.x -= 5;
        fchara.state = MOVE;
    }else if( key_state[ALLEGRO_KEY_S] ){
        fchara.y += 5;
        fchara.state = MOVE;
    }else if( key_state[ALLEGRO_KEY_D] ){
        fchara.dir = true;
        fchara.x += 5;
        fchara.state = MOVE;
    }else if( key_state[ALLEGRO_KEY_SPACE] ){
        fchara.state = ATK;
    }else if( fchara.anime == fchara.anime_time-1 ){
        fchara.anime = 0;
        fchara.state = STOP;
    }else if ( fchara.anime == 0 ){
        fchara.state = STOP;
    }
}
void fcharacter_draw(){
    // with the state, draw corresponding image
    if( fchara.state == STOP ){
        if( fchara.dir )
            al_draw_bitmap(fchara.img_move[0], fchara.x, fchara.y, ALLEGRO_FLIP_HORIZONTAL);
        else
            al_draw_bitmap(fchara.img_move[0], fchara.x, fchara.y, 0);
    }
    else if( fchara.state == MOVE ){
        if( fchara.dir ){
            if( fchara.anime < fchara.anime_time/2 ){
                al_draw_bitmap(fchara.img_move[0], fchara.x, fchara.y, ALLEGRO_FLIP_HORIZONTAL);
            }else{
                al_draw_bitmap(fchara.img_move[1], fchara.x, fchara.y, ALLEGRO_FLIP_HORIZONTAL);
            }
        }else{
            if( fchara.anime < fchara.anime_time/2 ){
                al_draw_bitmap(fchara.img_move[0], fchara.x, fchara.y, 0);
            }else{
                al_draw_bitmap(fchara.img_move[1], fchara.x, fchara.y, 0);
            }
        }
    }
        /*
    }else if( chara.state == ATK ){
        if( chara.dir ){
            if( chara.anime < chara.anime_time/2 ){
                al_draw_bitmap(chara.img_atk[0], chara.x, chara.y, ALLEGRO_FLIP_HORIZONTAL);
            }else{
                al_draw_bitmap(chara.img_atk[1], chara.x, chara.y, ALLEGRO_FLIP_HORIZONTAL);
                al_play_sample_instance(chara.atk_Sound);
            }
        }else{
            if( chara.anime < chara.anime_time/2 ){
                al_draw_bitmap(chara.img_atk[0], chara.x, chara.y, 0);
            }else{
                al_draw_bitmap(chara.img_atk[1], chara.x, chara.y, 0);
                al_play_sample_instance(chara.atk_Sound);
            }
        }
    }
    */
}

void fcharacter_destory(){
    //debug(1);
    al_destroy_bitmap(fchara.img_move[0]);
    //debug(1);
    al_destroy_bitmap(fchara.img_move[1]);
    //debug(1);
    //al_destroy_bitmap(chara.img_atk[0]);
    //al_destroy_bitmap(chara.img_atk[1]);
    //al_destroy_sample_instance(chara.atk_Sound);
}
