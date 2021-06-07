#pragma once


#include "Fish.h"
#include "Caviar.h"


//Примечание
//Вся реализация конструкторов, методов и т.п. будет находится в:
//HFish.cpp


public delegate void fishEatingHandler(Object^ sender);

ref class HFish :
    public Fish
{
private:
    String^ path = "source\\HuntFish.png";
    String^ path2 = "source\\HuntFishLeft.png";
public:
    HFish(double x, double y, int size);
    void foodEatingMethod();
    void fishDetectedMethod(Object^ sender, double x, double y, int level);
    void fishEatingMethod();
    void createCaviarMethod();
    void moveAnim();
    event fishEatingHandler^ fishEating;
};

