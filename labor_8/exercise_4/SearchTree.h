#pragma once
#include "Tree.h"
#include <utility>

template <class T>
class SearchTree : public Tree<T>
{
public:
	void add(T value);
	bool search(T value)
	{
		return search(this->root, value);
	}
	void remove(T value) { return remove(this->root, value); }
	int level(T val) {
		if (level(this->root, val) == -1)return -1;
		else return level(this->root, val);
	}
private:
	void add(Node<T>* current, T val);
	bool search(Node<T>* current, T val);
	void remove(Node<T>*& current, T value);
	int level(Node<T>* current, T val);
	Node<T>*  succ(Node<T>* current) {
		Node<T>* succ1 = NULL;
		if (current->right)
			succ1 = min(current->right);
		return succ1;
	}
	Node<T>*  min(Node<T>* current) {
		if (current->left)return min(current->left);
		return current;
	}
};

template <class T>
void SearchTree<T>::add(T val)
{
	if (!this->root)
	{
		this->root = new Node<T>(val);
		return;
	}
	add(this->root, val);
}

template <class T>
bool SearchTree<T>::search(Node<T>* current, T val)
{
	if (!current)
		return false;  
	if (current->value == val)
		return true;
	if (current->value < val)
		return search(current->right, val);
	else
		return search(current->left, val);
}

template <class T>
void SearchTree<T>::add(Node<T>* current, T val)
{
	if (current->value < val)
	{  
		if (!current->right)
		{
			current->right = new Node<T>(val);
			return;
		}
		else
			add(current->right, val);
	}
	else
	{   
		if (!current->left)
		{
			current->left = new Node<T>(val);
			return;
		}
		else
			add(current->left, val);
	}
}

template <class T>
void SearchTree<T>::remove(Node<T>*& current, T val)
{
	if (!current)
		return; 
	if (current->value == val)
	{
		if (!current->left && !current->right) 
		{
			delete current;
			current = NULL;
			return;
		}
		if (current->left &&current->right) 
		{
			Node<T>* tmp = succ(current);
			current->value = tmp->value;
			return remove(current->right, current->value);

		}
		if (!current->right) 
		{
			Node<T>* tmp = current->left;
			delete current;
			current = tmp;
			return;
		}
		if (!current->left) 
		{
			Node<T>* tmp = current->right;
			delete current;
			current = tmp; return;
		}
	}
	if (current->value < val)
		return remove(current->right, val);
	else
		return remove(current->left, val);
}
template <class T>
int SearchTree<T>::level(Node<T>* current, T val)
{
	if (!search(current, val))
		return -1;
	if (current->value == val)
		return 0;
	if (current->value < val)
		return 1 + level(current->right, val);
	else
		return 1 + level(current->left, val);
}