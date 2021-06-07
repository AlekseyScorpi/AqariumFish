#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


//Примечание
//Вся реализация конструкторов, методов и т.п. будет находится в:
//Aquarium.cpp

public delegate void AquariumVentHandler();

ref class Aquarium
{
private:
	int ventWork;
	int remontTime = 150;
	bool remontProcess = false;
	double trashLvl;
public:
	event AquariumVentHandler^ remontSuccess;
	event AquariumVentHandler^ ventIsCrush;
	property int ventIsWork {
		int get() {
			return ventWork;
		}
		void set(int i) {
			this->ventWork = i;
			if (i == 0) {
				ventIsCrush();
			}
		}
	}
	property int remontTimer {
		int get() {
			return this->remontTime;
		}
		void set(int param) {
			if (param <= 0) {
				remontSuccess();
			}
			else {
				this->remontTime = param;
			}
		}
	}
	property bool isRemont {
		bool get() {
			return this->remontProcess;
		}
		void set(bool param) {
			this->remontProcess = param;
		}
	}
	property double currentTrash {
		double get() {
			return this->trashLvl;
		}
		void set(double param) {
			this->trashLvl = param;
		}
	}
	Aquarium();
};

