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
	LinkedNode<Type>* search(const  Type & )const ;
	bool Delete(const Type&);
	///   bool Pick(Type &);
	void dispaly()const ;
	bool  get_first(Type & );
	bool is_empty();
	List(const List<Type >&);
	void operator=(const List <Type >&);
	bool  Pick(Type &);
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

	if (std::is_pointer<Type>::value) 
	{
		if (*(Head->Get_data()) == *Data)
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
			if (*(curr->Get_Next()->Get_data()) == *Data)
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
inline bool  List<Type>::get_first( Type & Data )
{
	if (!Head)
		return false;
	Data= Head->Get_data();
	return true;
}

template<class Type>
inline bool List<Type>::is_empty()
{
	if (Head) 
	{
		return false;
	}
	return true;
}

template<class Type>
inline List<Type>::List(const List<Type>& Ptr )
{
	Head = NULL;
	LinkedNode <Type > *curr = Ptr.Head;
	while (curr != NULL) 
	{
		this->Insert(curr->Get_data());
		curr = curr->Get_Next();
	
	}
}

template<class Type>
inline void List<Type>::operator=(const List<Type>&)
{

	LinkedNode <Type >* curr = Ptr.Head;
	while (curr != NULL)
	{
		this->Insert(curr->Get_data());
		curr = curr->Get_Next();
	}
}

template<class Type>
inline bool List<Type>::Pick( Type & Data)
{
	if (Head == NULL)
		return false;

	if (std::is_pointer<Type>::value)
	{
		if (*(Head->Get_data()) == *Data)
		{
			Data = Head->Get_data();
			LinkedNode <Type >*curr = Head;
			Head = Head->Get_Next();
			delete curr;
			curr = NULL;
			return true;
		}
		LinkedNode <Type >*curr = Head;
		while (curr->Get_Next())
		{
			if (*(curr->Get_Next()->Get_data()) == *Data)
			{
				Data = curr->Get_Next()->Get_data();
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
	if (Head->Get_data() == Data)
	{
		Data = Head->Get_data();
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
			Data = curr->Get_Next()->Get_data();
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

