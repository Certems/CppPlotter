#include <iostream>

#include "manager.h"

int main()
{
    std::cout<<"Main Started..."<<std::endl;

    Manager* cManager = new Manager();
    cManager->Generate_DataArray();
    cManager->Write_AllData();
    //cManager->BugFix_Output_DataArray();

    std::cout<<"Main Ended..."<<std::endl;
    return 0;
}