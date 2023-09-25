#include <iostream>
#include <cmath>
#include "equation.h"

Equation::Equation(int equationType)
{
    type = equationType;
}
Equation::~Equation()
{
    //pass
}
float Equation::GetValue(float xCoord, float yCoord)
{
    //std::cout<<"Evaluating equation at coordinate..."<<std::endl;
    if(type == 0)
    {
        float value = xCoord;
        if(fmod(floor(yCoord), 2) == 0)
        {
            value = 0.0;
        }
        return value;
    }
    else if(type == 1)
    {
        float value = sqrt( pow(xCoord,2) + pow(yCoord,2) );
        return value;
    }
    else
    {
        return 0;
    }
}