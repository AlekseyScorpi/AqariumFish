#include "Food.h"


Food::Food(double x, double y)
{
    this->x = x;
    this->y = y;
    sprite = gcnew Bitmap(path);
}

void Food::drawSprite(Graphics^ g)
{
    g->DrawImage(sprite, x - 10, y - 10, 20, 20);
}

void Food::moveAnim()
{
    this->yCoord += 0.5;
    existsFood(this, xCoord, yCoord);
}
