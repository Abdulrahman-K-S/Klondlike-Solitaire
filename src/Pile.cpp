#include "Pile.h"

Pile::Pile()
{
    card_click_buffer.loadFromFile("Assets/Sounds/Card Click.wav");
    card_shuffle_buffer.loadFromFile("Assets/Sounds/Card Shuffle.wav");
    card_click_sound.setBuffer(card_click_buffer);
    card_shuffle_sound.setBuffer(card_shuffle_buffer);
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

void Pile::setXYCoordinates(Card& c)
{
    switch (c.pile)
    {
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
            normal_pile1.push_back(cards[i]);
        }
        else if (i >= 1 && i <= 2)
        {
            cards[i].pile = CardPile::NORMAL_PILE2;
            setXYCoordinates(cards[i]);
            normal_pile2.push_back(cards[i]);
        }
        else if (i >= 3 && i <= 5)
        {
            cards[i].pile = CardPile::NORMAL_PILE3;
            setXYCoordinates(cards[i]);
            normal_pile3.push_back(cards[i]);
        }
        else if (i >= 6 && i <= 9)
        {
            cards[i].pile = CardPile::NORMAL_PILE4;
            setXYCoordinates(cards[i]);
            normal_pile4.push_back(cards[i]);
        }
        else if (i >= 10 && i <= 14)
        {
            cards[i].pile = CardPile::NORMAL_PILE5;
            setXYCoordinates(cards[i]);
            normal_pile5.push_back(cards[i]);
        }
        else if (i >= 15 && i <= 20)
        {
            cards[i].pile = CardPile::NORMAL_PILE6;
            setXYCoordinates(cards[i]);
            normal_pile6.push_back(cards[i]);
        }
        else if (i >= 21 && i <= 27)
        {
            cards[i].pile = CardPile::NORMAL_PILE7;
            setXYCoordinates(cards[i]);
            normal_pile7.push_back(cards[i]);
        }
        else
        {
            cards[i].pile = CardPile::SHUFFLED_PILE;
            setXYCoordinates(cards[i]);
            shuffled_pile.push(cards[i]);
            setSpriteTexture(1);
        }
    }
}

void Pile::setSpriteTexture()
{
    // First Card
    normal_pile1.front().card_sprite.setTexture(normal_pile1.front().front_img_file);
    normal_pile1.front().card_sprite.setPosition(normal_pile1.front().xCoordinate, normal_pile1.front().yCoordinate);
    normal_pile1.front().is_flipped = true;

    for (int i = 0; i < normal_pile2.size(); ++i)
    {
        normal_pile2.at(i).card_sprite.setTexture(normal_pile2.at(i).back_img_file);
        normal_pile2.at(i).card_sprite.setPosition(normal_pile2.at(i).xCoordinate, normal_pile2.at(i).yCoordinate + (i * offset));

        if (i == normal_pile2.size() - 1)
        {
            normal_pile2.at(i).card_sprite.setTexture(normal_pile2.at(i).front_img_file);
            normal_pile2.at(i).card_sprite.setPosition(normal_pile2.at(i).xCoordinate, normal_pile2.at(i).yCoordinate + (i * offset));
            normal_pile2.at(i).is_flipped = true;
        }
    }

    for (int i = 0; i < normal_pile3.size(); ++i)
    {
        normal_pile3.at(i).card_sprite.setTexture(normal_pile3.at(i).back_img_file);
        normal_pile3.at(i).card_sprite.setPosition(normal_pile3.at(i).xCoordinate, normal_pile3.at(i).yCoordinate + (i * offset));

        if (i == normal_pile3.size() - 1)
        {
            normal_pile3.at(i).card_sprite.setTexture(normal_pile3.at(i).front_img_file);
            normal_pile3.at(i).card_sprite.setPosition(normal_pile3.at(i).xCoordinate, normal_pile3.at(i).yCoordinate + (i * offset));
            normal_pile3.at(i).is_flipped = true;
        }
    }

    for (int i = 0; i < normal_pile4.size(); ++i)
    {
        normal_pile4.at(i).card_sprite.setTexture(normal_pile4.at(i).back_img_file);
        normal_pile4.at(i).card_sprite.setPosition(normal_pile4.at(i).xCoordinate, normal_pile4.at(i).yCoordinate + (i * offset));

        if (i == normal_pile4.size() - 1)
        {
            normal_pile4.at(i).card_sprite.setTexture(normal_pile4.at(i).front_img_file);
            normal_pile4.at(i).card_sprite.setPosition(normal_pile4.at(i).xCoordinate, normal_pile4.at(i).yCoordinate + (i * offset));
            normal_pile4.at(i).is_flipped = true;
        }
    }

    for (int i = 0; i < normal_pile5.size(); ++i)
    {
        normal_pile5.at(i).card_sprite.setTexture(normal_pile5.at(i).back_img_file);
        normal_pile5.at(i).card_sprite.setPosition(normal_pile5.at(i).xCoordinate, normal_pile5.at(i).yCoordinate + (i * offset));

        if (i == normal_pile5.size() - 1)
        {
            normal_pile5.at(i).card_sprite.setTexture(normal_pile5.at(i).front_img_file);
            normal_pile5.at(i).card_sprite.setPosition(normal_pile5.at(i).xCoordinate, normal_pile5.at(i).yCoordinate + (i * offset));
            normal_pile5.at(i).is_flipped = true;
        }
    }

    for (int i = 0; i < normal_pile6.size(); ++i)
    {
        normal_pile6.at(i).card_sprite.setTexture(normal_pile6.at(i).back_img_file);
        normal_pile6.at(i).card_sprite.setPosition(normal_pile6.at(i).xCoordinate, normal_pile6.at(i).yCoordinate + (i * offset));

        if (i == normal_pile6.size() - 1)
        {
            normal_pile6.at(i).card_sprite.setTexture(normal_pile6.at(i).front_img_file);
            normal_pile6.at(i).card_sprite.setPosition(normal_pile6.at(i).xCoordinate, normal_pile6.at(i).yCoordinate + (i * offset));
            normal_pile6.at(i).is_flipped = true;
        }
    }
    for (int i = 0; i < normal_pile7.size(); ++i)
    {
        normal_pile7.at(i).card_sprite.setTexture(normal_pile7.at(i).back_img_file);
        normal_pile7.at(i).card_sprite.setPosition(normal_pile7.at(i).xCoordinate, normal_pile7.at(i).yCoordinate + (i * offset));

        if (i == normal_pile7.size() - 1)
        {
            normal_pile7.at(i).card_sprite.setTexture(normal_pile7.at(i).front_img_file);
            normal_pile7.at(i).card_sprite.setPosition(normal_pile7.at(i).xCoordinate, normal_pile7.at(i).yCoordinate + (i * offset));
            normal_pile7.at(i).is_flipped = true;
        }
    }
}

