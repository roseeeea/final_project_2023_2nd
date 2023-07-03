#include "GameWindow.h"

bool draw = false;
int window = 1;

const char *title = "Final Project 111070005";

// ALLEGRO Variables
ALLEGRO_DISPLAY* display = NULL;
ALLEGRO_SAMPLE *song=NULL;
ALLEGRO_SAMPLE_INSTANCE *sample_instance;

//------------------------------------------------------------------

int Game_establish() {
    int msg = 0;

    game_init();
    game_begin();

    while ( msg != GAME_TERMINATE ) {
        msg = game_run();
        if ( msg == GAME_TERMINATE )
            printf( "Game Over\n" );
    }

    game_destroy();
    return 0;
}

//------------------------------------------------------------------
void game_init() {
    //printf("draw position in :%#x\n", &draw);
    printf( "Game Initializing...\n" );
    al_init();
    // init audio
    al_install_audio();
    al_init_acodec_addon();
    // Create display
    display = al_create_display(WIDTH, HEIGHT);
    // create event queue
    event_queue = al_create_event_queue();
    // Initialize Allegro settings
    al_set_window_position(display, 0, 0);
    al_set_window_title(display, title);
    al_init_primitives_addon();
    al_init_font_addon(); // initialize the font addon
    al_init_ttf_addon(); // initialize the ttf (True Type Font) addon
    al_init_image_addon(); // initialize the image addon
    al_init_acodec_addon(); // initialize acodec addon
    al_install_keyboard(); // install keyboard event
    al_install_mouse();    // install mouse event
    al_install_audio();    // install audio event
    // Register event
    al_register_event_source(event_queue, al_get_display_event_source( display ));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());
    fps  = al_create_timer( 1.0 / FPS );
    al_register_event_source(event_queue, al_get_timer_event_source( fps )) ;
    // initialize the icon on the display
    ALLEGRO_BITMAP *icon = al_load_bitmap("./image/icon.png");
    al_set_display_icon(display, icon);
}

//------------------------------------------------------------------
void game_begin() {
    // Load sound
    song = al_load_sample("./sound/farmingmusic.wav");
    al_reserve_samples(20);
    sample_instance = al_create_sample_instance(song);
    // Loop the song until the display closes
    al_set_sample_instance_playmode(sample_instance, ALLEGRO_PLAYMODE_LOOP);
    al_restore_default_mixer();
    al_attach_sample_instance_to_mixer(sample_instance, al_get_default_mixer());
    // set the volume of instance
    al_set_sample_instance_gain(sample_instance, 1) ;
    al_play_sample_instance(sample_instance);
    al_start_timer(fps);
    // initialize the menu before entering the loop
    menu_init();

}

//------------------------------------------------------------------
void game_update(){
    if(window==2){
        fcharater_update();
    }
    if(window==3 || window==4 || window==5){
        character_update();
        if(mower_fire == true) mower_update();
        if(dart_fire == true) dart_update();
        if(arrow_fire == true) arrow_update();
        cow_update();
        cow2_update();
        cow3_update();

    }
    if( judge_next_window ){
        if( window == 1 ){
            // not back menu anymore, therefore destroy it
            menu_destroy();
            // initialize next scene
            //debug(1);
            game_introduction_init();
            //debug(1);
            judge_next_window = false;
            //window = changewindow;
            //debug(1);
            
        }
        if( window == 8 ){
            // not back menu anymore, therefore destroy it
            game_introduction_destroy();
            // initialize next scene
            //debug(1);
            game_scene_init();
            fcharater_update();
            //debug(1);
            judge_next_window = false;
            //window = changewindow;
            //debug(1);
            
        }
        if( window == 2 ){
            debug(1);
            //charater_update();
            if(changewindow == 3){
                //debug(1);
                game_scene_destroy();
                //debug(1);
                scenemode=1;
                game_barn1_init();
                //debug(1);
                judge_next_window = false;
                //scenemode=0;
                //debug(1);
                //window = changewindow;
            }
            if(changewindow == 4){
                //debug(1);
                game_scene_destroy();
                //debug(1);
                scenemode=3;
                game_barn2_init();
                //debug(1);
                judge_next_window = false;
                //scenemode=0;
                //debug(1);
                //window = changewindow;
            }
            if(changewindow == 5){
                //debug(1);
                game_scene_destroy();
                //debug(1);
                scenemode=5;
                game_barn3_init();
                //debug(1);
                judge_next_window = false;
                //scenemode=0;
                //debug(1);
                //window = changewindow;
            }
            if(changewindow == 6){
                //debug(1);
                game_scene_destroy();
                //debug(1);
                game_end_init();
                debug(1);
                judge_next_window = false;
                //debug(1);
                //window = changewindow;
            }
         }
        if( window == 3){
            debug(1);
            if(changewindow==2){
                game_barn1_destroy();
                game_scene_init();
                fcharater_update();
                judge_next_window = false;
            }
            if(changewindow==7){
                debug(1);
                game_barn1_destroy();
                game_limit_init();
                judge_next_window = false;
            }
                
        }
        if( window == 4){
            debug(1);
            if(changewindow==2){
                game_barn2_destroy();
                game_scene_init();
                fcharater_update();
                judge_next_window = false;
            }
            if(changewindow==7){
                debug(1);
                game_barn2_destroy();
                game_limit_init();
                judge_next_window = false;
            }
                
        }
        if( window == 5){
            debug(1);
            if(changewindow==2){
                game_barn3_destroy();
                game_scene_init();
                fcharater_update();
                judge_next_window = false;
            }
            if(changewindow==7){
                debug(1);
                game_barn3_destroy();
                game_limit_init();
                judge_next_window = false;
            }
                
        }
        if(window == 7){
            game_limit_destroy();
            game_scene_init();
            fcharater_update();
            judge_next_window = false;
        }
        if(window == 6){
            game_end_destroy();
            game_scene_init();
            fcharater_update();
            judge_next_window = false;
        } 
    
        window=changewindow;
        printf("change window to %d\n", window);
        changewindow=0;
    }
    
} 

