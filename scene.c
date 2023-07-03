#include "scene.h"

ALLEGRO_FONT *font1 = NULL;
ALLEGRO_FONT *font2 = NULL;
ALLEGRO_FONT *font3 = NULL;
ALLEGRO_FONT *font4 = NULL;

ALLEGRO_FONT *font_beef = NULL;
ALLEGRO_FONT *font_sheep = NULL;
ALLEGRO_FONT *font_chicken = NULL;



ALLEGRO_BITMAP *hallbackground = NULL;
ALLEGRO_BITMAP *menubackground = NULL;
ALLEGRO_BITMAP *introduction = NULL;
ALLEGRO_BITMAP *slaughterbackground = NULL;
ALLEGRO_BITMAP *slaughterbackground2 = NULL;
ALLEGRO_BITMAP *slaughterbackground3 = NULL;
ALLEGRO_BITMAP *limit = NULL;

ALLEGRO_BITMAP *food= NULL;
ALLEGRO_BITMAP *endscene = NULL;

int food_flag=0;

//-----------------------------------------------------------------
// function of menu
void menu_init(){
    font1 = al_load_ttf_font("./font/GladlyAcceptRegular-Wyjov.ttf",120,10);
    font2 = al_load_ttf_font("./font/GladlyAcceptRegular-Wyjov.ttf",30,0);
    menubackground = al_load_bitmap("./image/menubackground.png");
    
}
void menu_process(ALLEGRO_EVENT event){
    if( event.type == ALLEGRO_EVENT_KEY_UP ){
        if( event.keyboard.keycode == ALLEGRO_KEY_ENTER ){
            judge_next_window = true;
            changewindow=8;
            /*
            printf("changewindow position in :%#x\n", &changewindow);
            printf("jusdgewindow position in :%#x\n", &judge_next_window);
            printf("slaghterbg position in :%#x\n", &slaughterbackground);
            printf("hallbg position in :%#x\n", &hallbackground);
            */
        }
    }
}
void menu_draw(){
    //al_clear_to_color(al_map_rgb(62, 117, 39));
    al_draw_bitmap(menubackground, 0, 0, 0);
    al_draw_text(font1, al_map_rgb(245, 101, 39), WIDTH/2, HEIGHT/2-200 , ALLEGRO_ALIGN_CENTRE, "NTHU SLAUGHTERHOUSE");
    al_draw_text(font2, al_map_rgb(255, 255, 255), WIDTH/2, HEIGHT/2+10 , ALLEGRO_ALIGN_CENTRE, "Press 'Enter' to start");
    al_draw_rectangle(WIDTH/2-300, HEIGHT/2-10, WIDTH/2+300, HEIGHT/2+50, al_map_rgb(255, 255, 255), 10);
}
void menu_destroy(){
    //debug(1);
    al_destroy_font(font1);
    al_destroy_font(font2);
    //debug(1);
    al_destroy_bitmap(menubackground);
    //debug(1);
}

//-----------------------------------------------------------------
// function of game_scene
void game_scene_init(){
    //debug(1);
    fcharacter_init();

    font_chicken = al_load_ttf_font("./font/pirulen.ttf",40,0);
    font_beef = al_load_ttf_font("./font/pirulen.ttf",40,0);
    font_sheep = al_load_ttf_font("./font/pirulen.ttf",40,0);
    //debug(1);
    hallbackground = al_load_bitmap("./image/background.png");
    //debug(1);
}

void game_scene_process(ALLEGRO_EVENT event){
    //debug(1);
    if( event.type == ALLEGRO_EVENT_KEY_UP ){
         //debug(1);
        if(event.keyboard.keycode == ALLEGRO_KEY_LEFT ){
            judge_next_window = true;
            changewindow=3;
            //debug(1);
        }
        if(event.keyboard.keycode == ALLEGRO_KEY_DOWN ){
            judge_next_window = true;
            changewindow=4;
            //debug(1);
        }
        if(event.keyboard.keycode == ALLEGRO_KEY_RIGHT ){
            judge_next_window = true;
            changewindow=5;
            //debug(1);
        }
        if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE ){
            judge_next_window = true;
            changewindow=6;
            //debug(1);
        }
        if(event.keyboard.keycode == ALLEGRO_KEY_Y ){
            food_flag=1;
            changewindow=6;
            judge_next_window = true;
            //debug(1);
        }
        if(event.keyboard.keycode == ALLEGRO_KEY_U ){
            food_flag=2;
            changewindow=6;
            judge_next_window = true;
            //debug(1);
        }
        if(event.keyboard.keycode == ALLEGRO_KEY_I ){
            food_flag=3;
            changewindow=6;
            judge_next_window = true;
            //debug(1);
        }
        if(event.keyboard.keycode == ALLEGRO_KEY_O ){
            food_flag=4;
            changewindow=6;
            judge_next_window = true;
            debug(1);
            printf("%d\n", food_flag);
        }
        if(event.keyboard.keycode == ALLEGRO_KEY_P ){
            food_flag=5;
            changewindow=6;
            judge_next_window = true;
            debug(1);
            printf("%d\n", food_flag);
        }
    }
}

