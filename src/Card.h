#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#define stringify( name ) #name

using namespace sf;
using namespace std;

// An enum class for the 4 suits
enum class Suits
{
    CLUBS = 1,
    DIAMONDS,
    HEARTS,
    SPADES,
};

// An enum class for the card-names from it being
// an ace to it being a king
enum class CardNames
{
    ACE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
};

// An enum class whether it's a red card
// or a black card
enum class CardColor
{
    RED,
    BLACK
};

string convert_suits[] ={
        stringify(CLUBS),
        stringify(DIAMONDS),
        stringify(HEARTS),
        stringify(SPADES)
};

string convert_names[] ={
        stringify(ACE),
        stringify(TWO),
        stringify(THREE),
        stringify(FOUR),
        stringify(FIVE),
        stringify(SIX),
        stringify(SEVEN),
        stringify(EIGHT),
        stringify(NINE),
        stringify(TEN),
        stringify(JACK),
        stringify(QUEEN),
        stringify(KING)
};

class Card
{
    public:
        Suits suit;
        CardNames name;
        CardColor color;
        bool is_flipped;
        Texture img_file;
};

class Deck
{   
    public:
        Card *cards = new Card [52];
        void setDeck() const;
        void shuffleCards() const;
        static void swap(Card *a, Card *b);
};
