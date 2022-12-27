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
    Card* normal_pile1 = new Card[13];
    int normal_pile1_index = 0;

    Card* normal_pile2 = new Card[14];
    int normal_pile2_index = 0;

    Card* normal_pile3 = new Card[15];
    int normal_pile3_index = 0;

    Card* normal_pile4 = new Card[16];
    int normal_pile4_index = 0;

    Card* normal_pile5 = new Card[17];
    int normal_pile5_index = 0;

    Card* normal_pile6 = new Card[18];
    int normal_pile6_index = 0;

    Card* normal_pile7 = new Card[19];
    int normal_pile7_index = 0;

    stack<Card> foundation_pile1;
    stack<Card> foundation_pile2;
    stack<Card> foundation_pile3;
    stack<Card> foundation_pile4;
    stack<Card> shuffled_pile;
    stack<Card> draw_pile;

    Card* cards = new Card[52];
    Pile();
    void setDeck();
    void shuffleCards();
    void swap(Card*, Card*);
    void setSpriteTexture();
    void setPileCards();
    void setXYCoordinates(Card&);

    void displayCards(RenderWindow& window);
};
