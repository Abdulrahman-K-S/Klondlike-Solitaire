#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class OutlinePile
{
private:
    RectangleShape pileOutline; // Defining the outline shape for the pile
    int xPosition, yPosition; // Having the position known for later use
public:
    OutlinePile(int xPosition, int yPosition);
    RectangleShape getShape();
};



