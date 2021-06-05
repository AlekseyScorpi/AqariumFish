#include "Fish.h"
#include "MyForm.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


//метод из инета для определения границ и создания прозрачности (спасибо всемирной паутине и добрым умным людям)
//static Drawing2D::GraphicsPath^ BuildTransparencyPath(Image^ im)
//{
//	int x;
//	int y;
//	Drawing2D::GraphicsPath^ gp = gcnew Drawing2D::GraphicsPath();
//	Bitmap^ bmp = gcnew Bitmap(im);
//	Color mask = bmp->GetPixel(0, 0);
//
//	for (x = 0; x <= bmp->Width - 1; x++)
//	{
//		for (y = 0; y <= bmp->Height - 1; y++)
//		{
//			if (!bmp->GetPixel(x, y).Equals(mask))
//			{
//				gp->AddRectangle(Rectangle(x, y, 1, 1));
//			}
//		}
//	}
//	return gp;
//}


//Fish::Fish() //конструктор по умолчанию
//{
//	//sprite = gcnew PictureBox();
//	x = (float) 250;
//	y = (float) 250;
//	size = 1;
//	sprite = gcnew Bitmap(path);
//	//sprite->Top = y;
//	//sprite->Left = x;
//	//sprite->Width = sprite->Width * 0.5 + 0.1 * size * sprite->Width;
//	//sprite->Height = sprite->Height * 0.5 + 0.1 * size * sprite->Height;
//	//bm = gcnew Bitmap(path);
//	//sprite->BackColor = Color::Transparent;
//	//bm->MakeTransparent(Color::Transparent);
//	//sprite->Image = bm;
//	////sprite->Size = sprite->Image->Size;
//	//sprite->SizeMode = PictureBoxSizeMode::Zoom;
//	//sprite->Region = gcnew Region(BuildTransparencyPath(bm));
//}


double Fish::calculateDistance(double x1, double y1, double x2, double y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int Fish::getMaxEnergy()
{
	return this->maxEnergy;
}

int Fish::getColor()
{
	return this->colorGen;
}

double Fish::getHeight()
{
	return this->fishSize->Height;
}

double Fish::getVisibleDistance()
{
	return this->visibleDistance;
}

Fish::Fish(double x, double y, int size, int colorGen) //ожидаемый конструктор
{
	this->x = x;
	this->y = y;
	this->size = size;
	this->colorGen = colorGen;
	this->maxEnergy = 2000 * size;
	this->fishEnergy = this->maxEnergy / 2;
	switch (this->colorGen)
	{
	case 1:
		this->fishRight = gcnew Bitmap(path);
		this->fishLeft = gcnew Bitmap(path2);
		break;
	case 2:
		this->fishRight = gcnew Bitmap(path3);
		this->fishLeft = gcnew Bitmap(path4);
		break;
	case 3:
		this->fishRight = gcnew Bitmap(path5);
		this->fishLeft = gcnew Bitmap(path6);
		break;
	default:
		break;
	}
	sprite = fishRight;
	fishSize = gcnew Size(80 + 20 * size, 50 + 18 * size);
	this->newX = x;
	this->newY = y;
	this->speed = 1.8 - 0.1 * size;
	this->visibleDistance = 300 + 20 * size;


}

void Fish::drawSprite(Graphics^ g)
{
	g->DrawImage(sprite, x - (fishSize->Width / 2), (y - fishSize->Height / 2), (float)fishSize->Width, (float)fishSize->Height);
}

void Fish::move(float x, float y) //задание новых координат и отображение спрайта по пути движения
{
	newX = x;
	newY = y;
}

void Fish::moveAnim() //само передвижение - анимация
{
	existsFish(this, xCoord, yCoord, level);
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

void Fish::foodDetectedMethod(Object^ sender, double x, double y)
{
	if (foodCd != 0) {
		doSeeFood = false;
		return;
	}
	if ((calculateDistance(xCoord, yCoord, x, y) <= visibleDistance)) {
		if (calculateDistance(xCoord, yCoord, x, y) <= currentDistanceToAnyFood) {
			currentDistanceToAnyFood = calculateDistance(xCoord, yCoord, x, y);
			if (calculateDistance(xCoord, yCoord, x, y) <= this->getHeight() / 2) {
				foodEatingMethod();
				foodEating(sender);
			}
			else {
				this->seeFood = true;
				newXCoord = x;
				newYCoord = y;
			}
		}
	}
}

void Fish::foodEatingMethod()
{
	this->foodColdown = 700;
	this->seeFood = false;
	energy += 2000;
	this->currentDistanceToAnyFood = 10000;
}

void Fish::createCaviarMethod()
{
	energy -= 3500;
	createCaviar(xCoord, yCoord, colorGen, isHunt);
}
