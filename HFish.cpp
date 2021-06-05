#include "HFish.h"

HFish::HFish(double x, double y, int size) : 
    Fish(x, y, size, 1)
{
    this->fishRight = gcnew Bitmap(this->path);
    this->fishLeft = gcnew Bitmap(this->path2);
    sprite = fishRight;
    this->speed = 2 - 0.1 * size;
    this->visibleDistance = 400 + 20 * size;
	this->isHunt = true;
}

void HFish::foodEatingMethod()
{
    this->foodColdown = 350;
    this->seeFood = false;
    energy += 1750;
    this->currentDistanceToAnyFood = 10000;
}

void HFish::fishDetectedMethod(Object^ sender, double x, double y, int level)
{
	if (foodCd != 0) {
		doSeeFood = false;
		return;
	}
	if ((calculateDistance(xCoord, yCoord, x, y) <= visibleDistance)) {
		if ((calculateDistance(xCoord, yCoord, x, y) <= currentDistanceToAnyFood) 
			&& (level < this->size) && (this->energy <= 0.3 * getMaxEnergy())) {
			currentDistanceToAnyFood = calculateDistance(xCoord, yCoord, x, y);
			if (calculateDistance(xCoord, yCoord, x, y) <= this->getHeight() / 2) {
				fishEatingMethod();
				fishEating(sender);
			}
			else {
				this->seeFood = true;
				newXCoord = x;
				newYCoord = y;
			}
		}
	}
}

void HFish::fishEatingMethod()
{
	this->foodColdown = 800;
	this->seeFood = false;
	energy += 3000;
	this->currentDistanceToAnyFood = 10000;
}

void HFish::createCaviarMethod()
{
    energy -= 2500;
    createCaviar(this->xCoord, this->yCoord, this->colorGen, true);
}

void HFish::moveAnim()
{
	double distance = calculateDistance(xCoord, yCoord, newXCoord, newYCoord);
	if (distance < 2) {
		doSeeFood = false;
		return;
	}
	if (newX >= this->x) {
		sprite = fishRight;
	}
	else {
		sprite = fishLeft;
	}
	x += speed * (newX - x) / distance;
	y += speed * (newY - y) / distance;
	currentDistanceToAnyFood = 10000;
}

