#include "Caviar.h"

Caviar::Caviar(double x, double y, int colorGen, bool huntFish)
{
    this->x = x;
    this->y = y;
    this->colorGen = colorGen;
    sprite = gcnew Bitmap(path);
    this->huntFish = huntFish;
}

void Caviar::drawSprite(Graphics^ g)
{
    g->DrawImage(sprite, x - 15, y - 15, 30, 30);
}

void Caviar::moveAnim()
{
    if (y < 475) {
        yCoord += 1.5;
    }
    else {
        birthTimer--;
    }
}
