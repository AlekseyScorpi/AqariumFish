#pragma once
#include "Food.h"
#include "Caviar.h"


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


//Примечание
//Вся реализация конструкторов, методов и т.п. будет находится в:
//Fish.cpp

public delegate Point FoodDetectedHandler(Food^ food);
public delegate void CreateCaviarHandler(double x, double y, int color, bool hunt);
public delegate void DeleteFishHandler(Object^ sender);
public delegate void FoodEatingHandler(Object^ sender);
public delegate void ExistsFishHandler(Object^ sender, double x, double y, int lvl);

ref class Fish
{
private:
	String^ path = "source\\Fish.png";
	String^ path2 = "source\\FishLeft.png";
	String^ path3 = "source\\Fish2.png";
	String^ path4 = "source\\FishLeft2.png";
	String^ path5 = "source\\Fish3.png";
	String^ path6 = "source\\FishLeft3.png";
protected:
	Size^ fishSize;
	double fishEnergy;
	Bitmap^ fishLeft;
	Bitmap^ fishRight;
	double newX, newY;
	double x, y, speed;
	double visibleDistance;
	int level;
	Image^ sprite;
	bool seeFood = false;
	int colorGen;
	int maxEnergy;
	int foodColdown = 0;
	double currentDistanceToAnyFood = 10000;
	double calculateDistance(double x1, double y1, double x2, double y2);
	bool isHunt = false;
public:
	int getMaxEnergy();
	property double energy {
		double get() {
			return this->fishEnergy;
		}
		void set(double energy) {
			this->fishEnergy = energy;
			if (energy <= 0) {
				death(this);
			}
			if (energy > this->maxEnergy) {
				if (size != 5) {
					this->fishEnergy = energy - maxEnergy / 2;
					this->size++;
					this->maxEnergy = 1000 * size;
					this->fishSize = gcnew Size(80 + 20 * size, 50 + 18 * size);
					this->speed = 1.8 - 0.15 * size;
					this->visibleDistance = 200 + 20 * size;
				}
				else {
					createCaviarMethod();
				}
			}
		}
	}
	property double xCoord{
		double get() {
			return this->x;
		}
	}
	property double yCoord {
		double get() {
			return this->y;
		}
	}
	property double newXCoord {
		double get() {
			return this->newX;
		}
		void set(double param) {
			this->newX = param;
		}
	}
	property double newYCoord {
		double get() {
			return this->newY;
		}
		void set(double param) {
			this->newY = param;
		}
	}
	property int foodCd {
		int get() {
			return this->foodColdown;
		}
		void set(int param) {
			this->foodColdown = param;
		}
	}
	int getColor();
	property int size {
		int get() {
			return this->level;
		}
		void set(int param) {
			this->level = param;
		}
	}
	property bool doSeeFood {
		bool get() {
			return this->seeFood;
		}
		void set(bool param) {
			this->seeFood = param;
		}
	}
	double getHeight();
	event FoodDetectedHandler^ foodDetected;
	event CreateCaviarHandler^ createCaviar;
	event DeleteFishHandler^ death;
	event FoodEatingHandler^ foodEating;
	event ExistsFishHandler^ existsFish;
	double getVisibleDistance();
	Fish(double x, double y, int size, int colorGen);
	void drawSprite(Graphics^ g);
	void move(float x, float y);
	void moveAnim();
	void foodDetectedMethod(Object^ sender, double x, double y);
	void foodEatingMethod();
	void createCaviarMethod();
};

