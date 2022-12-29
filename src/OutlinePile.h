#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class OutlinePile
{
public:
    RectangleShape pileOutline;
    int startXPosition = 0, startYPosition = 0;
    int endXPosition = 0, endYPosition = 0;
    OutlinePile(int startXPosition, int startYPosition,\
        int endXposition, int endYposition);
};
