#include "src/Card.cpp"

int main() {
    RenderWindow window(VideoMode(1600, 900), "Solitaire");
    Deck deck;
    deck.setDeck();
    deck.shuffleCards();
    Sprite spriteArr[52];
    for(int i = 0; i < 52; ++i){
        spriteArr[i].setTexture(deck.cards[i].img_file);
        spriteArr[i].setOrigin(i*-6,i*-6);
    }

    // Setting up the background of the game

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        for(int i = 0; i < 52; ++i)
            window.draw(spriteArr[i]);
        window.display();
    }

    return 0;
}

// Key Pressed/Released
// Mouse Button Pressed/Released
// x,y coordinates of the mouse
// window resize x,y coordinates
// window lost/gained focus
// text entered
// which text has been pressed
// Is key pressed or not (inside an if statement) # Live Keyboard
// Is mouse button pressed or not (inside an if statement) # Live mouse
// Mouse::getPosition() gets the position of the mouse in the whole screen
// Mouse::getPosition(window) gets the position of the mouse in the whole window (negative left and positive right) out of the range