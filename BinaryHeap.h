#pragma once
class BinaryHeap
{
private:
	int size = 0;;
	int *ptr = NULL;
public:
	BinaryHeap();
	void push(int i);
	void heapify(int index);
	void heapifyDown(int index);
	void pop();
	void display();
	int findMax();
	void copy(int* temp);
	void copy2(int* temp);
	void findVal(int val);

	~BinaryHeap();
};

