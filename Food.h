#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


//Примечание
//Вся реализация конструкторов, методов и т.п. будет находится в:
//Food.cpp


public delegate void DeleteFoodHandler(Object^ sender);
public delegate void ExistsFoodHandler(Object^ sender, double x, double y);

ref class Food
{
private:
	double x, y;
	Image^ sprite;
	String^ path = "source\\Food.png";
public:
	property double xCoord {
		double get() {
			return this->x;
		}
	}
	property double yCoord {
		double get() {
			return this->y;
		}
		void set(double param) {
			this->y = param;
			if (param > 475) {
				deleteFood(this);
			}
		}
	}
	event DeleteFoodHandler^ deleteFood;
	event ExistsFoodHandler^ existsFood;
	Food(double x, double y);
	void drawSprite(Graphics^ g);
	void moveAnim();
};

