#pragma once

#include "equation.h"
#include "extendedList.h"

class Manager
{
public:
    Manager();
    ~Manager();
public:
    void Empty_DataArray();
    void Generate_DataArray();
    void BugFix_Output_DataArray();
    void Write_Specification();
    void Write_DataArray();
    void Write_AllData();
public:
    int XgridDensity;   //# of grid points measured in each axis
    int YgridDensity;   //
    float XgridJump;    //'Distance' between grid points
    float YgridJump;    //
    Equation* cEquation;
    ExtendedList<ExtendedList<float>>* DataArray;
    ExtendedList<float>* DataArray_1D;
private:
    //pass
};