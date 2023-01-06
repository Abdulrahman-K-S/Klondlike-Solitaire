#include <SFML/Graphics.hpp>
#include <iostream>
#include <stack>
#include <random>
#define stringify( name ) #name

using namespace sf;
using namespace std;

enum class Suits
{
    CLUBS = 1,
    DIAMONDS,
    HEARTS,
    SPADES
};
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

enum class CardColor
{
    RED,
    BLACK
};

enum class CardPile 
{
    SHUFFLED_PILE,
    DRAW_PILE,
    NORMAL_PILE1,
    NORMAL_PILE2,
    NORMAL_PILE3,
    NORMAL_PILE4,
    NORMAL_PILE5,
    NORMAL_PILE6,
    NORMAL_PILE7,
    FOUNDATION_PILE1,
    FOUNDATION_PILE2,
    FOUNDATION_PILE3,
    FOUNDATION_PILE4
};

static string convert_suits[] = 
{
        stringify(CLUBS),
        stringify(DIAMONDS),
        stringify(HEARTS),
        stringify(SPADES)
};

static string convert_names[] = 
{
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
    Card();
    Card(const Card&);
    Card& operator=(const Card&);
    friend bool operator==(const Card&, const Card&);

    Suits suit;
    CardNames name;
    CardColor color;
    CardPile pile;
    bool is_flipped;
    Texture front_img_file, back_img_file;
    Sprite card_sprite;
    float x_coordinate, y_coordinate;
};
