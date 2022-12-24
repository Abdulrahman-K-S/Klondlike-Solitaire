#include "Pile.h"

void Pile::setDeck() const
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
            cards[index] = card;
            ++index;
        }
    }
}

void Pile::shuffleCards() const
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
    switch(c.pile){
        case(CardPile::SHUFFLED_PILE):
            c.xyCoordinates[0] = 285;
            c.xyCoordinates[1] = 118;
            break;
        case(CardPile::DRAW_PILE):
            c.xyCoordinates[0] = 0;
            c.xyCoordinates[1] = 118;
            break;
        case(CardPile::FOUNDATION_PILE1):
            c.xyCoordinates[0] = 735;
            c.xyCoordinates[1] = 118;
            break;
        case(CardPile::FOUNDATION_PILE2):
            c.xyCoordinates[0] = 885;
            c.xyCoordinates[1] = 118;
            break;
        case(CardPile::FOUNDATION_PILE3):
            c.xyCoordinates[0] = 1040;
            c.xyCoordinates[1] = 118;
            break;
        case(CardPile::FOUNDATION_PILE4):
            c.xyCoordinates[0] = 1185;
            c.xyCoordinates[1] = 118;
            break;
        case(CardPile::NORMAL_PILE1):
            c.xyCoordinates[0] = 285;
            c.xyCoordinates[1] = 368;
            break;
        case(CardPile::NORMAL_PILE2):
            c.xyCoordinates[0] = 435;
            c.xyCoordinates[1] = 368;
            break;
        case(CardPile::NORMAL_PILE3):
            c.xyCoordinates[0] = 585;
            c.xyCoordinates[1] = 368;
            break;
        case(CardPile::NORMAL_PILE4):
            c.xyCoordinates[0] = 735;
            c.xyCoordinates[1] = 368;
            break;
        case(CardPile::NORMAL_PILE5):
            c.xyCoordinates[0] = 885;
            c.xyCoordinates[1] = 368;
            break;
        case(CardPile::NORMAL_PILE6):
            c.xyCoordinates[0] = 1035;
            c.xyCoordinates[1] = 368;
            break;
        case(CardPile::NORMAL_PILE7):
            c.xyCoordinates[0] = 1185;
            c.xyCoordinates[1] = 368;
            break;
    }
}

void Pile::setPileCards()
{
    for (int i = 0; i < 52; i++)
    {
        if(i == 0){
            cards[i].pile = CardPile::NORMAL_PILE1;
            setXYCoordinates(cards[i]);
        }
        else if(i >= 1 && i <= 2){
            cards[i].pile = CardPile::NORMAL_PILE2;
            setXYCoordinates(cards[i]);
        }
        else if(i >= 3 && i <= 5){
            cards[i].pile = CardPile::NORMAL_PILE3;
            setXYCoordinates(cards[i]);
        }
        else if(i >= 6 && i <= 9){
            cards[i].pile = CardPile::NORMAL_PILE4;
            setXYCoordinates(cards[i]);
        }
        else if(i >= 10 && i <= 14){
            cards[i].pile = CardPile::NORMAL_PILE5;
            setXYCoordinates(cards[i]);
        }
        else if(i >= 15 && i <= 20){
            cards[i].pile = CardPile::NORMAL_PILE6;
            setXYCoordinates(cards[i]);
        }
        else if(i >= 21 && i <= 27){
            cards[i].pile = CardPile::NORMAL_PILE6;
            setXYCoordinates(cards[i]);
        }
        else{
            cards[i].pile = CardPile::SHUFFLED_PILE;
            setXYCoordinates(cards[i]);
        }
    }
}

void Pile::setSpriteTexture()
{
    for (int i = 0; i < 52; i++)
    {
        if(i == 0 || i == 2 || i == 5 || i == 9 || i == 14 || i == 20 || i == 27)
        {
            cards[i].is_flipped = true;
            card_sprites[i].setTexture(cards[i].front_img_file);
            if(i == 0)
            {
                card_sprites[i].setPosition(cards[i].xyCoordinates[0],cards[i].xyCoordinates[1]);
            }
            else
            {
                card_sprites[i].setPosition(cards[i].xyCoordinates[0],cards[i].xyCoordinates[1] + (i * 5.0));
            }
        }
        else
        {
            card_sprites[i].setTexture(cards[i].back_img_file);
            card_sprites[i].setPosition(cards[i].xyCoordinates[0],cards[i].xyCoordinates[1] + (i * 5.0));
        }
    }
}