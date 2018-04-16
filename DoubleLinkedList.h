#pragma once

class DoubleLinkedList
{

private: 
	struct Node
	{
		int data;
		Node* next=NULL;
		Node* prev=NULL;
	};

	Node* head = NULL;
	Node* tail = NULL;
	int size = 0;



public:

	DoubleLinkedList();
	void addFront(int element);
	void addBack(int element);
	void addAt(int index, int value);
	void deleteHead();
	void deleteTail();
	void deleteAt(int index);
	int getFront();
	int getBack();
	int getElement(int index);
	void display();
	int getSize();
	void deleteAll();
	int findMax();
	void findVal(int val);
	~DoubleLinkedList();
};

