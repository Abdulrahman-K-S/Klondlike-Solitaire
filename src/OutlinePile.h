#include <SFML/Graphics.hpp>
using namespace sf;

class OutlinePile
{
public:
    RectangleShape pileOutline;
    OutlinePile();
    OutlinePile(int, int);
};