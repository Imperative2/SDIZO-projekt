#include "stdafx.h"
#include "RBT.h"
#include <iostream>
#include <iomanip>
//konstruktor rbt
RBT::RBT()
{
	NodeRBT * temp = new NodeRBT();
	temp->color = 'b';
	temp->leftSon = sentinel;
	temp->rightSon = sentinel;
	temp->data = NULL;
	sentinel = temp;
	root = sentinel;

}
//dodaje wêze³ do drzewa
void RBT::add(int i)
{
	
	NodeRBT * temp;

	temp = new NodeRBT;        
	temp->leftSon = sentinel;          
	temp->rightSon = sentinel;
	temp->parent = root;
	temp->data = i;
	if (temp->parent == sentinel)
	{
		root = temp;
	}
	else
		while (true)            
		{
			if (i < temp->parent->data)
			{
				if (temp->parent->leftSon == sentinel)
				{
					temp->parent->leftSon = temp;  
					break;
				}
				temp->parent = temp->parent->leftSon;
			}
			else
			{
				if (temp->parent->rightSon == sentinel)
				{
					temp->parent->rightSon = temp;
					break;
				}
				temp->parent = temp->parent->rightSon;
			}
		}
	temp->color = 'r';  
	repair(temp);
}
//zwraca wartoœæ max drzewa
int RBT::findMax()
{
	if (root == sentinel)
	{
		std::cout << "drzewo jest puste!!! " << std::endl;
		return NULL;
	}
	else
	{
		NodeRBT* temp = root;
		while (temp->rightSon != sentinel)
		{
			temp = temp->rightSon;
		}
		return temp->data;
	}
	return 0;
}
//zwraca wêze³ minimalny w dzewie
NodeRBT * RBT::findMin(NodeRBT *t)
{
	if (t != sentinel)
	{
		while (t->leftSon != sentinel)
		{
			t = t->leftSon;
		}
	}
	return t;
}

//zwraca weze³ z dan¹ wartoœci¹
NodeRBT * RBT::findNode(int i)
{
	
	NodeRBT * temp;

	temp = root;
	while ((temp != sentinel) && (temp->data != i))
	{


		if (i < temp->data)
		{
			temp = temp->leftSon;
		}
		else
		{
			temp = temp->rightSon;
		}
		if (temp == sentinel) return NULL;
	}
		return temp;
}
//znajduje nastêpnika
NodeRBT * RBT::findNext(NodeRBT * temp)
{
	NodeRBT * r;

	if (temp != sentinel)
	{
		if (temp->rightSon != sentinel) return findMin(temp->rightSon);
		else
		{
			r = temp->parent;
			while ((r != sentinel) && (temp == r->rightSon))
			{
				temp = r;
				r = r->parent;
			}
			return r;
		}
	}
	return sentinel;
}
//rotacja w lewo
void RBT::rotL(NodeRBT * A)
{ 
	NodeRBT * B, *p;

	B = A->rightSon;
	if (B != sentinel)
	{
		p = A->parent;
		A->rightSon = B->leftSon;
		if (A->rightSon != sentinel)
		{
			A->rightSon->parent = A;
		}

		B->leftSon = A;
		B->parent = p;
		A->parent = B;

		if (p != sentinel)
		{
			if (p->leftSon == A)
			{
				p->leftSon = B;
			}
			else
			{
				p->rightSon = B;
			}
		}
		else root = B;
	}
}
//rotacja w prawo
void RBT::rotR(NodeRBT * A)
{
	NodeRBT * B, *p;

	B = A->leftSon;
	if (B != sentinel)
	{
		p = A->parent;
		A->leftSon = B->rightSon;
		if (A->leftSon != sentinel)
		{
			A->leftSon->parent = A;
		}

		B->rightSon = A;
		B->parent = p;
		A->parent = B;

		if (p != sentinel)
		{
			if (p->leftSon == A)
			{
				p->leftSon = B;
			}
			else
			{
				p->rightSon = B;
			}
		}
		else root = B;
	}

}
//wyswietla
void RBT::display()
{
	if (root != sentinel)
		pre(root);
	std::cout<<"\n\n" << std::endl;
	nett(root, 0);
}
//formatuje wyswietlanie
void RBT::nett(NodeRBT * current, int indent)
{
	if (current != sentinel)
	{
		nett(current->leftSon, indent + 5);
		if (indent > 0)
			std::cout << std::setw(indent) << " ";
		std::cout << current->data<<current->color << std::endl;
		nett(current->rightSon, indent + 5);
	}
}
//zwraca korzen
int RBT::getRoot()
{
	return root->data;
}

