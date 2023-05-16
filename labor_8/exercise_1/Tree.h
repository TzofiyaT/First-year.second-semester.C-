#include <utility>
#pragma once
#include <iostream>
#include <string>

template <class T>
class Node
{
public:
	Node* left;
	Node* right;
	T value;
	Node(T val) : value(val), left(NULL), right(NULL) {}
	Node(T val, Node<T>* l, Node<T>* r)
		: value(val), left(l), right(r) {}
}; 

template <class T>
class Tree
{
protected:
	Node<T>* root;
public:
	Tree() { root = NULL; } 
	~Tree();
	int isEmpty() const;
	void clear() { clear(root); root = NULL; }
	void preOrder() { preOrder(root); }
	void inOrder() { inOrder(root); }
	void postOrder() { postOrder(root); }
	virtual void process(T val) { cout << val << " "; }
	virtual void add(T val) = 0;
	virtual bool search(T val) = 0;
	virtual void remove(T val) = 0;
	int leaves() { return leaves(root); }
	int height() { return height(root); }
	void reflect() { return reflect(root); }
	//int onlyLeftSon() { return onlyLeftSon(root); }
	int onlyLeftSon() { return onlyLeftSon(root); }

	int sumEvens(int);
private:
	int   sum(Node<int>* root, int level, int max);
	void  clear(Node<T>* current);
	void  preOrder(Node<T>* current);
	void  inOrder(Node<T>* current);
	void  postOrder(Node<T>* current);
	int leaves(Node<T> * current);
	int height(Node<T> * current); //
	void reflect(Node<T> * current);
	int onlyLeftSon(Node<T> * current);
	//int onlyLeftSon(Node<T> * current);
	void swap(Node<T> *& current_left, Node<T> *& current_right)
	{
		Node<T> * tmp = current_left;
		current_left = current_right;
		current_right = tmp;
	}
};

template <class T>
int Tree<T>::sumEvens(int max)
{
	return sum(root, 0, max);
}

template <class T>
int Tree<T>::sum(Node<int>* root, int level, int max)
{
	int x = 0;
	if (root)
	{
		level++; 
		if (level <= max)
		{
			int even = (root->value % 2) ? 0 : root->value;
			x = even + sum(root->left, level, max)
				+ sum(root->right, level, max);
			cout << "level = " << level << ". value = " << root->value
				<< ". sum = " << x << endl;
			return x;
		}
		else
			return 0;
	}
	else
		return 0;
}

template <class T>
Tree<T>::~Tree() 
{
	if (root != NULL)
		clear(root);
}

template <class T>
void Tree<T>::clear(Node<T>* current)
{
	if (current)
	{   
		if (current->left)
			clear(current->left);
		if (current->right)
			clear(current->right);
		delete current;
	}
}

template <class T>
int Tree<T>::isEmpty() const
{
	return  root == NULL;
}

template <class T>
void Tree<T>::preOrder(Node<T>* current)
{   
	if (current)
	{  
		process(current->value);
		preOrder(current->left);
		preOrder(current->right);
	}
}

template <class T>
void Tree<T>::inOrder(Node<T>* current)
{  
	if (current)
	{
		inOrder(current->left);
		process(current->value);
		inOrder(current->right);
	}
}

template <class T>
void Tree<T>::postOrder(Node<T> * current)
{    
	if (current)
	{
		postOrder(current->left);
		postOrder(current->right);
		process(current->value);
	}
}


template <class T>
int Tree<T>::leaves(Node<T> * current)
{

	if (!current)

		return 0;

	if ((!current->left) && (!current->right))
		return 1;
	return (this->leaves(current->left) + this->leaves(current->right));
}


template <class T>
int Tree<T>::height(Node<T> * current)
{
	int l, r;
	if (!current)
	{
		return -1;
	}

	l = height(current->left);
	r=  height(current->right);
	return ((r > l) ? r : l)+1;

}


//heigh of the tree
template <class T>
void Tree<T>::reflect(Node<T> * current)
{
	if (!current)
	{
		return;
	}

	this->reflect(current->left);
	this->reflect(current->right);
	Node<T> * help = current->left;
	current->left = current->right;
	current->right = help;
}


/*template <class T>
int Tree<T>::onlyLeftSon(Node<T> * current)
{
	if (!current)
		return 0;
	if (!current->right&&current->left)
		return onlyLeftSon(current->left) + 1;
	if (current->right && !current->left)
		return onlyLeftSon(current->right);
	else
	{
		return onlyLeftSon(current->right);
		return onlyLeftSon(current->left);
	}
}*/

//count the left sons
template <class T>
int Tree<T>::onlyLeftSon(Node<T> * current)
{
	if (!current)
	{
		return 0;
	}
	if ((current->left) && (!current->right))
		return onlyLeftSon(current->left) + 1;
	return onlyLeftSon(current->left) + onlyLeftSon(current->right);
}
