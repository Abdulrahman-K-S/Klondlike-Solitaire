#include "Card.h"

Card::Card()
{
    is_flipped = false;
    front_img_file.loadFromFile("Assets/Cards/BACK.png");
    back_img_file.loadFromFile("Assets/Cards/BACK.png");
    card_sprite.setTexture(back_img_file);
    xCoordinate = 0;
    yCoordinate = 0;
}

Card::Card(const Card& c)
{
    suit = c.suit;
    name = c.name;
    color = c.color;
    pile = c.pile;
    is_flipped = c.is_flipped;
    front_img_file = c.front_img_file;
    back_img_file = c.back_img_file;
    card_sprite = c.card_sprite;
    xCoordinate = c.xCoordinate;
    yCoordinate = c.yCoordinate;
}

Card& Card::operator=(const Card& c)
{
    suit = c.suit;
    name = c.name;
    color = c.color;
    pile = c.pile;
    is_flipped = c.is_flipped;
    front_img_file = c.front_img_file;
    back_img_file = c.back_img_file;
    card_sprite = c.card_sprite;
    xCoordinate = c.xCoordinate;
    yCoordinate = c.yCoordinate; 
    return *this;
}
