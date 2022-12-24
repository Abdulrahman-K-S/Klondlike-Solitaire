#include "Card.h"

void Deck::setDeck() const
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
            card.img_file.loadFromFile("Assets/cards/" + convert_suits[suit - 1] + " - " + convert_names[name - 1] + ".png");
            cards[index] = card;
            ++index;
        }
    }
}

void Deck::shuffleCards() const
{
    srand(time(nullptr));
    for (int i = 51; i > 0; i--)
    {
        int j = rand() % (i + 1);
        swap(&cards[i], &cards[j]);
    }
}

void Deck::swap(Card* a, Card* b)
{
    Card temp = *a;
    *a = *b;
    *b = temp;
}
