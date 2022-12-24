#include "OutlinePile.h"

OutlinePile::OutlinePile(int xPosition, int yPosition)
{
    this->xPosition = xPosition;
    this->yPosition = yPosition;
    pileOutline.setSize(Vector2f(120, 164));
    pileOutline.setPosition(Vector2f(xPosition, yPosition));
    pileOutline.setFillColor(Color::Transparent);
    pileOutline.setOutlineColor(Color::White);
    pileOutline.setOutlineThickness(1);
}

RectangleShape OutlinePile::getShape()
{
    return pileOutline;
}