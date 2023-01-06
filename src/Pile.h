#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include "Card.h"
#include <stack>
#include <random>
#include <vector>

using namespace sf;
using namespace std;

class Pile
{
public:
    SoundBuffer card_click_buffer, card_shuffle_buffer, card_error_buffer;
    Sound card_click_sound, card_shuffle_sound, card_error_sound;

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
    void setSounds();
    void setDeck();
    void shuffleCards();
    void swap(Card*, Card*);

    void setSpriteTexture();
    void setSpriteTexture(vector<Card>&);

    void setSpriteTexture(int);
	void setSpriteTexture(stack<Card>&, int, int);
	void setSpriteTexture(vector<Card>&, int, int);

	void setPileCards();

    void setXYCoordinates(Card&);

    void displayCards(RenderWindow&);
    void displayCards(RenderWindow&, stack<Card>&);
    void displayCards(RenderWindow&, vector<Card>&, int);

    void checkIfSpriteIsClicked(Vector2f);
	bool checkIfSpriteIsClicked(Vector2f, FloatRect, int, stack<Card>&, vector<Card>&);
	bool checkIfSpriteIsClicked(Vector2f, FloatRect, int, stack<Card>&, vector<Card>&, int);

    void moveCard(int, stack<Card>&, vector<Card>&, int);

    void moveFromShuffledPile();

    void moveFromDrawPile();
    bool moveFromDrawPile(stack<Card>&, int);
    bool moveFromDrawPile(vector<Card>&, int);

    void moveFromFoundationPile(stack<Card>&);
    bool moveFromFoundationPile(stack<Card>&, stack<Card>&, int);
    bool moveFromFoundationPile(vector<Card>&, stack<Card>&, int);

    void moveFromNormalPile(vector<Card>&, int);
    bool moveFromNormalPile(stack<Card>&, vector<Card>&, int, int);
    bool moveFromNormalPile(vector<Card>&, vector<Card>&, int, int);

    bool gameWon();
};
