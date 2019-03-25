#pragma once
// all Ds are implemented by (abdalla mahmoud ) 
#include"TreeNode.h"
template<class Type>
class BinaryTree
{
	Treenode<Type>* Root;
	Treenode<Type>* Get_dep(Treenode<Type> *, Treenode<Type>*&);
	void displayo(Treenode<Type>*)const ;
	void Delete_elem(Treenode <Type >*, Treenode <Type >*);

public:
	void Insert( Type& Data);
	void Delete_max();
	Type* Peek();
	void display()const ;
	bool Is_empty()const ;
	bool Delete(const Type& );
	BinaryTree();
};

template<class Type>
inline Treenode<Type>* BinaryTree<Type>::Get_dep(Treenode<Type>* curr, Treenode<Type>*&prev)
{

	Treenode<Type>* dep = curr, *temp;
	while (dep->Get_left() || dep->Get_right())
	{
		if (dep->Get_right() != NULL)
		{
			temp = dep;
			dep = dep->Get_right();
			prev = temp;
		}
		else
		{
			temp = dep;
			dep = dep->Get_left();
			prev = temp;
		}
	}
	return dep;
}

template<class Type>
inline void BinaryTree<Type>::Insert( Type& Data)
{
	Treenode<Type>* curr = new Treenode<Type>();
	curr->Set_data(Data);
	curr->Set_left(NULL);
	curr->Set_right(NULL);
	if (Root == NULL)
	{
		Root = curr;
		return;
	}
	Treenode<Type>*  path = Root;
	while (true)
	{
		if (Data > path->Get_data())
		{
			if (path->Get_right() == NULL) {
				path->Set_right(curr);
				return;
			}
			path = path->Get_right();
		}
		else
		{
			if (path->Get_left() == NULL)
			{
				path->Set_left(curr);
				return;
			}
			path = path->Get_left();
		}
	}
}

template<class Type>
inline void BinaryTree<Type>::Delete_max()
{
	Treenode<Type >* curr = Root, *prev = Root;
	if (Root == NULL)
	{
		return;
	}
	if (Root->Get_right() == NULL)
	{
		Root = Root->Get_left();
		delete curr;
		curr = NULL;
		return;
	}
	curr = curr->Get_right();
	while (curr->Get_right())
	{
		prev = curr;
		curr = curr->Get_right();
	}
	Delete_elem(curr, prev);
}

template<class Type>
inline Type* BinaryTree<Type>::Peek()
{
	Treenode<Type>* curr = Root;
	if (Root == NULL)
	{
		return nullptr;
	}
	if (Root->Get_right() == NULL)
	{
		Type Temp = Root->Get_data();
		Type* ptr = &Temp;
		return ptr;
	}
	while (curr->Get_right())
		curr = curr->Get_right();

	Type Temp = curr->Get_data();
	Type* ptr = &Temp;
	return ptr;
}

template<class Type>
inline void BinaryTree<Type>::display()const 
{
	displayo(Root);
}

template<class Type>
inline bool BinaryTree<Type>::Is_empty()const 
{
	if (Root)
		return false;
	return true;
}

template<class Type>
inline bool  BinaryTree<Type>::Delete(const Type&  Data)
{
	if (Root == NULL)
		return false ;
	if (Root->Get_data() == Data)
	{
		if (!Root->Get_left() && !Root->Get_right())
		{
			delete Root;
			Root = NULL;
			return true ;
		}
		if (Root->Get_right() == NULL)
		{
			Treenode <Type>* curr = Root;
			Root = Root->Get_left();
			delete curr;
			curr = NULL;
			return true ;
		}
		if (Root->Get_left() == NULL)
		{
			Treenode <Type>* curr = Root;
			Root = Root->Get_right();
			delete curr;
			curr = NULL;
			return true ;
		}
		Treenode<Type>* curr = Root, *prev = curr;
		Delete_elem(curr, prev);// here I am sure That root has two children 
	}
	Treenode<Type>* curr, *prev = Root;
	if (Data > Root->Get_data())
		curr = curr->Get_right();
	else
		curr = curr->Get_left();

	while (curr)
	{
		if (curr->Get_data() == Data)
		{

			Delete_elem(curr);
			return true ;
		}
		if (Data > curr->Get_data())
		{
			prev = curr;
			curr = curr->Get_right();
		}
		else
		{
			prev = curr;
			curr = curr->Get_left();
		}
	}
	return false;
}

template<class Type>
inline BinaryTree<Type>::BinaryTree()
{
	Root = NULL;
}

template<class Type>
inline void BinaryTree<Type>::displayo(Treenode<Type>* curr)const 
{
	if (curr == NULL)
		return;
	cout << curr->Get_data() << " ";
	displayo(curr->Get_right());
	displayo(curr->Get_left());
}
template<class Type>
inline void BinaryTree<Type>::Delete_elem(Treenode<Type>* curr, Treenode <Type >*prev)
{
	if (!curr->Get_left() && !curr->Get_right()) // if it was a leaf 
	{
		if (prev->Get_left() == curr)
		{
			delete curr;
			curr = NULL;
			prev->Set_left(NULL);
			return;
		}
		else
		{
			delete curr;
			curr = NULL;
			prev->Set_right(NULL);
			return;
		}
	}
	//has one child
	if (curr->Get_left() == NULL)
	{
		if (curr == prev->Get_left())
		{
			prev->Set_left(curr->Get_right());
			delete curr;
			curr = NULL;
			return;
		}
		else
		{
			prev->Set_right(curr->Get_right());
			delete curr;
			curr = NULL;
			return;
		}
	}
	if (curr->Get_right() == NULL)
	{
		if (curr == prev->Get_left())
		{
			prev->Set_left(curr->Get_left());
			delete curr;
			curr = NULL;
			return;
		}
		else
		{
			prev->Set_right(curr->Get_left());
			delete curr;
			curr = NULL;
			return;
		}
	}
	// if it has two children 
	Treenode<Type >* temp = curr;
	prev = curr;
	curr = curr->Get_right();
	while (curr->Get_left())
	{
		prev = curr;
		curr = curr->Get_left();
	}
	temp->Set_data(curr->Get_data());
	Delete_elem(curr, prev);
}
