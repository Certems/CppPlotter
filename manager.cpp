#include <iostream>
#include <fstream>
#include "manager.h"

Manager::Manager()
{
    XgridDensity = 20;
    YgridDensity = 20;
    XgridJump = 2.4;
    YgridJump = 2.4;
    cEquation = new Equation(1);
    DataArray = new ExtendedList<ExtendedList<float>>(); //2D Array to store data -> Dynamic=>less efficient, however was good practice creating it
    DataArray_1D = new ExtendedList<float>();
}
Manager::~Manager()
{
    //pass
}
void Manager::Empty_DataArray()
{
    //pass
}
void Manager::Generate_DataArray()
{
    std::cout<<"Generate DataArray..."<<std::endl;
    //std::cout<<"(Xden, Yden) = ("<<XgridDensity<<", "<<YgridDensity<<")"<<std::endl;
    //std::cout<<"(Xjum, Yjum) = ("<<XgridJump<<", "<<YgridJump<<")"<<std::endl;
    //std::cout<<"EquationType -> "<<cEquation->type<<std::endl;

    Empty_DataArray();  //Ensure it is clear before adding to it
    for(int j=0; j<YgridDensity; j++)
    {
        DataArray->Add(new ExtendedList<float>());
        for(int i=0; i<XgridDensity; i++)
        {
            float value = cEquation->GetValue(i*XgridJump,j*YgridJump);
            float* ptrValue = new float(value); //Has made the GIVEN VALUE a float ta its own memory address, and return to pointer to that new address
            DataArray->Get(j)->Add(ptrValue);
        }
    }
}
void Manager::BugFix_Output_DataArray()
{
    std::cout<<"BUG FIXING <..."<<std::endl;
    for(int j=0; j<YgridDensity; j++)
    {
        for(int i=0; i<XgridDensity; i++)
        {
            std::cout<<*(DataArray->Get(j)->Get(i))<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<"BUG FIXING ...>"<<std::endl;
}
void Manager::Write_AllData()
{
    std::cout<<"Writing all Data..."<<std::endl;

    std::ofstream DataFile("plotterForData/DataFile.txt");
    //Write spec
    DataFile <<XgridDensity<<","<<YgridDensity<<","<<XgridJump<<","<<YgridJump<<",";
    //Write array
    for(int j=0; j<YgridDensity; j++)
    {
        DataFile << "\n";   //Move to new line
        for(int i=0; i<XgridDensity; i++)
        {
            DataFile <<*(DataArray->Get(j)->Get(i))<<",";   //Write data value & comma
        }
    }
    DataFile.close();
}