void game_scene_draw(){
    //debug(1);
    al_draw_bitmap(hallbackground, 0, 0, 0);

    char st_score_beef[4]={0};
    char st_score_sheep[4]={0};
    char st_score_chicken[4]={0};

    sprintf(st_score_beef, "%03d", score_beef);
    sprintf(st_score_chicken, "%03d", score_chicken);
    sprintf(st_score_sheep, "%03d", score_sheep);

    al_draw_text(font_beef, al_map_rgb(255,255,255), 250, 100 , ALLEGRO_ALIGN_CENTRE, st_score_beef);
    al_draw_text(font_sheep, al_map_rgb(255,255,255), 250, 230 , ALLEGRO_ALIGN_CENTRE, st_score_sheep);
    al_draw_text(font_chicken, al_map_rgb(255,255,255), 250, 360 , ALLEGRO_ALIGN_CENTRE, st_score_chicken);



    //debug(1);
    fcharacter_draw();
    //debug(1);

}

void game_scene_destroy(){
    //debug(1);
    al_destroy_bitmap(hallbackground);
    al_destroy_font(font_chicken);
    al_destroy_font(font_beef);
    al_destroy_font(font_sheep);


    //debug(1);
    fcharacter_destory();
    //debug(1);
}

//-----------------------------------------------------------------
void game_barn1_init(){
    slaughterbackground = al_load_bitmap("./image/slaughterscene_cow.png");
    debug(1);
    font_beef = al_load_ttf_font("./font/pirulen.ttf",50,0);
    debug(1);

    character_init();
    cow_init();
    cow2_init();
    cow3_init();
    mower_init();
    dart_init();
    arrow_init();
    
}

void game_barn1_process(ALLEGRO_EVENT event){
   //debug(1);
    if( event.type == ALLEGRO_EVENT_KEY_UP ){
         //debug(1);
        if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE ){
            //debug(1);
            judge_next_window = true;
            changewindow=2;
            //debug(1);
        }
    }
    if(add_beef>=10 || add_sheep>=8 || add_chicken>=6){
        judge_next_window=true;
        changewindow=7;
    }
}
void game_barn1_draw(){
    //debug(1);
    al_draw_bitmap(slaughterbackground, 0, 0, 0);
    char st_add_beef[4]={0};
    //debug(1);
    sprintf(st_add_beef, "%d", add_beef);
    
    
    //debug(1);

    al_draw_text(font_beef, al_map_rgb(232,51,23), 250, 1320 , ALLEGRO_ALIGN_CENTRE, st_add_beef);

    character_draw();
    cow_draw();
    cow2_draw();
    cow3_draw();
    mower_draw();
    dart_draw();
    arrow_draw();
    //debug(1);
    //character_draw();

}

void game_barn1_destroy(){
    debug(1);
    al_destroy_bitmap(slaughterbackground);
    al_destroy_font(font_beef);

    score_beef+=add_beef;
    add_beef=0;

    character_destroy();
    cow_destroy();
    cow2_destroy();
    cow3_destroy();
    mower_destroy();
    dart_destroy();
    arrow_destroy();


    //debug(1);
    //character_destory();
}

//-----------------------------------------------------------------
void game_barn2_init(){
    slaughterbackground2 = al_load_bitmap("./image/slaughterscene_sheep.png");
    font_sheep = al_load_ttf_font("./font/pirulen.ttf",50,0);

    character_init();
    cow_init();
    cow2_init();
    cow3_init();
    mower_init();
    dart_init();
    arrow_init();
    //debug(1);
}

