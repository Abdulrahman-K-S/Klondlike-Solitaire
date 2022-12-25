#include "Pile.h"

void Pile::setDeck()
{
    int index = 0;
    for (int suit = (int)Suits::CLUBS; suit <= (int)Suits::SPADES; ++suit)
    {
        for (int name = (int)CardNames::ACE; name <= (int)CardNames::KING; ++name)
        {
            Card card;
            if (suit == (int)Suits::CLUBS || suit == (int)Suits::SPADES)
            {
                card.color = CardColor::BLACK;
            }
            else
            {
                card.color = CardColor::RED;
            }
            card.name = (CardNames)name;
            card.suit = (Suits)suit;
            card.is_flipped = false;
            card.front_img_file.loadFromFile("Assets/Cards/" + convert_suits[suit - 1] + " - " + convert_names[name - 1] + ".png");
            //card.card_sprite.setTexture()
            cards[index] = card;
            ++index;
        }
    }
}

void Pile::shuffleCards()
{
    srand(time(nullptr));
    for (int i = 51; i > 0; i--)
    {
        int j = rand() % (i + 1);
        swap(&cards[i], &cards[j]);
    }
}

void Pile::swap(Card* a, Card* b)
{
    Card temp = *a;
    *a = *b;
    *b = temp;
}

void Pile::setXYCoordinates(Card& c) {
    switch (c.pile) {
    case(CardPile::SHUFFLED_PILE):
        c.xCoordinate = 285;
        c.yCoordinate = 118;
        break;
    case(CardPile::DRAW_PILE):
        c.xCoordinate = 0;
        c.yCoordinate = 118;
        break;
    case(CardPile::NORMAL_PILE1):
        c.xCoordinate = 285;
        c.yCoordinate = 368;
        break;
    case(CardPile::NORMAL_PILE2):
        c.xCoordinate = 435;
        c.yCoordinate = 368;
        break;
    case(CardPile::NORMAL_PILE3):
        c.xCoordinate = 585;
        c.yCoordinate = 368;
        break;
    case(CardPile::NORMAL_PILE4):
        c.xCoordinate = 735;
        c.yCoordinate = 368;
        break;
    case(CardPile::NORMAL_PILE5):
        c.xCoordinate = 885;
        c.yCoordinate = 368;
        break;
    case(CardPile::NORMAL_PILE6):
        c.xCoordinate = 1035;
        c.yCoordinate = 368;
        break;
    case(CardPile::NORMAL_PILE7):
        c.xCoordinate = 1185;
        c.yCoordinate = 368;
        break;
    }
}

void Pile::setPileCards()
{
    for (int i = 0; i < 52; i++)
    {
        if (i == 0) 
        {
            cards[i].pile = CardPile::NORMAL_PILE1;
            setXYCoordinates(cards[i]);
        }
        else if (i >= 1 && i <= 2) 
        {
            cards[i].pile = CardPile::NORMAL_PILE2;
            setXYCoordinates(cards[i]);
        }
        else if (i >= 3 && i <= 5) 
        {
            cards[i].pile = CardPile::NORMAL_PILE3;
            setXYCoordinates(cards[i]);
        }
        else if (i >= 6 && i <= 9) 
        {
            cards[i].pile = CardPile::NORMAL_PILE4;
            setXYCoordinates(cards[i]);
        }
        else if (i >= 10 && i <= 14) 
        {
            cards[i].pile = CardPile::NORMAL_PILE5;
            setXYCoordinates(cards[i]);
        }
        else if (i >= 15 && i <= 20) 
        {
            cards[i].pile = CardPile::NORMAL_PILE6;
            setXYCoordinates(cards[i]);
        }
        else if (i >= 21 && i <= 27) 
        {
            cards[i].pile = CardPile::NORMAL_PILE7;
            setXYCoordinates(cards[i]);
        }
        else 
        {
            cards[i].pile = CardPile::SHUFFLED_PILE;
            draw_pile.push(cards[i]);
            setXYCoordinates(cards[i]);
        }
    }
}

void Pile::setSpriteTexture()
{
    for (int i = 0; i < 52; i++)
    {
        if (i == 0 || i == 2 || i == 5 || i == 9 || i == 14 || i == 20 || i == 27)
        {
            cards[i].is_flipped = true;
            cards[i].card_sprite.setTexture(cards[i].front_img_file);
            if (i == 0)
            {
                cards[i].card_sprite.setPosition(cards[i].xCoordinate, cards[i].yCoordinate);
            }
            else
            {
                cards[i].card_sprite.setPosition(cards[i].xCoordinate, cards[i].yCoordinate + (i * 5.0));
            }
        }
        else
        {
            cards[i].card_sprite.setTexture(cards[i].back_img_file);
            cards[i].card_sprite.setPosition(285, 118);
        }
    }
}