void Pile::setSpriteTexture(int pile_number)
{
    switch (pile_number)
    {
    case 1: // Shuffle pile
        shuffled_pile.top().card_sprite.setTexture(shuffled_pile.top().back_img_file);
        shuffled_pile.top().card_sprite.setPosition(shuffled_pile.top().xCoordinate, shuffled_pile.top().yCoordinate);
        shuffled_pile.top().is_flipped = false;
        break;
    case 2: // Draw pile
        draw_pile.top().card_sprite.setTexture(draw_pile.top().front_img_file);
        draw_pile.top().card_sprite.setPosition(draw_pile.top().xCoordinate + 180, draw_pile.top().yCoordinate);
        draw_pile.top().is_flipped = true;
        break;
    case 3: // Foundation pile 1
        foundation_pile1.top().card_sprite.setTexture(foundation_pile1.top().front_img_file);
        foundation_pile1.top().xCoordinate = 740;
        foundation_pile1.top().yCoordinate = 120;
        foundation_pile1.top().card_sprite.setPosition(foundation_pile1.top().xCoordinate, foundation_pile1.top().yCoordinate);
        break;
    case 4: // Foundation pile 2
        foundation_pile2.top().card_sprite.setTexture(foundation_pile2.top().front_img_file);
        foundation_pile2.top().xCoordinate = 890;
        foundation_pile2.top().yCoordinate = 120;
        foundation_pile2.top().card_sprite.setPosition(foundation_pile2.top().xCoordinate, foundation_pile2.top().yCoordinate);
        break;
    case 5: // Foundation pile 3
        foundation_pile3.top().card_sprite.setTexture(foundation_pile3.top().front_img_file);
        foundation_pile3.top().xCoordinate = 1040;
        foundation_pile3.top().yCoordinate = 120;
        foundation_pile3.top().card_sprite.setPosition(foundation_pile3.top().xCoordinate, foundation_pile3.top().yCoordinate);
        break;
    case 6: // Foundation pile 4
        foundation_pile4.top().card_sprite.setTexture(foundation_pile4.top().front_img_file);
        foundation_pile4.top().xCoordinate = 1190;
        foundation_pile4.top().yCoordinate = 120;
        foundation_pile4.top().card_sprite.setPosition(foundation_pile4.top().xCoordinate, foundation_pile4.top().yCoordinate);
        break;
    case 7: // Normal pile 1
        for (int i = 0; i < normal_pile1.size(); ++i)
        {
            if (normal_pile1[i].is_flipped == true)
            {
                normal_pile1[i].card_sprite.setTexture(normal_pile1[i].front_img_file);
                normal_pile1[i].xCoordinate = 285;
                normal_pile1[i].yCoordinate = 368;
                normal_pile1[i].card_sprite.setPosition(normal_pile1[i].xCoordinate, normal_pile1[i].yCoordinate + (offset * i));
            }
            else
            {
                normal_pile1[i].card_sprite.setTexture(normal_pile1[i].back_img_file);
                normal_pile1[i].xCoordinate = 285;
                normal_pile1[i].yCoordinate = 368;
                normal_pile1[i].card_sprite.setPosition(normal_pile1[i].xCoordinate, normal_pile1[i].yCoordinate + (offset * i));
            }
        }
        break;
    case 8: // Normal pile 2
        for (int i = 0; i < normal_pile2.size(); ++i)
        {
            if (normal_pile2[i].is_flipped == true)
            {
                normal_pile2[i].card_sprite.setTexture(normal_pile2[i].front_img_file);
                normal_pile2[i].xCoordinate = 435;
                normal_pile2[i].yCoordinate = 368;
                normal_pile2[i].card_sprite.setPosition(normal_pile2[i].xCoordinate, normal_pile2[i].yCoordinate + (offset * i));
            }
            else
            {
                normal_pile2[i].card_sprite.setTexture(normal_pile2[i].back_img_file);
                normal_pile2[i].xCoordinate = 435;
                normal_pile2[i].yCoordinate = 368;
                normal_pile2[i].card_sprite.setPosition(normal_pile2[i].xCoordinate, normal_pile2[i].yCoordinate + (offset * i));
            }
        }
        break;
    case 9: // Normal pile 3
        for (int i = 0; i < normal_pile3.size(); ++i)
        {
            if (normal_pile3[i].is_flipped == true)
            {
                normal_pile3[i].card_sprite.setTexture(normal_pile3[i].front_img_file);
                normal_pile3[i].xCoordinate = 585;
                normal_pile3[i].yCoordinate = 368;
                normal_pile3[i].card_sprite.setPosition(normal_pile3[i].xCoordinate, normal_pile3[i].yCoordinate + (offset * i));
            }
            else
            {
                normal_pile3[i].card_sprite.setTexture(normal_pile3[i].back_img_file);
                normal_pile3[i].xCoordinate = 585;
                normal_pile3[i].yCoordinate = 368;
                normal_pile3[i].card_sprite.setPosition(normal_pile3[i].xCoordinate, normal_pile3[i].yCoordinate + (offset * i));
            }
        }
        break;
    case 10: // Normal pile 4
        for (int i = 0; i < normal_pile4.size(); ++i)
        {
            if (normal_pile4[i].is_flipped == true)
            {
                normal_pile4[i].card_sprite.setTexture(normal_pile4[i].front_img_file);
                normal_pile4[i].xCoordinate = 735;
                normal_pile4[i].yCoordinate = 368;
                normal_pile4[i].card_sprite.setPosition(normal_pile4[i].xCoordinate, normal_pile4[i].yCoordinate + (offset * i));
            }
            else
            {
                normal_pile4[i].card_sprite.setTexture(normal_pile4[i].back_img_file);
                normal_pile4[i].xCoordinate = 735;
                normal_pile4[i].yCoordinate = 368;
                normal_pile4[i].card_sprite.setPosition(normal_pile4[i].xCoordinate, normal_pile4[i].yCoordinate + (offset * i));
            }
        }
        break;
    case 11: // Normal pile 5
        for (int i = 0; i < normal_pile5.size(); ++i)
        {
            if (normal_pile5[i].is_flipped == true)
            {
                normal_pile5[i].card_sprite.setTexture(normal_pile5[i].front_img_file);
                normal_pile5[i].xCoordinate = 885;
                normal_pile5[i].yCoordinate = 368;
                normal_pile5[i].card_sprite.setPosition(normal_pile5[i].xCoordinate, normal_pile5[i].yCoordinate + (offset * i));
            }
            else
            {
                normal_pile5[i].card_sprite.setTexture(normal_pile5[i].back_img_file);
                normal_pile5[i].xCoordinate = 885;
                normal_pile5[i].yCoordinate = 368;
                normal_pile5[i].card_sprite.setPosition(normal_pile5[i].xCoordinate, normal_pile5[i].yCoordinate + (offset * i));
            }
        }
        break;
    case 12: // Normal pile 6
        for (int i = 0; i < normal_pile6.size(); ++i)
        {
            if (normal_pile6[i].is_flipped == true)
            {
                normal_pile6[i].card_sprite.setTexture(normal_pile6[i].front_img_file);
                normal_pile6[i].xCoordinate = 1035;
                normal_pile6[i].yCoordinate = 368;
                normal_pile6[i].card_sprite.setPosition(normal_pile6[i].xCoordinate, normal_pile6[i].yCoordinate + (offset * i));
            }
            else
            {
                normal_pile6[i].card_sprite.setTexture(normal_pile6[i].back_img_file);
                normal_pile6[i].xCoordinate = 1035;
                normal_pile6[i].yCoordinate = 368;
                normal_pile6[i].card_sprite.setPosition(normal_pile6[i].xCoordinate, normal_pile6[i].yCoordinate + (offset * i));
            }
        }
        break;
    case 13: // Normal pile 7
        for (int i = 0; i < normal_pile7.size(); ++i)
        {
            if (normal_pile7[i].is_flipped == true)
            {
                normal_pile7[i].card_sprite.setTexture(normal_pile7[i].front_img_file);
                normal_pile7[i].xCoordinate = 1185;
                normal_pile7[i].yCoordinate = 368;
                normal_pile7[i].card_sprite.setPosition(normal_pile7[i].xCoordinate, normal_pile7[i].yCoordinate + (offset * i));
            }
            else
            {
                normal_pile7[i].card_sprite.setTexture(normal_pile7[i].back_img_file);
                normal_pile7[i].xCoordinate = 1185;
                normal_pile7[i].yCoordinate = 368;
                normal_pile7[i].card_sprite.setPosition(normal_pile7[i].xCoordinate, normal_pile7[i].yCoordinate + (offset * i));
            }
        }
        break;
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
    for (int i = 0; i < normal_pile1.size(); i++) // Normal pile 1
    {
        setSpriteTexture(7);
        window.draw(normal_pile1[i].card_sprite);
    }

    for (int i = 0; i < normal_pile2.size(); i++) // Normal pile 2
    {
        setSpriteTexture(8);
        window.draw(normal_pile2[i].card_sprite);
    }

    for (int i = 0; i < normal_pile3.size(); i++) // Normal pile 3
    {
        setSpriteTexture(9);
        window.draw(normal_pile3[i].card_sprite);
    }

    for (int i = 0; i < normal_pile4.size(); i++) // Normal pile 4
    {
        setSpriteTexture(10);
        window.draw(normal_pile4[i].card_sprite);
    }

    for (int i = 0; i < normal_pile5.size(); i++) // Normal pile 5
    {
        setSpriteTexture(11);
        window.draw(normal_pile5[i].card_sprite);
    }

    for (int i = 0; i < normal_pile6.size(); i++) // Normal pile 6
    {
        setSpriteTexture(12);
        window.draw(normal_pile6[i].card_sprite);
    }

    for (int i = 0; i < normal_pile7.size(); i++) // Normal pile 7
    {
        setSpriteTexture(13);
        window.draw(normal_pile7[i].card_sprite);
    }
}

void Pile::checkIfSpriteIsClicked(Vector2f mouse) {
    FloatRect bounds;

    // Draw Pile
    if (!draw_pile.empty())
        bounds = draw_pile.top().card_sprite.getGlobalBounds();
    if (bounds.contains(mouse)) {
        MoveCard(1, foundation_pile1, normal_pile1);
        return;
    }

    if (!foundation_pile1.empty())
        bounds = foundation_pile1.top().card_sprite.getGlobalBounds();
    if (bounds.contains(mouse)) {
        cout << "f1\n";
        MoveCard(2, foundation_pile1, normal_pile1);
        return;
    }
    if (!foundation_pile2.empty())
        bounds = foundation_pile2.top().card_sprite.getGlobalBounds();
    if (bounds.contains(mouse)) {
        cout << "f2\n";
        MoveCard(2, foundation_pile2, normal_pile1);
        return;
    }
    if (!foundation_pile3.empty())
        bounds = foundation_pile3.top().card_sprite.getGlobalBounds();
    if (bounds.contains(mouse)) {
        cout << "f3\n";
        MoveCard(2, foundation_pile3, normal_pile1);
        return;
    }
    if (!foundation_pile4.empty())
        bounds = foundation_pile4.top().card_sprite.getGlobalBounds();
    if (bounds.contains(mouse)) {
        cout << "f4\n";
        MoveCard(2, foundation_pile4, normal_pile1);
        return;
    }
    for (int i = normal_pile1.size() - 1; i >= 0; i--) {
        bounds = normal_pile1[i].card_sprite.getGlobalBounds();
        if (bounds.contains(mouse) && normal_pile1[i].is_flipped)
        {
            MoveCard(3, foundation_pile1, normal_pile1);
            cout << "n1 element " << i + 1 << "\n";
            return;
        }
    }
    for (int i = normal_pile2.size() - 1; i >= 0; i--) {
        bounds = normal_pile2[i].card_sprite.getGlobalBounds();
        if (bounds.contains(mouse) && normal_pile2[i].is_flipped) {
            MoveCard(3, foundation_pile1, normal_pile2);
            cout << "n2 element " << i + 1 << "\n";
            return;
        }
    }
    for (int i = normal_pile3.size() - 1; i >= 0; i--) {
        bounds = normal_pile3[i].card_sprite.getGlobalBounds();
        if (bounds.contains(mouse) && normal_pile3[i].is_flipped) {
            MoveCard(3, foundation_pile1, normal_pile3);
            cout << "n3 element " << i + 1 << "\n";
            return;
        }
    }
    for (int i = normal_pile4.size() - 1; i >= 0; i--) {
        bounds = normal_pile4[i].card_sprite.getGlobalBounds();
        if (bounds.contains(mouse) && normal_pile4[i].is_flipped) {
            MoveCard(3, foundation_pile1, normal_pile4);
            cout << "n4 element " << i + 1 << "\n";
            return;
        }
    }
    for (int i = normal_pile5.size() - 1; i >= 0; i--) {
        bounds = normal_pile5[i].card_sprite.getGlobalBounds();
        if (bounds.contains(mouse) && normal_pile5[i].is_flipped) {
            MoveCard(3, foundation_pile1, normal_pile5);
            cout << "n5 element " << i + 1 << "\n";
            return;
        }
    }
    for (int i = normal_pile6.size() - 1; i >= 0; i--) {
        bounds = normal_pile6[i].card_sprite.getGlobalBounds();
        if (bounds.contains(mouse) && normal_pile6[i].is_flipped) {
            MoveCard(3, foundation_pile1, normal_pile6);
            cout << "n6 element " << i + 1 << "\n";
            return;
        }
    }
    for (int i = normal_pile7.size() - 1; i >= 0; i--) {
        bounds = normal_pile7[i].card_sprite.getGlobalBounds();
        if (bounds.contains(mouse) && normal_pile7[i].is_flipped) {
            MoveCard(3, foundation_pile1, normal_pile7);
            cout << "n7 element " << i + 1 << "\n";
            return;
        }
    }
}

void Pile::MoveCard(int pile_number, stack<Card>& fPile, vector<Card>& nPile)
{
    switch (pile_number)
    {
    case 1: // Draw Pile
        MoveFromDrawPile();
        return;
    case 2: // Foundation Pile
        MoveFromFoundationPile(fPile);
        return;
    case 3: // Normal Pile
        MoveFromNormalPile(nPile);
        return;
    }
}

void Pile::MoveFromShuffledPile()
{
    if (!shuffled_pile.empty())
    {
        card_click_sound.play();
        draw_pile.push(shuffled_pile.top());
        shuffled_pile.pop();
        setSpriteTexture(2);
    }
    else
    {
        while (!draw_pile.empty())
        {
            card_shuffle_sound.play();
            shuffled_pile.push(draw_pile.top());
            draw_pile.pop();
            setSpriteTexture(1);
        }
    }
}

void Pile::MoveFromDrawPile()
{
    if (foundation_pile1.empty() && int(draw_pile.top().name) == 1)
    {
        card_click_sound.play();
        foundation_pile1.push(draw_pile.top());
        draw_pile.pop();
        setSpriteTexture(3/*Foundation pile*/);
        return;
    }
    else if (!foundation_pile1.empty() \
        && int(foundation_pile1.top().color) == int(draw_pile.top().color) \
        && int(foundation_pile1.top().suit) == int(draw_pile.top().suit) \
        && (int(foundation_pile1.top().name) - int(draw_pile.top().name) == -1))
    {
        card_click_sound.play();
        foundation_pile1.push(draw_pile.top());
        draw_pile.pop();
        setSpriteTexture(3/*Foundation pile*/);
        return;
    }
    if (foundation_pile2.empty() && int(draw_pile.top().name) == 1)
    {
        card_click_sound.play();
        foundation_pile2.push(draw_pile.top());
        draw_pile.pop();
        setSpriteTexture(4/*Foundation pile*/);
        return;
    }
    else if (!foundation_pile2.empty() \
        && int(foundation_pile2.top().color) == int(draw_pile.top().color) \
        && int(foundation_pile2.top().suit) == int(draw_pile.top().suit) \
        && (int(foundation_pile2.top().name) - int(draw_pile.top().name) == -1))
    {
        card_click_sound.play();
        foundation_pile2.push(draw_pile.top());
        draw_pile.pop();
        setSpriteTexture(4/*Foundation pile*/);
        return;
    }
    if (foundation_pile3.empty() && int(draw_pile.top().name) == 1) // Foundation pile 3
    {
        card_click_sound.play();
        foundation_pile3.push(draw_pile.top());
        draw_pile.pop();
        setSpriteTexture(5/*Foundation pile*/);
        return;
    }
    else if (!foundation_pile3.empty() \
        && int(foundation_pile3.top().color) == int(draw_pile.top().color) \
        && int(foundation_pile3.top().suit) == int(draw_pile.top().suit) \
        && (int(foundation_pile3.top().name) - int(draw_pile.top().name) == -1))
    {
        card_click_sound.play();
        foundation_pile3.push(draw_pile.top());
        draw_pile.pop();
        setSpriteTexture(5/*Foundation pile*/);
        return;
    }
    if (foundation_pile4.empty() && int(draw_pile.top().name) == 1) // Foundation pile 4
    {
        card_click_sound.play();
        foundation_pile4.push(draw_pile.top());
        draw_pile.pop();
        setSpriteTexture(6/*Foundation pile*/);
        return;
    }
    else if (!foundation_pile4.empty() \
        && int(foundation_pile4.top().color) == int(draw_pile.top().color) \
        && int(foundation_pile4.top().suit) == int(draw_pile.top().suit) \
        && (int(foundation_pile4.top().name) - int(draw_pile.top().name) == -1))
    {
        card_click_sound.play();
        foundation_pile4.push(draw_pile.top());
        draw_pile.pop();
        setSpriteTexture(6/*Foundation pile*/);
        return;
    }
    if (normal_pile1.empty() && int(draw_pile.top().name) == 13) // Normal Pile 1
    {
        card_click_sound.play();
        normal_pile1.push_back(draw_pile.top());
        draw_pile.pop();
        setSpriteTexture(7/*Foundation pile*/);
        return;
    }
    else if (!normal_pile1.empty() \
        && int(normal_pile1.back().color) != int(draw_pile.top().color) \
        && (int(normal_pile1.back().name) - int(draw_pile.top().name) == 1))
    {
        card_click_sound.play();
        normal_pile1.push_back(draw_pile.top());
        draw_pile.pop();
        setSpriteTexture(7/*Foundation pile*/);
        return;
    }
    if (normal_pile2.empty() && int(draw_pile.top().name) == 13) // Normal Pile 1
    {
        card_click_sound.play();
        normal_pile2.push_back(draw_pile.top());
        draw_pile.pop();
        setSpriteTexture(8/*Foundation pile*/);
        return;
    }
    else if (!normal_pile2.empty() \
        && int(normal_pile2.back().color) != int(draw_pile.top().color) \
        && (int(normal_pile2.back().name) - int(draw_pile.top().name) == 1))
    {
        card_click_sound.play();
        normal_pile2.push_back(draw_pile.top());
        draw_pile.pop();
        setSpriteTexture(8/*Foundation pile*/);
        return;
    }
    if (normal_pile3.empty() && int(draw_pile.top().name) == 13) // Normal Pile 1
    {
        card_click_sound.play();
        normal_pile3.push_back(draw_pile.top());
        draw_pile.pop();
        setSpriteTexture(9/*Foundation pile*/);
        return;
    }
    else if (!normal_pile3.empty() \
        && int(normal_pile3.back().color) != int(draw_pile.top().color) \
        && (int(normal_pile3.back().name) - int(draw_pile.top().name) == 1))
    {
        card_click_sound.play();
        normal_pile3.push_back(draw_pile.top());
        draw_pile.pop();
        setSpriteTexture(9/*Foundation pile*/);
        return;
    }
    if (normal_pile4.empty() && int(draw_pile.top().name) == 13) // Normal Pile 1
    {
        card_click_sound.play();
        normal_pile4.push_back(draw_pile.top());
        draw_pile.pop();
        setSpriteTexture(10/*Foundation pile*/);
        return;
    }
    else if (!normal_pile4.empty() \
        && int(normal_pile4.back().color) != int(draw_pile.top().color) \
        && (int(normal_pile4.back().name) - int(draw_pile.top().name) == 1))
    {
        card_click_sound.play();
        normal_pile4.push_back(draw_pile.top());
        draw_pile.pop();
        setSpriteTexture(10/*Foundation pile*/);
        return;
    }
    if (normal_pile5.empty() && int(draw_pile.top().name) == 13) // Normal Pile 1
    {
        card_click_sound.play();
        normal_pile5.push_back(draw_pile.top());
        draw_pile.pop();
        setSpriteTexture(11/*Foundation pile*/);
        return;
    }
    else if (!normal_pile5.empty() \
        && int(normal_pile5.back().color) != int(draw_pile.top().color) \
        && (int(normal_pile5.back().name) - int(draw_pile.top().name) == 1))
    {
        card_click_sound.play();
        normal_pile5.push_back(draw_pile.top());
        draw_pile.pop();
        setSpriteTexture(11/*Foundation pile*/);
        return;
    }
    if (normal_pile6.empty() && int(draw_pile.top().name) == 13) // Normal Pile 1
    {
        card_click_sound.play();
        normal_pile6.push_back(draw_pile.top());
        draw_pile.pop();
        setSpriteTexture(12/*Foundation pile*/);
        return;
    }
    else if (!normal_pile6.empty() \
        && int(normal_pile6.back().color) != int(draw_pile.top().color) \
        && (int(normal_pile6.back().name) - int(draw_pile.top().name) == 1))
    {
        card_click_sound.play();
        normal_pile6.push_back(draw_pile.top());
        draw_pile.pop();
        setSpriteTexture(12/*Foundation pile*/);
        return;
    }
    if (normal_pile7.empty() && int(draw_pile.top().name) == 13) // Normal Pile 1
    {
        card_click_sound.play();
        normal_pile7.push_back(draw_pile.top());
        draw_pile.pop();
        setSpriteTexture(13/*Foundation pile*/);
        return;
    }
    else if (!normal_pile7.empty() \
        && int(normal_pile7.back().color) != int(draw_pile.top().color) \
        && (int(normal_pile7.back().name) - int(draw_pile.top().name) == 1))
    {
        card_click_sound.play();
        normal_pile7.push_back(draw_pile.top());
        draw_pile.pop();
        setSpriteTexture(13/*Foundation pile*/);
        return;
    }

    return;
}

void Pile::MoveFromFoundationPile(stack<Card>& pile)
{
    if (foundation_pile1.empty() && int(pile.top().name) == 1)
    {
        card_click_sound.play();
        foundation_pile1.push(pile.top());
        pile.pop();
        setSpriteTexture(3/*Foundation pile 1*/);
        return;
    }
    else if (foundation_pile2.empty() && int(pile.top().name) == 1)
    {
        card_click_sound.play();
        foundation_pile2.push(pile.top());
        pile.pop();
        setSpriteTexture(4/*Foundation pile 2*/);
        return;
    }
    else if (foundation_pile3.empty() && int(pile.top().name) == 1)
    {
        card_click_sound.play();
        foundation_pile3.push(pile.top());
        pile.pop();
        setSpriteTexture(5/*Foundation pile 3*/);
        return;
    }
    else if (foundation_pile4.empty() && int(pile.top().name) == 1)
    {
        card_click_sound.play();
        foundation_pile4.push(pile.top());
        pile.pop();
        setSpriteTexture(6/*Foundation pile 4*/);
        return;
    }
    else if (int(normal_pile1.back().color) != int(pile.top().color) \
        && (int(normal_pile1.back().name) - int(pile.top().name) == 1))
    {
        card_click_sound.play();
        normal_pile1.push_back(pile.top());
        pile.pop();
        setSpriteTexture(7/*Normal pile 1*/);
        return;
    }
    else if (int(normal_pile2.back().color) != int(pile.top().color) \
        && (int(normal_pile2.back().name) - int(pile.top().name) == 1))
    {
        card_click_sound.play();
        normal_pile2.push_back(pile.top());
        pile.pop();
        setSpriteTexture(8/*Normal pile 2*/);
        return;
    }
    else if (int(normal_pile3.back().color) != int(pile.top().color) \
        && (int(normal_pile3.back().name) - int(pile.top().name) == 1))
    {
        card_click_sound.play();
        normal_pile3.push_back(pile.top());
        pile.pop();
        setSpriteTexture(9/*Normal pile 3*/);
        return;
    }
    else if (int(normal_pile4.back().color) != int(pile.top().color) \
        && (int(normal_pile4.back().name) - int(pile.top().name) == 1))
    {
        card_click_sound.play();
        normal_pile4.push_back(pile.top());
        pile.pop();
        setSpriteTexture(10/*Normal pile 4*/);
        return;
    }
    else if (int(normal_pile5.back().color) != int(pile.top().color) \
        && (int(normal_pile5.back().name) - int(pile.top().name) == 1))
    {
        card_click_sound.play();
        normal_pile5.push_back(pile.top());
        pile.pop();
        setSpriteTexture(11/*Normal pile 5*/);
        return;
    }
    else if (int(normal_pile6.back().color) != int(pile.top().color) \
        && (int(normal_pile6.back().name) - int(pile.top().name) == 1))
    {
        card_click_sound.play();
        normal_pile6.push_back(pile.top());
        pile.pop();
        setSpriteTexture(12/*Normal pile 6*/);
        return;
    }
    else if (int(normal_pile2.back().color) != int(pile.top().color) \
        && (int(normal_pile2.back().name) - int(pile.top().name) == 1))
    {
        card_click_sound.play();
        normal_pile7.push_back(pile.top());
        pile.pop();
        setSpriteTexture(13/*Normal pile 7*/);
        return;
    }
    return;
}

void Pile::MoveFromNormalPile(vector<Card>& pile)
{
    if (foundation_pile1.empty() && int(pile.back().name) == 1)
    {
        card_click_sound.play();
        foundation_pile1.push(pile.back());
        pile.pop_back();
        if (!pile.empty())
            pile.back().is_flipped = true;
        setSpriteTexture(3/*Foundation pile*/);
        return;
    }
    else if (!foundation_pile1.empty() \
        && int(foundation_pile1.top().color) == int(pile.back().color) \
        && int(foundation_pile1.top().suit) == int(pile.back().suit) \
        && (int(foundation_pile1.top().name) - int(pile.back().name) == -1))
    {
        card_click_sound.play();
        foundation_pile1.push(pile.back());
        pile.pop_back();
        if (!pile.empty())
            pile.back().is_flipped = true;
        setSpriteTexture(3/*Foundation pile*/);
        return;
    }
    if (foundation_pile2.empty() && int(pile.back().name) == 1)
    {
        card_click_sound.play();
        foundation_pile2.push(pile.back());
        pile.pop_back();
        if (!pile.empty())
            pile.back().is_flipped = true;
        setSpriteTexture(4/*Foundation pile*/);
        return;
    }
    else if (!foundation_pile2.empty() \
        && int(foundation_pile2.top().color) == int(pile.back().color) \
        && int(foundation_pile2.top().suit) == int(pile.back().suit) \
        && (int(foundation_pile2.top().name) - int(pile.back().name) == -1))
    {
        card_click_sound.play();
        foundation_pile2.push(pile.back());
        pile.pop_back();
        if (!pile.empty())
            pile.back().is_flipped = true;
        setSpriteTexture(4/*Foundation pile*/);
        return;
    }
    if (foundation_pile3.empty() && int(pile.back().name) == 1) // Foundation pile 3
    {
        card_click_sound.play();
        foundation_pile3.push(pile.back());
        pile.pop_back();
        if (!pile.empty())
            pile.back().is_flipped = true;
        setSpriteTexture(5/*Foundation pile*/);
        return;
    }
    else if (!foundation_pile3.empty() \
        && int(foundation_pile3.top().color) == int(pile.back().color) \
        && int(foundation_pile3.top().suit) == int(pile.back().suit) \
        && (int(foundation_pile3.top().name) - int(pile.back().name) == -1))
    {
        card_click_sound.play();
        foundation_pile3.push(pile.back());
        pile.pop_back();
        if (!pile.empty())
            pile.back().is_flipped = true;
        setSpriteTexture(5/*Foundation pile*/);
        return;
    }
    if (foundation_pile4.empty() && int(pile.back().name) == 1) // Foundation pile 4
    {
        card_click_sound.play();
        foundation_pile4.push(pile.back());
        pile.pop_back();
        if (!pile.empty())
            pile.back().is_flipped = true;
        setSpriteTexture(6/*Foundation pile*/);
        return;
    }
    else if (!foundation_pile4.empty() \
        && int(foundation_pile4.top().color) == int(pile.back().color) \
        && int(foundation_pile4.top().suit) == int(pile.back().suit) \
        && (int(foundation_pile4.top().name) - int(pile.back().name) == -1))
    {
        card_click_sound.play();
        foundation_pile4.push(pile.back());
        pile.pop_back();
        if (!pile.empty())
            pile.back().is_flipped = true;
        setSpriteTexture(6/*Foundation pile*/);
        return;
    }
    if (normal_pile1.empty() && int(pile.back().name) == 13) // Normal Pile 1
    {
        card_click_sound.play();
        normal_pile1.push_back(pile.back());
        pile.pop_back();
        if (!pile.empty())
            pile.back().is_flipped = true;
        setSpriteTexture(7/*Foundation pile*/);
        return;
    }
    else if (!normal_pile1.empty() \
        && int(normal_pile1.back().color) != int(pile.back().color) \
        && (int(normal_pile1.back().name) - int(pile.back().name) == 1))
    {
        card_click_sound.play();
        normal_pile1.push_back(pile.back());
        pile.pop_back();
        if (!pile.empty())
            pile.back().is_flipped = true;
        setSpriteTexture(7/*Foundation pile*/);
        return;
    }
    if (normal_pile2.empty() && int(pile.back().name) == 13) // Normal Pile 1
    {
        card_click_sound.play();
        normal_pile2.push_back(pile.back());
        pile.pop_back();
        if (!pile.empty())
            pile.back().is_flipped = true;
        setSpriteTexture(8/*Foundation pile*/);
        return;
    }
    else if (!normal_pile2.empty() \
        && int(normal_pile2.back().color) != int(pile.back().color) \
        && (int(normal_pile2.back().name) - int(pile.back().name) == 1))
    {
        card_click_sound.play();
        normal_pile2.push_back(pile.back());
        pile.pop_back();
        if (!pile.empty())
            pile.back().is_flipped = true;
        setSpriteTexture(8/*Foundation pile*/);
        return;
    }
    if (normal_pile3.empty() && int(pile.back().name) == 13) // Normal Pile 1
    {
        card_click_sound.play();
        normal_pile3.push_back(pile.back());
        pile.pop_back();
        if (!pile.empty())
            pile.back().is_flipped = true;
        setSpriteTexture(9/*Foundation pile*/);
        return;
    }
    else if (!normal_pile3.empty() \
        && int(normal_pile3.back().color) != int(pile.back().color) \
        && (int(normal_pile3.back().name) - int(pile.back().name) == 1))
    {
        card_click_sound.play();
        normal_pile3.push_back(pile.back());
        pile.pop_back();
        if (!pile.empty())
            pile.back().is_flipped = true;
        setSpriteTexture(9/*Foundation pile*/);
        return;
    }
    if (normal_pile4.empty() && int(pile.back().name) == 13) // Normal Pile 1
    {
        card_click_sound.play();
        normal_pile4.push_back(pile.back());
        pile.pop_back();
        if (!pile.empty())
            pile.back().is_flipped = true;
        setSpriteTexture(10/*Foundation pile*/);
        return;
    }
    else if (!normal_pile4.empty() \
        && int(normal_pile4.back().color) != int(pile.back().color) \
        && (int(normal_pile4.back().name) - int(pile.back().name) == 1))
    {
        card_click_sound.play();
        normal_pile4.push_back(pile.back());
        pile.pop_back();
        if (!pile.empty())
            pile.back().is_flipped = true;
        setSpriteTexture(10/*Foundation pile*/);
        return;
    }
    if (normal_pile5.empty() && int(pile.back().name) == 13) // Normal Pile 1
    {
        card_click_sound.play();
        normal_pile5.push_back(pile.back());
        pile.pop_back();
        if (!pile.empty())
            pile.back().is_flipped = true;
        setSpriteTexture(11/*Foundation pile*/);
        return;
    }
    else if (!normal_pile5.empty() \
        && int(normal_pile5.back().color) != int(pile.back().color) \
        && (int(normal_pile5.back().name) - int(pile.back().name) == 1))
    {
        card_click_sound.play();
        normal_pile5.push_back(pile.back());
        pile.pop_back();
        if (!pile.empty())
            pile.back().is_flipped = true;
        setSpriteTexture(11/*Foundation pile*/);
        return;
    }
    if (normal_pile6.empty() && int(pile.back().name) == 13) // Normal Pile 1
    {
        card_click_sound.play();
        normal_pile6.push_back(pile.back());
        pile.pop_back();
        if (!pile.empty())
            pile.back().is_flipped = true;
        setSpriteTexture(12/*Foundation pile*/);
        return;
    }
    else if (!normal_pile6.empty() \
        && int(normal_pile6.back().color) != int(pile.back().color) \
        && (int(normal_pile6.back().name) - int(pile.back().name) == 1))
    {
        card_click_sound.play();
        normal_pile6.push_back(pile.back());
        pile.pop_back();
        if (!pile.empty())
            pile.back().is_flipped = true;
        setSpriteTexture(12/*Foundation pile*/);
        return;
    }
    if (normal_pile7.empty() && int(pile.back().name) == 13) // Normal Pile 1
    {
        card_click_sound.play();
        normal_pile7.push_back(pile.back());
        pile.pop_back();
        if (!pile.empty())
            pile.back().is_flipped = true;
        setSpriteTexture(13/*Foundation pile*/);
        return;
    }
    else if (!normal_pile7.empty() \
        && int(normal_pile7.back().color) != int(pile.back().color) \
        && (int(normal_pile7.back().name) - int(pile.back().name) == 1))
    {
        card_click_sound.play();
        normal_pile7.push_back(pile.back());
        pile.pop_back();
        if (!pile.empty())
            pile.back().is_flipped = true;
        setSpriteTexture(13/*Foundation pile*/);
        return;
    }

    return;
}
