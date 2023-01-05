#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Pile.h"
#include "Game.h"
using namespace sf;
using namespace std;

int main()
{
    RenderWindow window(VideoMode(1600, 900), "Tryerz Solitaire");
    window.setFramerateLimit(30);

gamestart:

    // Declaring an object of the class Game
    Game game;

    // Declaring an object from the class piles to set up the cards
    Pile pile;
   
    game.music_start.play();
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        game.time_elapsed1 = game.clock.getElapsedTime();
        window.clear();
        window.draw(game.background);
        window.draw(game.start_button);
        window.draw(game.start);
        window.draw(game.start_message);
        window.draw(game.made_by);
        window.draw(game.tryerz_image);
        window.display();
        if (Mouse::getPosition(window).x >= 675 && Mouse::getPosition(window).x <= 925)
            if (Mouse::getPosition(window).y >= 415 && Mouse::getPosition(window).y <= 485)
                if (event.key.code == Mouse::Left)
                {
                    game.window_start.play();
                    game.music_start.stop();
                    break;
                }
    }

    bool menu = false;
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            switch (event.type)
            {
            case Event::MouseButtonPressed:
                if (event.key.code == Mouse::Left && !menu)
                {
                    Vector2f m = window.mapPixelToCoords(Mouse::getPosition(window));
                    pile.checkIfSpriteIsClicked(m);

                    // If shuffled pile clicked
                    if (Mouse::getPosition(window).x >= 285 && Mouse::getPosition(window).x <= 410)
                        if (Mouse::getPosition(window).y >= 120 && Mouse::getPosition(window).y <= 285)
                        {
                            pile.moveFromShuffledPile();
                            this_thread::sleep_for(chrono::milliseconds(100));
                            break;
                        }
                }
                else if (event.key.code == Mouse::Left && menu)
                {
                    if (Mouse::getPosition(window).x >= 650 && Mouse::getPosition(window).x <= 950)
                        if (Mouse::getPosition(window).y >= 400 && Mouse::getPosition(window).y <= 500)
                            menu = false;
                    if (Mouse::getPosition(window).x >= 650 && Mouse::getPosition(window).x <= 950)
                        if (Mouse::getPosition(window).y >= 530 && Mouse::getPosition(window).y <= 630)
                            goto gamestart;
                    if (Mouse::getPosition(window).x >= 650 && Mouse::getPosition(window).x <= 950)
                        if (Mouse::getPosition(window).y >= 660 && Mouse::getPosition(window).y <= 760)
                            window.close();
                }
            case Event::KeyPressed:
                if (event.key.code == Keyboard::Escape)
                    if (menu == false)
                        menu = true;
                    else if (menu == true)
                        menu = false;
                break;
            case Event::MouseButtonReleased:
                continue;
            default:
                break;
            }                    
        }

        window.clear(); // Clearing the window

        window.draw(game.background);
        window.draw(game.score_board);
        game.drawOutlinePiles(window);

        // Start of drawing the timer
        game.time_elapsed2 = game.clock.getElapsedTime() - game.time_elapsed1;
        int timer_minutes = int(game.time_elapsed2.asSeconds()) / 60;
        int timer_seconds = int(game.time_elapsed2.asSeconds()) % 60;
        if (timer_minutes < 10 && timer_seconds >= 10)
            game.timer.setString("Timer: 0" + to_string(timer_minutes) + ":" + to_string(timer_seconds));
        else if (timer_seconds < 10 && timer_minutes >= 10)
            game.timer.setString("Timer: " + to_string(timer_minutes) + ":0" + to_string(timer_seconds));
        else if (timer_minutes < 10 && timer_seconds < 10)
            game.timer.setString("Timer: 0" + to_string(timer_minutes) + ":0" + to_string(timer_seconds));
        else
            game.timer.setString("Timer: " + to_string(timer_minutes) + ":" + to_string(timer_seconds));
        window.draw(game.timer);
        // End of drawing the timer

        pile.displayCards(window);

        if (menu)
        {
            window.draw(game.menu_box);
            window.draw(game.resume);
            window.draw(game.new_game);
            window.draw(game.quit);
            window.draw(game.menu_text);
            window.draw(game.resume_text);
            window.draw(game.new_game_text);
            window.draw(game.quit_text);
            window.display();
        }
        else
            window.display(); // Displaying the window

        if (pile.gameWon())
            break;
    }


    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.draw(game.blurred_page);
        window.draw(game.you_won);
        window.display();
    }
    
    return 0;
}
