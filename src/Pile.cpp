#include "Pile.h"

Pile::Pile()
{
    Card nullCard;

    for (int i = 0; i < 13; i++)
        normal_pile1[i] = nullCard;

    for (int i = 0; i < 14; i++)
        normal_pile2[i] = nullCard;

    for (int i = 0; i < 15; i++)
        normal_pile3[i] = nullCard;

    for (int i = 0; i < 16; i++)
        normal_pile4[i] = nullCard;

    for (int i = 0; i < 17; i++)
        normal_pile5[i] = nullCard;

    for (int i = 0; i < 18; i++)
        normal_pile6[i] = nullCard;

    for (int i = 0; i < 19; i++)
        normal_pile7[i] = nullCard;
}

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
            normal_pile1[normal_pile1_index++] = cards[i];
            setXYCoordinates(cards[i]);
        }
        else if (i >= 1 && i <= 2) 
        {
            cards[i].pile = CardPile::NORMAL_PILE2;
            normal_pile2[normal_pile2_index++] = cards[i];
            setXYCoordinates(cards[i]);
        }
        else if (i >= 3 && i <= 5) 
        {
            cards[i].pile = CardPile::NORMAL_PILE3;
            normal_pile3[normal_pile3_index++] = cards[i];
            setXYCoordinates(cards[i]);
        }
        else if (i >= 6 && i <= 9) 
        {
            cards[i].pile = CardPile::NORMAL_PILE4;
            normal_pile4[normal_pile4_index++] = cards[i];
            setXYCoordinates(cards[i]);
        }
        else if (i >= 10 && i <= 14) 
        {
            cards[i].pile = CardPile::NORMAL_PILE5;
            normal_pile5[normal_pile5_index++] = cards[i];
            setXYCoordinates(cards[i]);
        }
        else if (i >= 15 && i <= 20) 
        {
            cards[i].pile = CardPile::NORMAL_PILE6;
            normal_pile6[normal_pile6_index++] = cards[i];
            setXYCoordinates(cards[i]);
        }
        else if (i >= 21 && i <= 27) 
        {
            cards[i].pile = CardPile::NORMAL_PILE7;
            normal_pile7[normal_pile7_index++] = cards[i];
            setXYCoordinates(cards[i]);
        }
        else 
        {
            cards[i].pile = CardPile::SHUFFLED_PILE;
            shuffled_pile.push(cards[i]);
            setXYCoordinates(cards[i]);
        }
    }

    //delete[] cards;
}

