#include <iostream>
#include "Pile.h"
#include "Game.h"

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
                    Vector2f mouse_position = window.mapPixelToCoords(Mouse::getPosition(window));
                    pile.checkIfSpriteIsClicked(mouse_position);

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
                        {
                            game.window_start.play();
                            menu = false;
                        }
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
                    {
                        game.window_start.play();
                        menu = true;
                    }
                    else if (menu == true)
                    {
                        game.window_start.play();
                        menu = false;
                    }
                break;
            }
        }

        window.clear(); // Clearing the window

        window.draw(game.background);
        window.draw(game.score_board);
        window.draw(game.drawTimer());
        game.drawOutlinePiles(window);

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

        if (pile.gameWon()) {
            break;
        }
    }

    game.setEndMenuButton();
    game.winning_theme_music.play();
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            else if (event.MouseButtonPressed && event.key.code == Mouse::Left)
            {
                if (Mouse::getPosition(window).x >= 470 && Mouse::getPosition(window).x <= 770)
                    if (Mouse::getPosition(window).y >= 555 && Mouse::getPosition(window).y <= 630)
                        goto gamestart;
                if (Mouse::getPosition(window).x >= 920 && Mouse::getPosition(window).x <= 1130)
                    if (Mouse::getPosition(window).y >= 555 && Mouse::getPosition(window).y <= 630)
                        window.close();

            }
        }

        window.draw(game.blurred_page);
        window.draw(game.you_won);
        window.draw(game.quit);
        window.draw(game.new_game);
        window.draw(game.new_game_text);
        window.draw(game.quit_text);
        window.draw(game.timer);
        window.display();
    }

    return 0;
}
