#pragma once

class Equation
{
public:
    Equation(int equationType);
    ~Equation();
public:
    float GetValue(float xCoord, float yCoord);
public:
    int type;
private:
    //pass
};