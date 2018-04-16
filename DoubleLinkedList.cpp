#include "stdafx.h"
#include "DoubleLinkedList.h"
#include <iostream>

//konstruktor listy dwukierunkowej
DoubleLinkedList::DoubleLinkedList()
{
}
//dodaje element na poczatek listy
void DoubleLinkedList::addFront(int element)
{
	size++;
	if (head == NULL)
	{
		Node* temp = new Node;
		temp->data = element;
		head = temp;
		tail = temp;
		return;
	}
	Node* temp = new Node;
	temp->data = element;
	head->prev = temp;
	temp->next = head;
	head = temp;
	

}
//dodaje element na koniec listy
void DoubleLinkedList::addBack(int element)
{
	size++;
	if (tail == NULL)
	{
		Node* temp = new Node;
		temp->data = element;
		head = temp;
		tail = temp;
		return;
	}
	Node* temp = new Node;
	temp->data = element;
	tail->next = temp;
	temp->prev = tail;
	tail = temp;

}
//dodaje element na index listy
void DoubleLinkedList::addAt(int index, int value)
{
	if (index<0) return;
	if (index >= size)
	{
		addBack(value);
		return;
	}
	if (index == 0)
	{
		addFront(value);
	}
	else if(size-index> index)
	{
		Node * temp = head;
		for (int i = 0; i <= index; i++)
		{
			temp = temp->next;
		}
		Node * t1 = new Node;
		t1->data = value;
		t1->prev = temp;
		t1->next = temp->next;
		temp->next->prev = t1;
		temp->next = t1;
		size++;
		return;
	}
	else
	{
		Node * temp = tail;
		for (int i = size-1; i > index; i--)
		{
			temp = temp->prev;
		}
		Node * t1 = new Node;
		t1->data = value;
		t1->next = temp;
		t1->prev = temp->prev;
		temp->prev->next = t1;
		temp->prev = t1;
		size++;
		return;
	}
}
// usuwa pierwszy element listy
void DoubleLinkedList::deleteHead()
{
	if (head == NULL) return;
	size--;
	if (head == tail)
	{
		delete head;
		head = NULL;
		tail = NULL;
		return;
	}
	Node* temp = head->next;
	temp->prev = NULL;
	delete head;
	head = temp;

}
//usuwa ostatni element listy
void DoubleLinkedList::deleteTail()
{
	if (tail == NULL) return;
	size--;
	if (head == tail)
	{
		delete head;
		delete tail;
		head = NULL;
		tail = NULL;
	}
	Node* temp = tail->prev;
	temp->next = NULL;
	delete tail;
	tail = temp;
}
//usuwa element listy na indexie
void DoubleLinkedList::deleteAt(int index)
{
	if (index < 0)
	{
		return;
	}
	if (index >= size)
	{
		deleteTail();
		return;
	}
	if (index == 0)
	{
		deleteHead();
		return;
	}
	else if (size - index> index)
	{
		Node * temp = head;
		for (int i = 0; i <= index; i++)
		{
			temp = temp->next;
		}
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
		size--;
		return;
	}
	else
	{
		Node * temp = tail;
		for (int i = size-1; i > index; i--)
		{
			temp = temp->prev;
		}
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
		size--;
		return;
	}
}
//zwraca wartoœæ pierwszego elementu listy
int DoubleLinkedList::getFront()
{
	if (head != NULL)
		return head->data;
	else
		std::cout << "error";
	return -1;
}
//zwraca wartoœæ ostatniego elementu listy
int DoubleLinkedList::getBack()
{
	if (tail != NULL)
		return tail->data;
	else
		std::cout << " error";
	return -1;
}
//zwraca wartoœæ element listy na indexie
int DoubleLinkedList::getElement(int index)
{
	if (index >= size || index < 0)
	{
		return NULL;
	}
	else
	{
		if (size - index > index)
		{
			Node* temp = head;
			for (int i = 1; i <= index; i++)
			{
				temp = temp->next;
			}
			return temp->data;
		}
		else
		{
			Node* temp = tail;
			for (int i = size - 2; i > index; i++)
			{
				temp = temp->prev;
			}
			return temp->data;
		}
	}
}
//wyœwietla listê
void DoubleLinkedList::display()
{
	if (head != NULL)
	{
		std::cout << std::endl;
		Node* temp = head;
		while (temp != NULL)
		{
			std::cout << temp->data << " ";
			temp = temp->next;
		}
		std::cout << std::endl;
	}
}
//zwraca rozmier listy
int DoubleLinkedList::getSize()
{
	return size;
}
//niszcz listê
void DoubleLinkedList::deleteAll()
{
	if (head != NULL)
	{
		Node* temp = head;
		Node* temp2 = head;
		do
		{
			temp2 = temp->next;
			delete temp;
			temp = temp2->next;
		} while (temp != tail);
		head = NULL;
		tail = NULL;
		size = 0;
	}
}
//zwraca element max listy
int DoubleLinkedList::findMax()
{
	if (head != NULL)
	{
		int temp = head->data;
		Node* tmpNode = head;
		do
		{
			tmpNode = tmpNode->next;
			if (tmpNode->data > temp)
				temp = tmpNode->data;
		} while (tmpNode->next!=NULL);
		return temp;
	}
	else
	{
		std::cout << "brak elementów listy" << std::endl;
		return NULL;
	}
}

void DoubleLinkedList::findVal(int val)
{
	if (head != NULL)
	{
		Node* temp = head;
		int i = 0;
		while (temp != NULL)
		{
			if (val == temp->data)
			{
				std::cout << "znaleziono element na pozycji: " << i << std::endl;
				return;
			}
			temp = temp->next;
			i++;
		}
		std::cout << " brak elementu" << std::endl;
		return;
	}
	else
	{
		std::cout << " brak elementu" << std::endl;
	}
}

//destruktor listy dwukierunkowej
DoubleLinkedList::~DoubleLinkedList()
{
	if (head != NULL)
	{
		Node *temp = head;
		Node * t2 = temp;
		while (temp->next != NULL)
		{
			temp = temp->next;
			delete t2;
			t2 = temp;
		}
	}
	head = NULL;
	size = 0;
	tail = NULL;
}