void game_barn2_process(ALLEGRO_EVENT event){
    //debug(1);
    if( event.type == ALLEGRO_EVENT_KEY_UP ){
         //debug(1);
        if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE ){
            //debug(1);
            judge_next_window = true;
            changewindow=2;
            //debug(1);
        }
    }
    if(add_beef>=10 || add_sheep>=8 || add_chicken>=6){
        judge_next_window=true;
        changewindow=7;
    }
}
void game_barn2_draw(){
    //debug(1);
    al_draw_bitmap(slaughterbackground2, 0, 0, 0);
    char st_add_sheep[4]={0};

    sprintf(st_add_sheep, "%d", add_sheep);

    al_draw_text(font_sheep, al_map_rgb(232,51,23), 250, 1320 , ALLEGRO_ALIGN_CENTRE, st_add_sheep);

    character_draw();
    cow_draw();
    cow2_draw();
    cow3_draw();
    mower_draw();
    dart_draw();
    arrow_draw();

    //debug(1);
    //character_draw();

}

void game_barn2_destroy(){
    //debug(1);
    al_destroy_bitmap(slaughterbackground2);
    al_destroy_font(font_sheep);

    score_sheep+=add_sheep;
    add_sheep=0;

    character_destroy();
    cow_destroy();
    cow2_destroy();
    cow3_destroy();
    mower_destroy();
    dart_destroy();
    arrow_destroy();


    //debug(1);
    //character_destory();
}


//-----------------------------------------------------------------
void game_barn3_init(){
    slaughterbackground3 = al_load_bitmap("./image/slaughterscene_chicken.png");
    font_chicken = al_load_ttf_font("./font/pirulen.ttf",50,0);

    character_init();
    cow_init();
    cow2_init();
    cow3_init();
    mower_init();
    dart_init();
    arrow_init();
    //debug(1);
}

void game_barn3_process(ALLEGRO_EVENT event){
    //debug(1);
    if( event.type == ALLEGRO_EVENT_KEY_UP ){
         //debug(1);
        if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE ){
            //debug(1);
            judge_next_window = true;
            changewindow=2;
            //debug(1);
        }
    }
    if(add_beef>=10 || add_sheep>=10 || add_chicken>=10){
        judge_next_window=true;
        changewindow=7;
    }
}
void game_barn3_draw(){
    //debug(1);
    al_draw_bitmap(slaughterbackground3, 0, 0, 0);
    char st_add_chicken[4]={0};

    sprintf(st_add_chicken, "%d", add_chicken);

    al_draw_text(font_chicken, al_map_rgb(232,51,23), 250, 1320, ALLEGRO_ALIGN_CENTRE, st_add_chicken);

    character_draw();
    cow_draw();
    cow2_draw();
    cow3_draw();
    mower_draw();
    dart_draw();
    arrow_draw();

    //debug(1);
    //character_draw();

}

void game_barn3_destroy(){
    //debug(1);
    al_destroy_bitmap(slaughterbackground3);
    al_destroy_font(font_chicken);

    score_chicken+=add_chicken;
    add_chicken=0;

    character_destroy();
    cow_destroy();
    cow2_destroy();
    cow3_destroy();
    mower_destroy();
    dart_destroy();
    arrow_destroy();


    //debug(1);
    //character_destory();
}


//-----------------------------------------------------------------
void game_end_init(ALLEGRO_EVENT event){
    endscene = al_load_bitmap("./image/food_bg.png");
    font3 = al_load_ttf_font("./font/GladlyAcceptRegular-Wyjov.ttf",30,30);
    font4 = al_load_ttf_font("./font/GladlyAcceptRegular-Wyjov.ttf",70,0);
    debug(1);
    //printf("%d, %d, %d\n", score_beef, score_chicken, score_sheep);
    if((score_chicken>score_beef && score_chicken >score_sheep)|| food_flag==1){
        food = al_load_bitmap("./image/food_chicken.png");
        food_flag=1;
    }
    else if((score_beef>score_chicken && score_beef>score_sheep) || food_flag==2){
        food = al_load_bitmap("./image/food_beef.png");
        food_flag=2;
    }
    else if((score_sheep>score_chicken && score_sheep>score_beef) || food_flag==3){
        food = al_load_bitmap("./image/food_sheep.png");
        food_flag=3;
    }
    else if((score_beef==score_chicken && score_chicken==score_sheep && score_beef>0) || food_flag==5){
        debug(1);
        food_flag=5;
        food = al_load_bitmap("./image/food_prize.png");
        debug(1); 
    }
    else if((score_beef==score_chicken && score_chicken==score_sheep && score_beef==0) || food_flag==4 ){
        debug(1);
        food = al_load_bitmap("./image/food_veg.png");
        food_flag=4;
        debug(1);
    }
    
        
        
}

