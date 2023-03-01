#include <SFML/Audio.hpp>
#include "OutlinePile.h"

class Game
{
public:
    RectangleShape menu_box, resume, quit, new_game, score_board, start_button, blurred_page;
    Texture main_background_texture, background_texture, tryerz_texture, sound_On_texture, mute_texture, menu_texture;
    Sprite main_background, background, sound_on, mute, menu;
    Font font;
    Text timer, you_won, menu_text, resume_text, new_game_text, quit_text;
    Clock clock;
    Time time_elapsed1, time_elapsed2;
    SoundBuffer window_start_buffer, music_start_buffer, winning_theme_buffer;
    Sound window_start, music_start, winning_theme_music;
    OutlinePile* outline_piles;

    Game();

    void setStartMenu();
    void setMainMenuMusic();
    void setMainMenuButton();
    void setBackground();
    void setTimer();
    Text drawTimer();
    void setMenu();
    void setMenuText();
    void setOutlinePiles();
    void drawOutlinePiles(RenderWindow&);
    void setScoreboard();
    void setFont();
    void setEndMenu();
    void setEndMenuButton();
};