void Pile::setSpriteTexture()
{
    for (int i = 0; i < 52; i++)
    {
        if (i == 0 || i == 1 || i == 3 || i == 6 || i == 10 || i == 15 || i == 21)
        {
            cards[i].card_sprite.setTexture(cards[i].back_img_file);
            cards[i].card_sprite.setPosition(cards[i].xCoordinate, cards[i].yCoordinate);
            
            if (i == 0)
            {
                cards[i].card_sprite.setTexture(cards[i].front_img_file);
                cards[i].is_flipped = true;
            }
        }
        else if (i == 2 || i == 4 || i == 7 || i == 11 || i == 16 || i == 22)
        {
            cards[i].card_sprite.setTexture(cards[i].back_img_file);
            cards[i].card_sprite.setPosition(cards[i].xCoordinate, cards[i].yCoordinate + 20);
            cards[i].yCoordinate = cards[i].yCoordinate + 20;
            
            if (i == 2)
            {
                cards[i].card_sprite.setTexture(cards[i].front_img_file);
                cards[i].is_flipped = true;
                cards[i].yCoordinate = cards[i].yCoordinate + 20;
            }
        }
        else if (i == 5 || i == 8 || i == 12 || i == 17 || i == 23)
        {
            cards[i].card_sprite.setTexture(cards[i].back_img_file);
            cards[i].card_sprite.setPosition(cards[i].xCoordinate, cards[i].yCoordinate + 40);
            cards[i].yCoordinate = cards[i].yCoordinate + 40;
            
            if (i == 5)
            {
                cards[i].card_sprite.setTexture(cards[i].front_img_file);
                cards[i].is_flipped = true;
                cards[i].yCoordinate = cards[i].yCoordinate + 40;
            }
        }
        else if (i == 9 || i == 13 || i == 18 || i == 24)
        {
            cards[i].card_sprite.setTexture(cards[i].back_img_file);
            cards[i].card_sprite.setPosition(cards[i].xCoordinate, cards[i].yCoordinate + 60);
            cards[i].yCoordinate = cards[i].yCoordinate + 60;
            
            if (i == 9)
            {
                cards[i].card_sprite.setTexture(cards[i].front_img_file);
                cards[i].is_flipped = true;
                cards[i].yCoordinate = cards[i].yCoordinate + 60;
            }
        }
        else if (i == 14 || i == 19 || i == 25)
        {
            cards[i].card_sprite.setTexture(cards[i].back_img_file);
            cards[i].card_sprite.setPosition(cards[i].xCoordinate, cards[i].yCoordinate + 80);
            cards[i].yCoordinate = cards[i].yCoordinate + 80;
            
            if (i == 14)
            {
                cards[i].card_sprite.setTexture(cards[i].front_img_file);
                cards[i].is_flipped = true;
                cards[i].yCoordinate = cards[i].yCoordinate + 80;
            }
        }
        else if (i == 20 || i == 26)
        {
            cards[i].card_sprite.setTexture(cards[i].back_img_file);
            cards[i].card_sprite.setPosition(cards[i].xCoordinate, cards[i].yCoordinate + 100);
            cards[i].yCoordinate = cards[i].yCoordinate + 100;
            
            if (i == 20)
            {
                cards[i].is_flipped = true;
                cards[i].card_sprite.setTexture(cards[i].front_img_file);
            }
        }
        else if (i == 27)
        {            
            cards[i].is_flipped = true;
            cards[i].card_sprite.setTexture(cards[i].front_img_file);
            cards[i].card_sprite.setPosition(cards[i].xCoordinate, cards[i].yCoordinate + 120);
            cards[i].yCoordinate = cards[i].yCoordinate + 120;
        }
        else
        {
            cards[i].card_sprite.setTexture(cards[i].back_img_file);
            cards[i].card_sprite.setPosition(285, 118);
        }
    }
}

void Pile::displayCards(RenderWindow& window)
{
    for (int i = 0; i < shuffled_pile.size(); i++) // Shuffle Pile
        window.draw(shuffled_pile.top().card_sprite);

    for (int i = 0; i < draw_pile.size(); i++) // Draw pile
        window.draw(draw_pile.top().card_sprite);

    // Foundation piles
    for (int i = 0; i < foundation_pile1.size(); i++) // Foundation pile 1
        window.draw(foundation_pile1.top().card_sprite);

    for (int i = 0; i < foundation_pile2.size(); i++) // Foundation pile 2
        window.draw(foundation_pile2.top().card_sprite);

    for (int i = 0; i < foundation_pile3.size(); i++) // Foundation pile 3
        window.draw(foundation_pile3.top().card_sprite);

    for (int i = 0; i < foundation_pile4.size(); i++) // Foundation pile 4
        window.draw(foundation_pile4.top().card_sprite);

    // Normal piles
    for (int i = 0; i <= normal_pile1_index; i++) // Normal pile 1
        window.draw(normal_pile1[i].card_sprite);

    for (int i = 0; i <= normal_pile2_index; i++) // Normal pile 2
        window.draw(normal_pile2[i].card_sprite);

    for (int i = 0; i <= normal_pile3_index; i++) // Normal pile 3
        window.draw(normal_pile3[i].card_sprite);

    for (int i = 0; i <= normal_pile4_index; i++) // Normal pile 4
        window.draw(normal_pile4[i].card_sprite);

    for (int i = 0; i <= normal_pile5_index; i++) // Normal pile 5
        window.draw(normal_pile5[i].card_sprite);

    for (int i = 0; i <= normal_pile6_index; i++) // Normal pile 6
        window.draw(normal_pile6[i].card_sprite);

    for (int i = 0; i <= normal_pile7_index; i++) // Normal pile 7
        window.draw(normal_pile7[i].card_sprite);
}