/*
void game_end_process(ALLEGRO_EVENT event){
    
}
*/

void game_end_draw(){
    //debug(1);
    al_draw_bitmap(endscene, 0, 0, 0);
    //debug(1);
    al_draw_bitmap(food, 0, 0, 1);
    //debug(1);
    al_draw_text(font3, al_map_rgb(255,255,255), WIDTH/2, HEIGHT/2+350 , ALLEGRO_ALIGN_CENTRE, "GAME OVER");
    //debug(1);
    if(food_flag==1){
        al_draw_text(font4, al_map_rgb(255,255,255), WIDTH/2, HEIGHT/2+250, ALLEGRO_ALIGN_CENTRE, "GREAT! YOU EARN THE CHICKEN NUGGET");
    }
    else if(food_flag==2){
        al_draw_text(font4, al_map_rgb(255,255,255), WIDTH/2, HEIGHT/2+250, ALLEGRO_ALIGN_CENTRE, "WELL DONE! YOU EARN THE BEEF NOODLE");
    }
    else if(food_flag==3){
        al_draw_text(font4, al_map_rgb(255,255,255), WIDTH/2, HEIGHT/2+250, ALLEGRO_ALIGN_CENTRE, "WELL DONE! YOU EARN THE GRILLED LAMB");
    }
    else if(food_flag==4){
        al_draw_text(font4, al_map_rgb(255,255,255), WIDTH/2, HEIGHT/2+250, ALLEGRO_ALIGN_CENTRE, "LOOKS LIKE THERE'S NO MEAT FOR YOU");
    }
    else if(food_flag==5){
        al_draw_text(font4, al_map_rgb(255,255,255), WIDTH/2, HEIGHT/2+250, ALLEGRO_ALIGN_CENTRE, "SPECTACULAR! YOU MADE YOURSELF A FEAST");
    }


}

void game_end_process(ALLEGRO_EVENT event){
    //debug(1);
    if( event.type == ALLEGRO_EVENT_KEY_UP ){
         //debug(1);
        if(event.keyboard.keycode == ALLEGRO_KEY_LEFT ){
            //debug(1);
            judge_next_window = true;
            changewindow=2;
            //debug(1);
        }
    }
}

void game_end_destroy(){
    //debug(1)
    al_destroy_bitmap(endscene);
    al_destroy_bitmap(food);
    al_destroy_font(font3);
    al_destroy_font(font4);
    //debug(1);
    //character_destory();
}

//-----------------------------------------------------------------

void game_limit_init(){
    limit = al_load_bitmap("./image/farmer_walk_3.png");
}

void game_limit_process(ALLEGRO_EVENT event){
    //debug(1);
    if( event.type == ALLEGRO_EVENT_KEY_UP ){
         //debug(1);
        if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE ){
            //debug(1);
            judge_next_window = true;
            changewindow=2;
            //debug(1);
        }
    }
}
void game_limit_draw(){
    //debug(1);
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_bitmap(limit, 200, 350, 0);

   

}

void game_limit_destroy(){
    //debug(1);
    al_destroy_bitmap(limit);
    //debug(1);
    //character_destory();
}

//-----------------------------------------------------------------

void game_introduction_init(){
    introduction = al_load_bitmap("./image/introduction.png");
}

void game_introduction_process(ALLEGRO_EVENT event){
    //debug(1);
    if( event.type == ALLEGRO_EVENT_KEY_UP ){
         //debug(1);
        if(event.keyboard.keycode == ALLEGRO_KEY_ENTER ){
            //debug(1);
            judge_next_window = true;
            changewindow=2;
            //debug(1);
        }
    }
}
void game_introduction_draw(){
    //debug(1);
    al_draw_bitmap(introduction, 0, 0, 0);

   

}

void game_introduction_destroy(){
    //debug(1);
    al_destroy_bitmap(introduction);
    //debug(1);
    //character_destory();
}









