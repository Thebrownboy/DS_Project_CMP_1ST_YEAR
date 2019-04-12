#pragma once
// all Ds are implemented by (abdalla mahmoud  ) 
#include<iostream>
using namespace std;
template<class Type >
class Treenode {
	Type data;
	Treenode<Type>* Right, *Left;
public:
	Treenode();
	void Set_data(const Type& );
	void Set_right(Treenode < Type >*);
	void Set_left(Treenode<Type>*);
	Type Get_data()const ;
	Treenode<Type>* Get_right()const ;
	Treenode<Type>* Get_left()const ;
};

template<class Type>
inline Treenode<Type>::Treenode()
{
}

template<class Type>
inline void Treenode<Type>::Set_data(const Type&  data)
{
	this->data = data;

}

template<class Type>
inline void Treenode<Type>::Set_right(Treenode<Type>* right)
{
	this->Right = right;
}

template<class Type>
inline void Treenode<Type>::Set_left(Treenode<Type>* left)
{
	this->Left = left;
}

template<class Type>
inline Type Treenode<Type>::Get_data()const 
{
	return data;
}

template<class Type>
inline Treenode<Type>* Treenode<Type>::Get_right()const 
{
	return Right;
}

template<class Type>
inline Treenode<Type>* Treenode<Type>::Get_left()const 
{
	return Left;
}