void RBT::postDel(NodeRBT * t)
{
	std::cout << " " << t->data;
	if (t->leftSon != sentinel)
		pre(t->leftSon);
	if (t->rightSon != sentinel)
		pre(t->rightSon);
	delete t;
}
//naprawa drzewa po dodawaniu wez³a
void RBT::repair(NodeRBT * t1)
{
	NodeRBT * t2;
	while ((t1 != root) && (t1->parent->color == 'r'))
	{
		if (t1->parent == t1->parent->parent->leftSon)
		{
			t2 = t1->parent->parent->rightSon; 
			//case 1 father 'r' uncle 'r'
			if (t2->color == 'r')  
			{
				t1->parent->color = 'b';
				t2->color = 'b';
				t1->parent->parent->color = 'r';
				t1 = t1->parent->parent;
				continue;
			}
			//case 2 t1- right son 2 father'r' uncle 'b'
			if (t1 == t1->parent->rightSon) 
			{
				t1 = t1->parent;
				rotL(t1);
			}
			//case 3 t1 - left son father 'r' uncle 'b'
			t1->parent->color = 'b';
			t1->parent->parent->color = 'r';
			rotR(t1->parent->parent);
			break;
		}
		else
		{                  // Przypadki lustrzane
			t2 = t1->parent->parent->leftSon;
			//case 1 mirror
			if (t2->color == 'r')
			{
				t1->parent->color = 'b';
				t2->color = 'b';
				t1->parent->parent->color = 'r';
				t1 = t1->parent->parent;
				continue;
			}
			//case 2 mirror
			if (t1 == t1->parent->leftSon) 
			{
				t1 = t1->parent;
				rotR(t1);
			}
			//case 3 mirror
			t1->parent->color = 'b'; 
			t1->parent->parent->color = 'r';
			rotL(t1->parent->parent);
			break;
		}
	}
	root->color = 'b';
}
// naprawa drzewa po usunieciu wezla
void RBT::repairDell(NodeRBT * X, NodeRBT* Y, NodeRBT* Z)
{
	NodeRBT* W;
	if (Y->color == 'b')  
	{
		while ((Z != root) && (Z->color == 'b'))
		{
			if (Z == Z->parent->leftSon)
			{
				W = Z->parent->rightSon;

				if (W->color == 'r')
				{            
					W->color = 'b';
					Z->parent->color = 'r';
					rotL(Z->parent);
					W = Z->parent->rightSon;
				}

				if ((W->leftSon->color == 'b') && (W->rightSon->color == 'b'))
				{            
					W->color = 'r';
					Z = Z->parent;
					continue;
				}

				if (W->rightSon->color == 'b')
				{            
					W->leftSon->color = 'b';
					W->color = 'r';
					rotR(W);
					W = Z->parent->rightSon;
				}

				W->color = Z->parent->color;
				Z->parent->color = 'b';
				W->rightSon->color = 'b';
				rotL(Z->parent);
				Z = root;         
			}
			else
			{              
				W = Z->parent->leftSon;

				if (W->color == 'r')
				{             
					W->color = 'b';
					Z->parent->color = 'r';
					rotR(Z->parent);
					W = Z->parent->leftSon;
				}

				if ((W->leftSon->color == 'b') && (W->rightSon->color == 'b'))
				{            
					W->color = 'r';
					Z = Z->parent;
					continue;
				}

				if (W->leftSon->color == 'b')
				{           
					W->rightSon->color = 'b';
					W->color = 'r';
					rotL(W);
					W = Z->parent->leftSon;
				}

				W->color = Z->parent->color;  
				Z->parent->color = 'b';
				W->leftSon->color = 'b';
				rotR(Z->parent);
				Z = root;        
			}
		}
	}

}

// wyswietla metoda preorder
void RBT::pre(NodeRBT * t)
{
	std::cout << " " << t->data<<t->color;
	if (t->leftSon != sentinel)
		pre(t->leftSon);
	if (t->rightSon != sentinel)
		pre(t->rightSon);
}
//usuwa wezel na pozycji i
void RBT::deleteAt(int i)
{
	
	NodeRBT* X;

	if (findNode(i) != sentinel)
	{
		X = findNode(i);
	}
	else
	{
		std::cout << "none such element!!" << std::endl;
		return;
	}
	NodeRBT  *Y, *Z;

	if ((X->leftSon == sentinel) || (X->rightSon == sentinel))
	{
		Y = X;
	}
	else
	{
		Y = findNext(X);
	}

	if (Y->leftSon != sentinel)
	{
		Z = Y->leftSon;
	}
	else
	{
		Z = Y->rightSon;
	}

	Z->parent = Y->parent;

	if (Y->parent == sentinel)
	{
		root = Z;
	}
	else if (Y == Y->parent->leftSon)
	{
		Y->parent->leftSon = Z;
	}
	else
	{
		Y->parent->rightSon = Z;
	}

	if (Y != X) X->data = Y->data;

	repairDell(X, Y, Z);

	Z->color = 'b';

	delete Y;
}



//zwalnia drzewo 
void RBT::relese(NodeRBT * t)
{
	if (t != sentinel)
	{
		relese(t->rightSon);
		relese(t->leftSon);
		delete t;
	}
}
void RBT::findVal(int val)
{

	if (findNode(val) != NULL)
	{
		std::cout << "wartosc znaleziona" << std::endl;
	}
	else
	{
		std::cout << "wartosc nie znaleziona!!" << std::endl;
		return;
	}
}
//destruktor rbt
RBT::~RBT()
{
	relese(root);
	root = NULL;
	delete sentinel;
}
