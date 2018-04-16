#include "stdafx.h"
#include "BinaryHeap.h"
#include <iostream>
#include <cmath>
#include <iomanip>

//Konstruktor
BinaryHeap::BinaryHeap()
{
	ptr = new int[0];
}
//dodaje element o wartoœci i
void BinaryHeap::push(int i)
{
	size++;
	int* temp = new int[size];
	copy(temp);
	ptr[size - 1] = i;
	heapify(size-1);
}
//naprawia kopiec w górê
void BinaryHeap::heapify(int index)
{
	if (index == 0)
		return;
	if (ptr[index] > ptr[index / 2])
	{
		int temp = ptr[index / 2];
		ptr[index / 2] = ptr[index];
		ptr[index] = temp;
	}
	heapify(index / 2);
}
//naprawia kopiec w dó³
void BinaryHeap::heapifyDown(int index)
{
	if (index*2+1<size && index*2+2<size)
	{
		if (ptr[index * 2 + 1] > ptr[index] || ptr[index * 2 + 2]>ptr[index])
		{
			if (ptr[index * 2 + 1] > ptr[index * 2 + 2])
			{
				int temp = ptr[index];
				ptr[index] = ptr[index * 2 + 1];
				ptr[index * 2 + 1] = temp;
				heapifyDown(index * 2 + 1);
			}
			else
			{
				int temp = ptr[index];
				ptr[index] = ptr[index * 2 + 2];
				ptr[index * 2 + 2] = temp;
				heapifyDown(index * 2 + 2);
			}
		}
		else return;
	}
	else if (index * 2 + 1 < size && index * 2 + 2 >= size)
	{
		if (ptr[index * 2 + 1] > ptr[index])
		{
			int temp = ptr[index];
			ptr[index] = ptr[index * 2 + 1];
			ptr[index * 2 + 1] = temp;
			return;
		}
		return;
	}
	return;

}
//usuwa korzeñ kopca
void BinaryHeap::pop()
{
	if (size != 0)
	{
		size--;
		int* temp = new int[size];
		ptr[0] = ptr[size];
		copy2(temp);
		heapifyDown(0);
	}
}
//wyœwietla kopiec
void BinaryHeap::display()
{
	if (size == 0)
	{
		std::cout << "heap is  empty" << std::endl;

		return;
	}
	int l = log2(size) + 1;
	int p = 0;
	for (int i = 0; i <= l; i++)
	{
		for (int k = 0; k < l - i; k++)
		{
			std::cout <<" ";
		}
		for (int j=0; j < pow(2, i) && p < size; j++)
		{
			//std::cout << std::setw(3);
			std::cout << " " << ptr[p];
			p++;
		}
		std::cout << std::endl;
	}
}
//zwraca max element kopca
int BinaryHeap::findMax()
{
	if (size > 0)
	{
		return ptr[0];
	}
	else std::cout << "Heap is empty" << std::endl;
	return NULL;
}
//kopiuje kopiec size
void BinaryHeap::copy(int * temp)
{
	for (int i = 0; i < size - 1; i++)
	{
		temp[i] = ptr[i];
	}
	delete[] ptr;
	ptr = temp;
}
//kopiuje kopiec size -1
void BinaryHeap::copy2(int * temp)
{
	for (int i = 0; i < size ; i++)
	{
		temp[i] = ptr[i];
	}
	delete[] ptr;
	ptr = temp;
}

void BinaryHeap::findVal(int val)
{
	if (size > 0)
	{
		for (int i = 0; i < size; i++)
		{
			if (ptr[i] == val)
			{
				std::cout << "element znaleziony na pozycji: " << i << std::endl;
				return;
			}
		}
		std::cout << "brak elementu" << std::endl;
	}
	else
	{
		std::cout << "brak elementu!" << std::endl;
	}
}

//destruktor
BinaryHeap::~BinaryHeap()
{
	delete[] ptr;
	size = NULL;
	ptr = NULL;
}
