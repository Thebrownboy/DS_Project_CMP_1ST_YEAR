#pragma once
// all Ds are implemented by (abdalla mahmoud  ) 
#include"BinaryTree.h"
template<class Type>
class PriorityQueue
{
	BinaryTree<Type> Tree;
public:
	PriorityQueue();
	void Enqueue(const Type&);
	void Dequeue();
	Type Peek()const;
	bool Is_Empty()const;
	virtual~PriorityQueue();

};

template<class Type>
inline PriorityQueue<Type>::PriorityQueue()
{
	Tree.~BinaryTree();
}

template<class Type>
inline void PriorityQueue<Type>::Enqueue(const  Type& Data)
{
	Tree.Insert(Data);
}

template<class Type>
inline void PriorityQueue<Type>::Dequeue()
{
	Tree.Delete_max();
}

template<class Type>
inline Type PriorityQueue<Type>::Peek()const
{
	return Tree.Peek();
}

template<class Type>
inline bool PriorityQueue<Type>::Is_Empty()const
{
	return Tree.Is_empty();
}

template<class Type>
inline PriorityQueue<Type>::~PriorityQueue()
{
	Tree.~BinaryTree();
}