//------------------------------------------------------------------
int process_event(){
    // Request the event
    ALLEGRO_EVENT event;
    al_wait_for_event(event_queue, &event);
    // process the event of other component
    if( window == 1 ){ 
        //debug(1);
        menu_process(event);
        //debug(1);
    }else if( window == 2 ){
        //debug(1);
        fcharater_process(event);
        //debug(1);
        game_scene_process(event);
        //debug(1);
    }
    else if( window == 3){
        //debug(1);
        game_barn1_process(event);
        character_process(event);
        cow_process(event);
        cow2_process(event);
        cow3_process(event);
        dart_process(event);
        arrow_process(event);
        //debug(1);
    }
    else if( window == 4){
        //debug(1);
        game_barn2_process(event);
        character_process(event);
        cow_process(event);
        cow2_process(event);
        cow3_process(event);
        dart_process(event);
        arrow_process(event);
        //debug(1);
    }
    else if( window == 5){
        //debug(1);
        game_barn3_process(event);
        character_process(event);
        cow_process(event);
        cow2_process(event);
        cow3_process(event);
        dart_process(event);
        arrow_process(event);
        //debug(1);
    }
    else if( window == 7){
        //debug(1);
        game_limit_process(event);
    }
    else if( window == 8){
        //debug(1);
        game_introduction_process(event);
    }
    else if( window == 6){
        //debug(1);
        game_end_process(event);
    }
    
    // Shutdown our program
    if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        return GAME_TERMINATE;
    else if(event.type == ALLEGRO_EVENT_TIMER)
        if(event.timer.source == fps)
            draw = true;
    if(draw) game_update();
    return 0;
}

//------------------------------------------------------------------
void game_draw(){
    //debug(1);
    if( window == 1 ){ //if window shot down, check the cloud of the photo
        //debug(1);
        menu_draw();
    }else if( window == 2 ){
        //debug(1);
        game_scene_draw();
    }
    
    else if( window == 3){
        //debug(1);
        game_barn1_draw();
    }
    else if( window == 4){
        //debug(1);
        game_barn2_draw();
    }
    else if( window == 5){
        //debug(1);
        game_barn3_draw();
    }
    else if( window == 6){
        //debug(1);
        game_end_draw();
    }
    else if( window == 7){
        //debug(1);
        game_limit_draw();
    }
     else if( window == 8){
        //debug(1);
        game_introduction_draw();
    }
    
    //debug(1);
    al_flip_display();
}

//------------------------------------------------------------------
int game_run() {
    int error = 0;
    if( draw ){
        //debug(1);
        game_draw();
        draw = false;
    }
    if ( !al_is_event_queue_empty(event_queue) ) {
        error = process_event();
    }
    return error;
}

//------------------------------------------------------------------
void game_destroy() {
    // Make sure you destroy all things
    al_destroy_event_queue(event_queue);
    al_destroy_display(display);
    if(window==2){
        //debug(1);
        game_scene_destroy();
        //debug(1);
    }
    else if(window == 3){
        //debug(1);
        game_barn1_destroy();
        //debug(1);
    }
    else if(window == 4){
        //debug(1);
        game_barn2_destroy();
        //debug(1);
    }
    else if(window == 5){
        //debug(1);
        game_barn3_destroy();
        //debug(1);
    }
    else if(window == 6){
        //debug(1);
        game_end_destroy();
        //debug(1);
    }
    else if(window == 7){
        //debug(1);
        game_limit_destroy();
        //debug(1);
    }
    else if(window == 8){
        //debug(1);
        game_introduction_destroy();
        //debug(1);
    }
    

}
