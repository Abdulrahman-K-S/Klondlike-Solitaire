#include "OutlinePile.h"

OutlinePile::OutlinePile(int startXPosition, int startYPosition, int endXPosition, int endYPosition)
{
    this->startXPosition = startXPosition;
    this->startYPosition = startYPosition;
    this->endXPosition = endXPosition;
    this->endYPosition = endYPosition;
    pileOutline.setSize(Vector2f(120, 164));
    pileOutline.setPosition(Vector2f(startXPosition, startYPosition));
    pileOutline.setFillColor(Color::Transparent);
    pileOutline.setOutlineColor(Color::White);
    pileOutline.setOutlineThickness(1);
}
