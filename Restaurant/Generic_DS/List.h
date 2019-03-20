#pragma once
// all Ds are implemented by (abdalla mahmoud  ) 
#include"LinkedNode.h"
template<class Type>
class List
{
	LinkedNode<Type >* Head;

public:
	List();
	void Insert(const Type& );
	LinkedNode<Type>* search(const  Type& )const ;
	bool Delete(const Type& );
	void dispaly()const ;
};

template<class Type>
inline List<Type>::List()
{
	Head = NULL;
}

template<class Type>
inline void List<Type>::Insert(const Type & Data)
{
	LinkedNode <Type >* p = new LinkedNode<Type >;
	p->Set_data(Data);
	p->Set_Next(NULL);
	if (Head == NULL)
	{
		Head = p;
		return;
	}
	LinkedNode <Type >* curr = Head;
	while (curr->Get_Next())
	{
		curr = curr->Get_Next();
	}
	curr->Set_Next(p);
}

template<class Type>
inline bool List<Type>::Delete(const Type&  Data)
{
	if (Head == NULL)
		return false;

	if (Head->Get_data() == Data)
	{
		LinkedNode <Type >*curr = Head;
		Head = Head->Get_Next();
		delete curr;
		curr = NULL;
		return true;
	}
	LinkedNode <Type >*curr = Head;
	while (curr->Get_Next())
	{
		if (curr->Get_Next()->Get_data() == Data)
		{
			LinkedNode<Type >* del = curr->Get_Next();
			curr->Set_Next(del->Get_Next());
			delete del;
			del = NULL;
			return true;
		}
		curr = curr->Get_Next();
	}
	return false;
}
template<class Type>
inline void List<Type>::dispaly()const 
{
	if (Head == NULL)
		return;
	LinkedNode<Type>* curr = Head;
	while (curr)
	{
		cout << curr->Get_data() << " ";
		curr = curr->Get_Next();

	}
	cout << endl;
}

template<class Type>
inline LinkedNode<Type>* List<Type>::search(const Type&  Data) const 
{
	if (Head == NULL)
		return NULL;
	LinkedNode <Type >curr = Head;
	while (curr)
	{
		if (curr->data == Data)
		{
			return curr;
		}
		curr = curr->Get_Next();
	}
	return NULL;
}
