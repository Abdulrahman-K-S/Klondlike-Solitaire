// Including the sfml and iostream libraires
#include <SFML/Graphics.hpp>
#include <iostream>

// Including the different classes
#include "OutlinePile.h"
#include "Card.h"

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

    // Declaring and setting up the deck of cards
    Deck deck;
    deck.setDeck();
    deck.shuffleCards();

    // Declaring the 52 sprite cards
    Sprite card_sprites[52];
    Sprite normal_pile1[13]; //* Not necessarily haykono 13
    Sprite normal_pile2[14]; //* Not necessarily haykono 14
    Sprite normal_pile3[15]; //* Not necessarily haykono 15
    Sprite normal_pile4[16]; //* Not necessarily haykono 16
    Sprite normal_pile5[17]; //* Not necessarily haykono 17
    Sprite normal_pile6[18]; //* Not necessarily haykono 18
    Sprite normal_pile7[19]; //* Not necessarily haykono 19
    stack<Sprite> foundation_pile1;
    stack<Sprite> foundation_pile2;
    stack<Sprite> foundation_pile3;
    stack<Sprite> foundation_pile4;
    stack<Sprite> shuffled_pile; // We'll need 2 stacks, 1 for the covered
    stack<Sprite> draw_pile; //* cards and the other for the uncovered ones
    for (int i = 0; i < 52; i++)
    {
        card_sprites[i].setTexture(deck.cards[i].back_img);
        card_sprites[i].setPosition(Vector2f(285, 118));
    }

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
        for (int i = 0; i < 52; i++)
            window.draw(card_sprites[i]);
        window.display();
    }

    return 0;
}
