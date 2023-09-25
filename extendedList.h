#pragma once

template <typename Type>
class DataNode
{
    public:
        DataNode();
        ~DataNode();
    private:
        //pass
    public:
        void Add(Type* newValue);
        Type* Get(int currentIndex, int requiredIndex);
        Type* value;
        DataNode<Type>* nextNode;
};

template <typename Type>
class ExtendedList
{
    public:
        ExtendedList();
        ~ExtendedList();
    private:
        //pass
    public:
        DataNode<Type>* initDataNode;
        void Add(Type* value);
        Type* Get(int index);
};