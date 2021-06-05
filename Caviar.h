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


public delegate void CaviarDeleteHandler(Object^ sender);
public delegate void FishBirthHandler(double x, double y, int color, bool hunt, Object^ sender);

ref class Caviar
{
private:
	String^ path = "source\\Caviar.png";
	Size^ caviarSize = gcnew Size(20, 20);
	double x, y;
	int colorGen;
	int timeToBirth = 500;
	Image^ sprite;
	bool needToDel = false;
	bool birth = false;
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
			if (param >= 500) {
				deleteCaviar(this);
			}
		}
		double get() {
			return this->y;
		}
	}
	property bool doBirth {
		void set(bool param) {
			this->birth = param;
		}
		bool get() {
			return this->birth;
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
	property int birtTimer {
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
	event CaviarDeleteHandler^ deleteCaviar;
	event FishBirthHandler^ fishBirth;
	Caviar(double x, double y, int colorGen, bool huntFish);
	void drawSprite(Graphics^ g);
	void moveAnim();
};

