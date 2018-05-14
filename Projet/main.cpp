#include <iostream>
#include <string.h>
#include <allegro.h>
#include <list>
#include <time.h>

#include "listeforme.h"
#include "murbrique.h"
#include "raquette.h"
#include "balle.h"
#include "listeballe.h"

using namespace std;

BITMAP *page;
BITMAP *image_fond;

SAMPLE *beep_raquette;
SAMPLE *beep_brique;
SAMPLE *defaite;
SAMPLE *victoire;
SAMPLE *taillePlus;
SAMPLE *vitessePlus;
SAMPLE *inversionRaquette;
SAMPLE *balleSup;

MIDI *background;

bool LOSE = false;
bool WIN = false;

typedef struct Theme {
    char* image_background;
    char* son_background;
} Theme;

void fenetre_init(Theme t)
{
    allegro_init();
    install_keyboard();
    install_mouse();
    //set_color_depth(16);

    if(set_gfx_mode(GFX_AUTODETECT_WINDOWED,640,480,0,0)!=0)
    {
        allegro_message(allegro_error);
        allegro_exit();
        return;
    }

    set_mouse_sprite(NULL);
    show_mouse(screen);
    set_keyboard_rate(0,0);
    set_window_title("Casse Brique");

    page = create_bitmap(SCREEN_W,SCREEN_H);
    image_fond = load_bitmap(t.image_background, NULL);

    if(!page)
    {
        allegro_message("probleme creation bitmap");
        allegro_exit();
        return;
    }
}

void sons_init(Theme t)
{
    install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,"A");
    beep_raquette = load_sample("sounds/bruitages/son_raquette.wav");
    beep_brique = load_sample("sounds/bruitages/son_brique.wav");
    defaite = load_sample("sounds/bruitages/mariodie.wav");
    victoire = load_sample("sounds/bruitages/stageclear.wav");
    taillePlus = load_sample("sounds/bruitages/taillePlus.wav");
    vitessePlus = load_sample("sounds/bruitages/vitessePlus.wav");
    inversionRaquette = load_sample("sounds/bruitages/inversionRaquette.wav");
    balleSup = load_sample("sounds/bruitages/balleSup.wav");

    background = load_midi(t.son_background);
    play_midi(background, true);
}

Theme theme_init()
{
    Theme* themes;
    themes = new Theme[4];

    themes[0].image_background="images/background/donkey_kong.pcx";
    themes[1].image_background="images/background/james_bond.pcx";
    themes[2].image_background="images/background/star_wars.pcx";
    themes[3].image_background="images/background/tropique.pcx";

    themes[0].son_background="sounds/background/donkey_kong.mid";
    themes[1].son_background="sounds/background/james_bond2.mid";
    themes[2].son_background="sounds/background/espace.mid";
    themes[3].son_background="sounds/background/yoshi.mid";

    srand(time(NULL));
    int tirage_theme=rand()%4;
    Theme theme_choisi = themes[tirage_theme];

    return theme_choisi;
}

int main()
{
    Theme theme;
    theme=theme_init();
    fenetre_init(theme);
    sons_init(theme);
    text_mode(-1);

    cout << "debut du jeu" << endl;
    listeforme& ll = forme::gett();
    listeballe lb;
    murbrique m;
    raquette r(240,455,150,20,0.7,makecol(255,255,100));

    do{
        clear_bitmap(page);
        blit(image_fond,page,0,0,0,0,page->w,page->h);
        textprintf(image_fond,font,575,430,makecol(200,200,200),"nb = %d",listeforme::getnb());
        textprintf(page,font,550,440,makecol(200,200,200),"Score = %d",m.getScore());
        ll.affiche();
        r.deplace();
        lb.deplace();
        lb.collision(&m,&r);
        blit(page,screen,0,0,0,0,page->w,page->h);
    } while(!key[KEY_ESC] && LOSE==false && WIN==false);
    if(LOSE==true)
    {
        textprintf_centre_ex(screen, font, SCREEN_W / 2, 350,makecol(252, 100, 100), -1,"DEFAITE ! SCORE = %d",m.getScore());
        stop_midi();
        play_sample(defaite,255,128,800,false);
        clock_t wait;
        wait = clock();
        while (clock() <= (wait + 4000));
    }
    if(WIN==true)
    {
        ll.affiche();
        textprintf_centre_ex(screen, font, SCREEN_W / 2, 350,makecol(100, 252, 100), -1,"VICTOIRE ! SCORE = %d",m.getScore());
        stop_midi();
        play_sample(victoire,255,128,800,false);
        clock_t wait;
        wait = clock();
        while (clock() <= (wait + 6500));
    }
    destroy_bitmap(page);
    set_gfx_mode(GFX_TEXT,0,0,0,0);
    cout << "fin du jeu" << endl;

    return 0;
}
END_OF_MAIN();
