#pragma once
// all Ds are implemented by (abdalla mahmoud ) 
#include"TreeNode.h"
template<class Type>
class BinaryTree
{
	Treenode<Type>* Root;
	Treenode<Type>* Get_dep(Treenode<Type> *, Treenode<Type>*&);
	void displayo(Treenode<Type>*)const;
	void Delete_elem(Treenode <Type >*, Treenode <Type >*);
	void insert(Treenode<Type>*);
	void Delete(Treenode<Type >*);


public:
	void Insert(const Type& Data);
	void Delete_max();
	Type Peek()const;
	void display()const;
	bool Is_empty()const;
	bool Delete(const Type&);
	BinaryTree();
	BinaryTree(const BinaryTree<Type>&);
	void operator=(const BinaryTree<Type>&);
	virtual ~BinaryTree();
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
inline void BinaryTree<Type>::Insert(const Type& Data)
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
	if (std::is_pointer<Type>::value) 
	{
		while (true)
		{
			if (*Data > *(path->Get_data()))
			{
				if (path->Get_right() != NULL)
					path = path->Get_right();
				else
				{
					path->Set_right(curr);
					return;
				}
			}
			else
			{
				if (path->Get_left() != NULL)
					path = path->Get_left();
				else
				{
					path->Set_left(curr);
					return;
				}
			}
		}
	}
	else 
	{
	
		while (true)
		{
			if (Data > path->Get_data())
			{
				if (path->Get_right() != NULL)
					path = path->Get_right();
				else
				{
					path->Set_right(curr);
					return;
				}
			}
			else
			{
				if (path->Get_left() != NULL)
					path = path->Get_left();
				else
				{
					path->Set_left(curr);
					return;
				}
			}
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
inline Type BinaryTree<Type>::Peek()const
{
	Treenode<Type>* curr = Root;
	if (Root == NULL)
	{
		abort();
	}
	if (Root->Get_right() == NULL)
	{
		return Root->Get_data();
	}
	while (curr->Get_right())
		curr = curr->Get_right();

	return curr->Get_data();
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
		return false;
	if (Root->Get_data() == Data)
	{
		if (!Root->Get_left() && !Root->Get_right())
		{
			delete Root;
			Root = NULL;
			return true;
		}
		if (Root->Get_right() == NULL)
		{
			Treenode <Type>* curr = Root;
			Root = Root->Get_left();
			delete curr;
			curr = NULL;
			return true;
		}
		if (Root->Get_left() == NULL)
		{
			Treenode <Type>* curr = Root;
			Root = Root->Get_right();
			delete curr;
			curr = NULL;
			return true;
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
			return true;
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
inline BinaryTree<Type>::BinaryTree(const BinaryTree<Type> & tree)
{
	Root = NULL;// here if  i don't  amake it with NULL it will be undefiend bc it doesn't enter the defualt constructor 
	this->insert(tree.Root);
}

template<class Type>
inline void BinaryTree<Type>::operator=(const  BinaryTree<Type>& tree)
{
	this->insert(tree.Root);
}

template<class Type>
inline BinaryTree<Type>::~BinaryTree()
{
	Delete(Root);
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

template<class Type>
inline void BinaryTree<Type>::insert(Treenode<Type>* node)
{
	if (node == NULL)
	{
		return;
	}
	Insert(node->Get_data());
	insert(node->Get_left());
	insert(node->Get_right());
}

template<class Type>
inline void BinaryTree<Type>::Delete(Treenode<Type>* node)
{
	if (node == NULL)
		return;
	Delete(node->Get_right());
	Delete(node->Get_left());
	delete node;
	node = NULL;
}
