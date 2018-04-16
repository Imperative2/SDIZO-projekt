#include "stdafx.h"
#include "Array1.h"
#include<iostream>

//konstruktor tablicy
Array1::Array1()
{
	size = 0;
	ptr = new int[size];
}
//dodaje element na poczatek tablicy
void Array1::addFront(int element)
{
	size++;
	int* temp;
	temp = new int[size];
	copy(temp, 0);
	temp[0] = element;
	delete[] ptr;
	ptr = temp;
}
//dodaje element na koniec tablicy
void Array1::addBack(int element)
{
	size++;
	int* temp;
	temp = new int[size];
	copy(temp, size-1);
	temp[size - 1] = element;
	delete[] ptr;
	ptr = temp;
}
//dodaje element na index tablicy
void Array1::addAtIndex(int element, int index)
{
	if (index >= 0 && index < size)
	{
		size++;
		int* temp;
		temp = new int[size];
		copy(temp, index);
		temp[index] = element;
		delete[] ptr;
		ptr = temp;
	}
	else
	{
		std::cout << "wrong index, try again!" << std::endl;
		int a;
		std::cin >> a;
	}
}
//usuwa element na indexie tablicy
void Array1::destroyElement(int index)
{
	if (size > 0 && index >= 0 && index < size)
	{
		size--;
		int* temp;
		temp = new int[size];
		for (int i = 0; i < index; i++)
		{
			temp[i] = ptr[i];
		}
		for (int i = index; i < size; i++)
		{
			temp[i] = ptr[i + 1];
		}
		delete[] ptr;
		ptr = temp;
	}
	else
		std::cout << "wrong index or not enough element in array try again!" << std::endl;

}
//zwraca rozmiar tablicy
int Array1::getSize()
{
	return size;
}
//zwraca element listy na indexie
int Array1::getElementAt(int index)
{
	if (index >= 0 && index < size)
		return ptr[index];
	else
		return NULL;
}
// kopiuje elementy tablicy
void Array1::copy(int * temp, int index)
{
	for (int i = 0; i < index; i++)
	{
		temp[i] = ptr[i];
	}
	for (int i = index; i < size-1; i++)
	{
		temp[i+1] = ptr[i];
	}
}
//wyswietla tablice
void Array1::display()
{
	std::cout << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << " " << ptr[i];
	}
	std::cout << std::endl;
}
//zwraca wartoœæ max tablicy
int Array1::findMax()
{
	if (size > 1)
	{
		int temp = ptr[0];
		for (int i = 1; i < size; i++)
		{
			if (ptr[i] > temp)
				temp = ptr[i];
		}
		return temp;
	}
	else
	{
		std::cout << "brak elementów tablicy" << std::endl;
		return NULL;
	}
}
//sprawdza czy wartoœæ znajduje siê w tablicy i zwraca pozycjê pierwszego wyst¹pienia
void Array1::findVal(int val)
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

//destruktor tablicy
Array1::~Array1()
{
	delete[] ptr;
	size = 0;
	ptr = NULL;
}
