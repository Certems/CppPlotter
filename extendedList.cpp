#include <iostream>
#include "extendedList.h"

template <typename Type>
DataNode<Type>::DataNode()
{
    value = nullptr;
    nextNode = nullptr;
}
template <typename Type>
DataNode<Type>::~DataNode()
{
    //pass
}
template <typename Type>
void DataNode<Type>::Add(Type* newValue)
{
    if(nextNode)  //If next node exists
    {
        nextNode->Add(newValue);
    }
    else
    {
        value    = newValue;
        nextNode = new DataNode<Type>();
    }
}
template <typename Type>
Type* DataNode<Type>::Get(int currentIndex, int requiredIndex)
{
    if(currentIndex >= requiredIndex)   //Should trigger when EQUAL, however > there just in case something goes wrong
    {
        return value;
    }
    else
    {
        if(nextNode)
        {
            return nextNode->Get(currentIndex+1, requiredIndex);
        }
        else
        {
            return nullptr; //## POSSIBLY CAN REMOVE THIS ##
        }
    }
}


template <typename Type>
ExtendedList<Type>::ExtendedList()
{
    initDataNode = new DataNode<Type>();
}
template <typename Type>
ExtendedList<Type>::~ExtendedList()
{
    //pass
}
template <typename Type>
void ExtendedList<Type>::Add(Type* value)
{
    /*
    Adds value to the end of the list
    */
    initDataNode->Add(value);
}
template <typename Type>
Type* ExtendedList<Type>::Get(int index)
{
    /*
    Gets value AT the given INDEX
    */
    return initDataNode->Get(0, index);
}
//Could add insert type functionality, but not needed here


template class DataNode<float>;
template class DataNode<DataNode<float>>;
template class ExtendedList<float>;
template class ExtendedList<ExtendedList<float>>;
