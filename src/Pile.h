#include <SFML/Graphics.hpp>
#include <iostream>
#include "Card.h"
#include <stack>
#include <random>

using namespace sf;
using namespace std;

class Pile
{
public:
    Card* card_sprites = new Card[52];
    Card* normal_pile1 = new Card[13];
    Card* normal_pile2 = new Card[14];
    Card* normal_pile3 = new Card[15];
    Card* normal_pile4 = new Card[16];
    Card* normal_pile5 = new Card[17];
    Card* normal_pile6 = new Card[18];
    Card* normal_pile7 = new Card[19];
    stack<Card> foundation_pile1;
    stack<Card> foundation_pile2;
    stack<Card> foundation_pile3;
    stack<Card> foundation_pile4;
    stack<Card> shuffled_pile;
    stack<Card> draw_pile;
    Card cards[52];
    void setDeck();
    void shuffleCards();
    static void swap(Card*, Card*);
    void setSpriteTexture();
    void setPileCards();
    void setXYCoordinates(Card&);
};
