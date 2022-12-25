#include <SFML/Graphics.hpp>
#include <iostream>
#include <stack>
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
    null
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
    KING,
    null
};

// An enum class whether it's a red card
// or a black card
enum class CardColor
{
    RED,
    BLACK,
    null
};

enum class CardPile{
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
    FOUNDATION_PILE4,
};

static string convert_suits[] = {
        stringify(CLUBS),
        stringify(DIAMONDS),
        stringify(HEARTS),
        stringify(SPADES)
};

static string convert_names[] = {
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
    Card() {
        suit = Suits::null;
        name = CardNames::null;
        color = CardColor::null;
        pile = CardPile::SHUFFLED_PILE;
        is_flipped = false;
        front_img_file.loadFromFile("Assets/Cards/BACK.png");
        back_img_file.loadFromFile("Assets/Cards/BACK.png");
        card_sprite.setTexture(back_img_file);
        xyCoordinates[0] = 0;
        xyCoordinates[1] = 0;
    }
    Suits suit;
    CardNames name;
    CardColor color;
    CardPile pile;
    bool is_flipped;
    Texture front_img_file;
    Texture back_img_file;
    Sprite card_sprite;
    float *xyCoordinates = new float[2];
};
