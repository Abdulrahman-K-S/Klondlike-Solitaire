// Including the sfml and iostream libraires
#include <SFML/Graphics.hpp>
#include <iostream>

// Including the different classes
#include "Piles.h"

// Using Namespace
using namespace sf;
using namespace std;

// Global Variables

// The 12 outlines
Piles pilesArr[12] = {Piles(290,120), Piles(740,120), Piles(890,120),
                    Piles(1040,120), Piles(1190,120), Piles(290, 370),
                    Piles(440, 370), Piles(590, 370), Piles(740, 370),
                    Piles(890,370), Piles(1040,370), Piles(1190,370)};


void DrawPiles(RenderWindow &window)
{
    for (int i = 0; i < 12; i++)
        window.draw(pilesArr[i].getShape());
}

int main()
{
    RenderWindow window(VideoMode(1600, 900), "Solitaire");

    // Setting up the background of the game
    Texture backgroundTex;
    backgroundTex.loadFromFile("Background.jpg");
    Sprite backgroundSpr(backgroundTex);

    // Setting up the Scoreboard
    RectangleShape scoreBoard(Vector2f(1600,80));
    scoreBoard.setFillColor(Color(169, 169, 169, 128));

    //Setting the font and adding the score text
    Font scoreFont;
    scoreFont.loadFromFile("MartianMono-VariableFont_wdth,wght.ttf");
    Text score;
    score.setFont(scoreFont);
    score.setString("Score: 00");
    score.setCharacterSize(20);
    score.setPosition(730, 30);


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
        window.draw(scoreBoard);
        DrawPiles(window);
        window.draw(score);
        window.display();
    }

    return 0;
}
