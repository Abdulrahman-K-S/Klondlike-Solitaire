#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Card.h"
#include <stack>
#include <random>
#include <vector>

using namespace sf;
using namespace std;

class Pile
{
public:
    SoundBuffer card_click_buffer, card_shuffle_buffer;
    Sound card_click_sound, card_shuffle_sound;

    vector<Card> normal_pile1;
    vector<Card> normal_pile2;
    vector<Card> normal_pile3;
	vector<Card> normal_pile4;
	vector<Card> normal_pile5;
    vector<Card> normal_pile6;
    vector<Card> normal_pile7;

    stack<Card> shuffled_pile;
    stack<Card> draw_pile;

    stack<Card> foundation_pile1;
    stack<Card> foundation_pile2;
    stack<Card> foundation_pile3;
    stack<Card> foundation_pile4;

    Card* cards = new Card[52];

    int offset = 25;

    Pile();
    void setDeck();
    void shuffleCards();
    void swap(Card*, Card*);
    
    void setSpriteTexture();
    void setSpriteTexture(int pile_number);
    void setPileCards();
    void setXYCoordinates(Card&);

    void displayCards(RenderWindow& window);

    void MoveShuffledCard();
    void checkIfSpriteIsClicked(Vector2f mouse);

    void MoveCard(int pile_number);
    void MoveFromDrawPile();
    void MoveFromFoundationPile1();
    void MoveFromFoundationPile2();
    void MoveFromFoundationPile3();
    void MoveFromFoundationPile4();
    void MoveFromNormalPile1();
    void MoveFromNormalPile2();
};
