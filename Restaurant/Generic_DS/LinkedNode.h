#pragma once
// all Ds are implemented by (abdalla mahmoud ) 
#include<iostream>
using namespace std;
template<class Type>
class LinkedNode
{
	Type data;
	LinkedNode<Type> * Next;
public:
	LinkedNode();
	void Set_data(const Type& );
	void Set_Next(LinkedNode  < Type >*);
	Type Get_data();
	LinkedNode<Type>* Get_Next();
};

template<class Type>
inline LinkedNode<Type>::LinkedNode()
{
}

template<class Type>
inline void LinkedNode<Type>::Set_data(const Type & data)
{
	this->data = data;
}

template<class Type>
inline void LinkedNode<Type>::Set_Next(LinkedNode<Type>* next)
{
	this->Next = next;
}

template<class Type>
inline Type LinkedNode<Type>::Get_data()
{
	return data;
}

template<class Type>
inline LinkedNode<Type>* LinkedNode<Type>::Get_Next()
{
	return Next;
}
