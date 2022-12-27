#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <chrono>
#include <thread>

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

void MoveSuffledCard(RenderWindow& window, stack<Card> &shuffled_pile)
{
    //cout << "Shuffled pile clicked\n";
    //cout << shuffled_pile.empty() << endl;
    if (!shuffled_pile.empty())
    {
        Card drawCard = shuffled_pile.top();
        shuffled_pile.pop();

        drawCard.card_sprite.setPosition(410, 290);
        window.draw(drawCard.card_sprite);
        window.display();
        this_thread::sleep_for(chrono::seconds(15));
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
    Time timeElapsed2;
    Timer.setFont(scoreFont);
    Timer.setCharacterSize(20);
    Timer.setPosition(800, 30);

    // Declaring an object from the class piles to set up the whole game
    Pile pile;
    pile.setDeck();
    pile.shuffleCards();
    pile.setPileCards();
    pile.setSpriteTexture();

    //Adding a sound effect for start
    SoundBuffer StartBuffer;
    StartBuffer.loadFromFile("Assets/Sounds/Start Sound.wav");
    Sound StartSound;
    StartSound.setBuffer(StartBuffer);

    // Declaring an object of the class Mouse
    Mouse mouse;

    /*while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        RectangleShape StartButton(Vector2f(250, 70));
        StartButton.setPosition(Vector2f(675, 415));
        StartButton.setFillColor(Color(0, 181, 212, 700));
        timeElapsed1 = clock.getElapsedTime();
        window.clear();
        window.draw(backgroundSpr);
        Text Start;
        Text StartMessage;
        Start.setFont(scoreFont);
        Start.setString("Start");
        Start.setCharacterSize(25);
        Start.setPosition(750, 435);
        StartMessage.setFont(scoreFont);
        StartMessage.setString("Welcome to our Solitaire!!\n\n\n\n\n\n\n   Press start to begin");
        StartMessage.setCharacterSize(25);
        StartMessage.setPosition(546, 300);
        window.draw(StartButton);
        window.draw(Start);
        window.draw(StartMessage);
        window.display();
        if (mouse.getPosition(window).x >= 675 && mouse.getPosition(window).x <= 925)
            if (mouse.getPosition(window).y >= 415 && mouse.getPosition(window).y <= 485)
                if (event.key.code == mouse.Left)
                {
                    StartSound.play();
                    break;
                }
    }*/

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
                    switch (event.type)
                    {
                    case Event::MouseButtonPressed:
                        if (event.key.code == Mouse::Left)
                        {
                            cout << "Shuffled pile clicked\n";
                            this_thread::sleep_for(chrono::milliseconds(300));
                            MoveSuffledCard(window, pile.shuffled_pile);
                            break;
                        }
                    case Event::MouseButtonReleased:
                        continue;
                    default:
                        break;
                    }
        }

        //MoveSuffledCard(window, pile);
        window.clear(); // Clearing the window

        window.draw(backgroundSpr);
        window.draw(scoreBoard);
        DrawPiles(window);

        // Start of drawing the timer
        timeElapsed2 = clock.getElapsedTime() - timeElapsed1;
        int Minutes = int(timeElapsed2.asSeconds()) / 60;
        int Seconds = int(timeElapsed2.asSeconds()) % 60;
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

        //pile.displayCards(window);

        for (int i = 0; i < pile.normal_pile7_index; i++)
            window.draw(pile.normal_pile7[i].card_sprite);

        window.draw(score);
        window.display(); // Displaying the window
    }

    return 0;
}
