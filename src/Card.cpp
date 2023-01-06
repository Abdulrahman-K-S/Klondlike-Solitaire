#include "Card.h"

Card::Card()
{
    is_flipped = false;
    front_img_file.loadFromFile("Assets/Cards/BACK.png");
    back_img_file.loadFromFile("Assets/Cards/BACK.png");
    card_sprite.setTexture(back_img_file);
    x_coordinate = 0;
    y_coordinate = 0;
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
    x_coordinate = c.x_coordinate;
    y_coordinate = c.y_coordinate;
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
    x_coordinate = c.x_coordinate;
    y_coordinate = c.y_coordinate; 
    return *this;
}

bool operator==(const Card& lhs, const Card& rhs)
{
    if (lhs.color == rhs.color)
        if (lhs.name == rhs.name)
            if (lhs.suit == rhs.suit)
                return true;
    return false;
}
