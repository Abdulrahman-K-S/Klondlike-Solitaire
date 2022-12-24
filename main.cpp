// Including the sfml and iostream libraires
#include <SFML/Graphics.hpp>
#include <iostream>

// Including the different classes
#include "src/OutlinePile.h"
#include "src/Pile.h"

// Using Namespace
using namespace sf;
using namespace std;

// Global Variables:

// The 12 outline piles
OutlinePile pilesArr[12] = {OutlinePile(290,120),OutlinePile(740,120), OutlinePile(890,120),
                            OutlinePile(1040,120), OutlinePile(1190,120), OutlinePile(290, 370),
                            OutlinePile(440, 370), OutlinePile(590, 370), OutlinePile(740, 370),
                            OutlinePile(890,370), OutlinePile(1040,370), OutlinePile(1190,370)};

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
    backgroundTex.loadFromFile("Assets/Background.jpg");
    Sprite backgroundSpr(backgroundTex);

    // Setting up the Scoreboard
    RectangleShape scoreBoard(Vector2f(1600,80));
    scoreBoard.setFillColor(Color(169, 169, 169, 128));

    //Setting the font and adding the score text
    Font scoreFont;
    scoreFont.loadFromFile("Assets/Martian_Mono/MartianMono-VariableFont_wdth,wght.ttf");
    Text score;
    score.setFont(scoreFont);
    score.setString("Score: 00");
    score.setCharacterSize(20);
    score.setPosition(730, 30);

    Pile pile;
    pile.setDeck();
    pile.shuffleCards();
    pile.setPileCards();
    pile.setSpriteTexture();


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
        for(int i = 0; i < 52; ++i){
            window.draw(pile.cards[i].card_sprite);
        }
        window.display();
    }

    return 0;
}
