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
    Sprite* card_sprites = new Sprite[52];
    Sprite* normal_pile1 = new Sprite[13];
    Sprite* normal_pile2 = new Sprite[14];
    Sprite* normal_pile3 = new Sprite[15];
    Sprite* normal_pile4 = new Sprite[16];
    Sprite* normal_pile5 = new Sprite[17];
    Sprite* normal_pile6 = new Sprite[18];
    Sprite* normal_pile7 = new Sprite[19];
    stack<Sprite> foundation_pile1;
    stack<Sprite> foundation_pile2;
    stack<Sprite> foundation_pile3;
    stack<Sprite> foundation_pile4;
    stack<Sprite> shuffled_pile;
    stack<Sprite> draw_pile;
    Card* cards = new Card[52];
    void setDeck() const;
    void shuffleCards() const;
    static void swap(Card*, Card*);
    void setSpriteTexture();
    void setPileCards();
    void setXYCoordinates(Card&);
};
