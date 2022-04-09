#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <functional>
#include "BNode.h"
using namespace std;


template <typename T>
class BTree
	//BTree with max degree M
{
	BNode<T>* root;
public:
	BTree() { /*root = NULL;*/ } //build an empty tree
	~BTree() { deleteTree(); } //dctor
	void insert(T x);      //add a value to the tree
	void deleteVal(T x);
	void deleteSubTree(BNode<T>* t); //delete of subtree and balancing original tree
	void deleteTree(); 
	void printSubTree(BNode<T>*,int);  // print all tree in ascending
	void printTree();
	void PrintPerDate(T t1,T t2) { printPerDate(root, 2,t1,t2 ); } // print all lending that containing specific date
	void printPerDate(BNode<T>*, int,T,T);
	void printAllKeys(T , T, int); // print all keys between x to y
	T* search(T x) { return search(root, x); }
	T* search(BNode<T>* p, T x, int);
	void balancing(BNode<T>*, T , T); //function of balancing tree after delete subtree
};


////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

template <typename T>
T* BTree<T>::search(BNode<T>* p, T x, int i)
{
	i = 0;
	while (i < p->nkeys)
	{
		if (p->key[i] > x)
			search(p->Son[i],x, i);
		else if (p->key[i] == x)
			return p->Key[i];
		else
			i++;

		return;
	}
}


template <typename T>
void BTree<T>::printAllKeys(T x1, T x2, int i)
{
	i = 0;
	while (i <= root->nkeys)
	{
		if (root->Key[i] > x1 || i == root->nkeys)
		{
			if (root->nsons != 0 && i != root->nkeys && root->Key[i] != x2)
			{
				root = root->Son[i];
				printAllKeys(x1, x2, i);
			}
				if (root->Key[i] <= x2)
				{
					cout << root->Key[i];
					i++;
				}
				else break;
		}
		else if (root->Key[i] == x1)
		{
			cout << root->Key[i];
			i++;
		}
		else
			i++;
	}
	return;
}

template <typename T>
void BTree<T>::deleteSubTree(BNode<T>* t)
{
	if (t->Son[0] == NULL) //if is leaf
		delete t; return;
	int i = 0;
	while (i != t->nsons)
	{
		deleteSubTree(t->Son[i]);
		i++;
	}
	// balancing of the original tree:
	t->parent->nsons -= 1;
	T temp1, temp2;
	balancing(t->parent, temp1,temp2);
}

template <typename T>
void BTree<T>::balancing(BNode<T>* t, T temp1, T temp2)
{
	if (!t->isleaf)
	{
		temp2 = t->Key[0];
		for (int i = 1; i < t->nkeys; i++)
		{
			t->Key[i - 1] = t->Key[i];
		}
		t->Key[t->nkeys] = temp1;
		temp1 = temp2;
		balancing(t->Son[0], temp1, temp2);
	}
}



template <typename T>
void BTree<T>::printSubTree(BNode<T>* t, int i)
{
	i = 0;
	while (t!= NULL  && (t->Son[0] != NULL) && (i <= t->nkeys)  || t != NULL&&(t->Son[0] == NULL && (i < t->nkeys))) // enter loop only if i<nkeys. two options: this leaf or not
	{
		if (t->Son[0] == NULL) //is leaf
		{
			cout << t->Key[i];
			i++;
		}
		else
		{
			printSubTree(t->Son[i], i); // in the first level, if this not leaf, continue todecline
			if (i <  t->nkeys)
				cout << t->Key[i];
			i++;
		}
	}
	return;// return to previous calling
}


template <typename T>
void BTree<T>::printPerDate(BNode<T>* t, int i,T t1, T t2)  // similar function of "deletesubtree", with additional conditions
{
	i = 0;
	while (t != NULL && (t->Son[0] != NULL) && (i <= t->nkeys) || t != NULL && (t->Son[0] == NULL && (i < t->nkeys)))
	{
		if (t->Son[0] == NULL)
		{
			if (t->Key[i] > t1 && t->Key[i] < t2) // if the Lending available between t1 - t2
			cout << t->Key[i];
			i++;
		}
		else
		{
			printSubTree(t->Son[i], i);
			if (i < t->nkeys)
			{
				if (t->Key[i] > t1&& t->Key[i] < t2)
				cout << t->Key[i];
			}
			i++;
		}
	}
	return;
}

template <typename T>
void BTree<T>::insert(T x) //add a value to the tree
{
	BNode<T>* tmp = NULL;
	T tx;
	if (root == NULL)
		root = new BNode<T>(x);
	else
	{
		root->insert(x, tx, tmp);
		if (tmp) //a split was done;
		{
			BNode<T>* newRoot = new BNode<T>(tx);
			newRoot->Son[0] = root;
			newRoot->Son[1] = tmp;
			root = newRoot;
		}
	}
}

template <typename T>
void BTree<T>::deleteVal(T x)
{
	T tmp;
	bool holeSent;
	if (root == NULL) return;
	root->deleteVal(x, false, tmp, holeSent); //and if a hole was return, the depth of all leaves reduces in one.
	if (holeSent == true)
		if (root->nsons == 1) //the son will be the root
		{
			BNode<T>* tmp = root;
			root = root->Son[0];
			delete tmp;
		}
	//otherwise, the root is allowed to have less than M/2 nodes.
}

template <typename T>
void BTree<T>::deleteTree()
{ deleteSubTree(root); }

template <typename T>
void BTree<T> :: printTree() 
{ printSubTree(root, 2); }
