#include <SFML/Graphics.hpp>
#include <iostream>

// Including the different classes
#include "OutlinePile.h"
#include "Pile.h"
//#include "Game.cpp"

// Using Namespace
using namespace sf;
using namespace std;

// Global Variables:

// The 12 outline piles
OutlinePile pilesArr[12] = { OutlinePile(290,120),OutlinePile(740,120), OutlinePile(890,120),
                             OutlinePile(1040,120), OutlinePile(1190,120), OutlinePile(290, 370),
                             OutlinePile(440, 370), OutlinePile(590, 370), OutlinePile(740, 370),
                             OutlinePile(890,370), OutlinePile(1040,370), OutlinePile(1190,370) };

void MoveSuffledCard(RenderWindow& window, Pile pile)
{
    //cout << "Shuffled pile clicked\n";
    //cout << pile.draw_pile.empty();
    if (pile.draw_pile.empty())
    {
        Card topCard = pile.draw_pile.top();

        while (topCard.card_sprite.getPosition().x != 460)
        {
            topCard.card_sprite.move(10, 0);
            cout << "here";
        }
    }
    else
    {

    }
}

void DrawPiles(RenderWindow& window)
{
    for (int i = 0; i < 12; i++)
        window.draw(pilesArr[i].getShape());
}

int main()
{
    RenderWindow window(VideoMode(1600, 900), "Solitaire");
    window.setFramerateLimit(5);


    // Setting up the background of the game
    Texture backgroundTex;
    backgroundTex.loadFromFile("Assets/Background.jpg");
    Sprite backgroundSpr(backgroundTex);

    // Setting up the Scoreboard
    RectangleShape scoreBoard(Vector2f(1600, 80));
    scoreBoard.setFillColor(Color(169, 169, 169, 128));

    // Setting the font and adding the score text
    Font scoreFont;
    scoreFont.loadFromFile("Assets/Martian_Mono/MartianMono-VariableFont_wdth,wght.ttf");
    Text score;
    score.setFont(scoreFont);
    score.setString("Score: 00");
    score.setCharacterSize(20);
    score.setPosition(600, 30);

    // Setting the timer for the game (Which starts once the game has begun)
    Text Timer;
    Clock clock;
    Time timeElapsed1;
    Timer.setFont(scoreFont);
    Timer.setCharacterSize(20);
    Timer.setPosition(800, 30);

    // Declaring an object from the class piles to set up the whole game
    Pile pile;
    pile.setDeck();
    pile.shuffleCards();
    pile.setPileCards();
    pile.setSpriteTexture();

    // Declaring an object of the class Mouse
    Mouse mouse;


    // While loop for the welcome message to the game
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(backgroundSpr);

        Text Start;
        Start.setFont(scoreFont);
        Start.setString("Start");
        Start.setCharacterSize(20);
        Start.setPosition(600, 30);
        window.draw(Start);
        window.display();
        if (mouse.getPosition(window).x >= 600 && mouse.getPosition(window).x <= 620)
            if (mouse.getPosition(window).y >= 30 && mouse.getPosition(window).y <= 50)
                if (event.key.code == mouse.Left)
                {
                    cout << "Start button clicked\n";
                    break;
                }
    }
    // End of the while loop for the message display


    // Start of the while loop for the gameplay
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        
            // If shuffled pile clicked
            if (mouse.getPosition(window).x >= 285 && mouse.getPosition(window).x <= 410)
                if (mouse.getPosition(window).y >= 118 && mouse.getPosition(window).y <= 283)
                    if (event.key.code == mouse.Left)
                    {
                        //MoveSuffledCard(window, pile);
                        cout << "Shuffled pile clicked\n";
                        while (mouse.getPosition(window).x >= 285 && mouse.getPosition(window).x <= 410 && mouse.getPosition(window).y >= 118 && mouse.getPosition(window).y <= 283)
                        {
                            continue;
                        }
                    }
        }


        //MoveSuffledCard(window, pile);
        window.clear(); // Clearing the window

        window.draw(backgroundSpr);
        window.draw(scoreBoard);
        DrawPiles(window);

        // Start of drawing the timer
        Time timeElapsed1 = clock.getElapsedTime();
        int Minutes = int(timeElapsed1.asSeconds()) / 60;
        int Seconds = int(timeElapsed1.asSeconds()) % 60;
        if (Minutes < 10 && Seconds >= 10)
            Timer.setString("Timer: 0" + to_string(Minutes) + ":" + to_string(Seconds));
        else if (Seconds < 10 && Minutes >= 10)
            Timer.setString("Timer: " + to_string(Minutes) + ":0" + to_string(Seconds));
        else if (Minutes < 10 && Seconds < 10)
            Timer.setString("Timer: 0" + to_string(Minutes) + ":0" + to_string(Seconds));
        else
            Timer.setString("Timer: " + to_string(Minutes) + ":" + to_string(Seconds));
        window.draw(Timer);
        // End of drawing the timer

        window.draw(score);

        for (int i = 0; i < 52; ++i) {
            window.draw(pile.cards[i].card_sprite);
        }

        window.display(); // Displaying the window
    }
    // End of the while loop for the gameplay

    return 0;
}

