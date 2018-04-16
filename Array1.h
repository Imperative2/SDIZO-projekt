	#pragma once
class Array1
{
private:

	int size=0;
	int* ptr = NULL;

public:
	Array1();
	void addFront(int element);
	void addBack(int element);
	void addAtIndex(int element, int index);
	void destroyElement(int index);
	int getSize();
	int getElementAt(int index);
	void copy(int*, int index);
	void display();
	int findMax();
	void findVal(int val);
	~Array1();

};

