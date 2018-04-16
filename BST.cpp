#include "stdafx.h"
#include "BST.h"
#include <iostream>
#include <queue>
#include <cmath>
#include <string>
#include <iomanip>


//konstrutor Drzewa
BST::BST()
{

}
//dodaje element do drzewa
void BST::add(int i)
{
	if (root == NULL)
	{
		root = new NodeBST;
		root->data = i;
		root->leftSon = NULL;
		root->rightSon = NULL;
		return;
	}
	else
	{
		NodeBST* temp = root;
		while (true)
		{
			if (i<temp->data)
			{
				if (temp->leftSon != NULL)
				{
					temp = temp->leftSon;
				}

				else
				{
					temp->leftSon = new NodeBST;
					temp->leftSon->data = i;
					temp->leftSon->parent = temp;
					temp->leftSon->leftSon = NULL;
					temp->leftSon->rightSon = NULL;
					break;
				}

			}
			else if (i>temp->data)
			{
				if (temp->rightSon != NULL)
				{
					temp = temp->rightSon;
				}
				else
				{
					temp->rightSon = new NodeBST;
					temp->rightSon->data = i;
					temp->rightSon->parent = temp;
					temp->rightSon->leftSon = NULL;
					temp->rightSon->rightSon = NULL;
					break;
				}
			}
			else if (i == temp->data)
			{
				//std::cout << "values cannot be repeated!!!" << std::endl;
				break;
			}

		}
	}
}
//zwraca element max drzewa
int BST::findMax()
{
	if (root == NULL)
	{
		std::cout << "drzewo jest puste!!! " << std::endl;
		return NULL;
	}
	else
	{
		NodeBST* temp = root;
		while (temp->rightSon != NULL)
		{
			temp = temp->rightSon;
		}
		return temp->data;
	}
	return 0;
}
//zwraca element min drzewa
NodeBST * BST::findMin(NodeBST * t)
{
	NodeBST* temp = t;
	while (temp->leftSon != NULL)
	{
		temp = temp->leftSon;
	}
		return temp;

}
// wyszukuje weze³ drzewa
NodeBST * BST::findNode(int i)
{
	if (root == NULL)
	{
		return NULL;
	}
	NodeBST * temp = root;
	while (true)
	{
		if (i < temp->data)
		{
			if (temp->leftSon != NULL)
			{
				temp = temp->leftSon;
			}
			else return NULL;
		}
		else if (i > temp->data)
		{
			if (temp->rightSon != NULL)
			{
				temp = temp->rightSon;
			}
			else return NULL;
		}
		else
			return temp;
	}
	return NULL;
}
//usuwa weze³ z danym kluczem
void BST::deleteAtIndex(int i)
{
	NodeBST* temp;
	if (findNode(i) != NULL)
	{
		temp = findNode(i);
	}
	else
	{
		std::cout << "none such element!!" << std::endl;
		return;
	}

	if (temp->leftSon == NULL && temp->rightSon == NULL)
	{
		if (temp->parent == NULL)
		{
			delete temp;
			root = NULL;
			return;
		}
		else if (temp->data > temp->parent->data)
		{

			temp->parent->rightSon = NULL;

			delete temp;
			return;
		}
		else
		{
			temp->parent->leftSon = NULL;
			delete temp;
			return;
		}
	}
	if (temp->leftSon != NULL && temp->rightSon == NULL)
	{
		if (temp == root)
		{
			root = temp->leftSon;
			temp->leftSon->parent = NULL;
			delete temp;
			return;
		}
		else if (temp->data > temp->parent->data)
		{
			temp->parent->rightSon = temp->leftSon;
			temp->leftSon->parent = temp->parent;
			delete temp;
			return;
		}
		else
		{
			temp->parent->leftSon = temp->leftSon;
			temp->leftSon->parent = temp->parent;
			delete temp;
			return;
		}
	}
	if (temp->leftSon == NULL && temp->rightSon != NULL)
	{
		if (temp == root)
		{
			root = temp->rightSon;
			temp->rightSon->parent = NULL;
			delete temp;
			return;
		}
		else if (temp->data > temp->parent->data)
		{
			temp->parent->rightSon = temp->rightSon;
			temp->rightSon->parent = temp->parent;
			delete temp;
			return;
		}
		else
		{
			temp->parent->leftSon = temp->rightSon;
			temp->rightSon->parent = temp->parent;
			delete temp;
			return;
		}

	}
	if (temp->leftSon != NULL && temp->rightSon != NULL)
	{
		if (temp == root)
		{
			NodeBST * tt = new NodeBST;
			tt->leftSon = root->leftSon;
			tt->rightSon = root->rightSon;
			root = temp->rightSon;
			temp->parent = root;
			root->leftSon = tt->leftSon;
			delete temp;
			delete tt;
			return;
		}
		NodeBST * t1 = temp;
		NodeBST * t2 = t1->parent;
		NodeBST * t3 = t1->leftSon;
		NodeBST * t4 = t1->rightSon;
		temp = findNext(temp);
		temp->parent->leftSon = NULL;
		temp->parent = t2;
		temp->leftSon = t3;
		if(temp!=t4)
			temp->rightSon = t4;
		t3->parent = temp;
		t4->parent = temp;
		if (temp->data > t2->data)
		{
			t2->rightSon = temp;
		}
		else
		{
			t2->leftSon = temp;
		}
		
		return;
	}

	std::cout << "error in deleting" << std::endl;
	return;

}
//znajduje nastepnika
NodeBST * BST::findNext(NodeBST * temp)
{
	while (temp->rightSon != NULL)
	{
		return findMin(temp->rightSon);
	}
	return NULL;
}

//wyswiata drzewo metoda preorder
void BST::display()
{
	if(root!=NULL)
		pre(root);
	std::cout << "\n\n" << std::endl;
	nett(root, 0);
}
//metoda pre order s³uz¹ca do wyœwietlania drzewa
void BST::pre(NodeBST * t)
{
	std::cout << " " << t->data;
	if (t->leftSon != NULL)
		pre(t->leftSon);
	if (t->rightSon != NULL)
		pre(t->rightSon);
}
//generuje widok drzewa
void BST::nett(NodeBST * current, int indent)
{
	if (current != nullptr)
	{
		nett(current->leftSon, indent + 4);
		if (indent > 0)
			std::cout << std::setw(indent) << " ";
		std::cout << current->data << std::endl;
		nett(current->rightSon, indent + 4);
	}
}
//zwraca wartosc korzenia
int BST::getRoot()
{
	return root->data;
}

void BST::postDel(NodeBST * t)
{
	std::cout << " " << t->data;
	if (t->leftSon != NULL)
		pre(t->leftSon);
	if (t->rightSon != NULL)
		pre(t->rightSon);
	delete t;
}
//zwalnia drzewo
void BST::relese(NodeBST * t)
{

		if (t != NULL)
		{
			relese(t->leftSon);
			relese(t->rightSon);
			delete t;
		}
}

void BST::findVal(int val)
{
	//NodeBST* temp;
	if (findNode(val) != NULL)
	{
		//temp = findNode(val);
		std::cout << "wartosc znaleziona" << std::endl;
	}
	else
	{
		std::cout << "wartosc nie znaleziona!!" << std::endl;
		return;
	}

}



//destruktor bst
BST::~BST()
{
	relese(root);
	root = NULL;
}
