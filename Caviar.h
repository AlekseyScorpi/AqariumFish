#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


//Примечание
//Вся реализация конструкторов, методов и т.п. будет находится в:
//Caviar.cpp


public delegate void FishBirthHandler(double x, double y, int color, bool hunt, Object^ sender);

ref class Caviar
{
private:
	String^ path = "source\\Caviar.png";
	double x, y;
	int colorGen;
	int timeToBirth = 500;
	Image^ sprite;
	bool huntFish;
public:
	property double xCoord {
		void set(double param) {
			this->x = param;
		}
		double get() {
			return this->x;
		}
	}
	property double yCoord{
		void set(double param) {
			this->y = param;
		}
		double get() {
			return this->y;
		}
	}
	property bool isHunt {
		void set(bool param) {
			this->huntFish = param;
		}
		bool get() {
			return this->huntFish;
		}
	}
	property int birthTimer {
		void set(int param) {
			if (param <= 0) {
				fishBirth(xCoord, yCoord, colorGen, isHunt, this);
				this->timeToBirth = 500;
			}
			else {
				this->timeToBirth = param;
			}
		}
		int get() {
			return this->timeToBirth;
		}
	}
	event FishBirthHandler^ fishBirth;
	Caviar(double x, double y, int colorGen, bool huntFish);
	void drawSprite(Graphics^ g);
	void moveAnim();
};

