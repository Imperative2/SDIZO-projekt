// SDIZO_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Array1.h"
#include "DoubleLinkedList.h"
#include "BST.h"
#include "BinaryHeap.h"
#include"RBT.h"
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <fstream>
#include <String>
#include <time.h>
#include <cmath>
#include<iomanip>


double PCFreq = 0.0;
__int64 CounterStart = 0;

int test_p = 100; //liczba określająca ilość testów
int rG = 1000; //liczba okreslacjaca zakres rand()


void startCounter()
{
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		std::cout << "QueryPerformanceFrequency failed!\n";

	PCFreq = double(li.QuadPart) / 1000.0;

	QueryPerformanceCounter(&li);
	CounterStart = li.QuadPart;
}
double getCounter()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return double(li.QuadPart - CounterStart) / PCFreq;
}

void menuArray()
{
	Array1* list = new Array1();
	while (true)
	{
		system("cls");
		std::cout << "----------------TABLICA-------------------\n" << std::endl;
		std::cout << "1. Dodaj na poczatek." << std::endl;
		std::cout << "2. Dodaj na koniec." << std::endl;
		std::cout << "3. Dodaj na pozycji." << std::endl;
		std::cout << "4. Usun element na pozycji. " << std::endl;
		std::cout << "5. Pobierz element na pozycji." << std::endl;
		std::cout << "6. Znajdz maksimum." << std::endl;
		std::cout << "7. Wyswietl tablice" << std::endl;
		std::cout << "8. Exit." << std::endl;
		std::cout << "9. Zaladuj dane z pliku." << std::endl;
		std::cout << " 10. Usun element z konca." << std::endl;
		std::cout << "11. Wyszukaj element." << std::endl;

		int a;
		std::cin >> a;
		switch (a)
		{
			case 1:
			{
				system("cls");
				std::cout << "podaj element: ";
				int b;
				std::cin >> b;
				list->addFront(b);
				break;
			}
			case 2 :
			{
				system("cls");
				std::cout << "podaj element: ";
				int b;
				std::cin >> b;
				list->addBack(b);
				break;
			}
			case 3:
			{
				system("cls");
				std::cout << "podaj index: ";
				int b;
				std::cin >> b;
				std::cout << "\n podaj wartosc: ";
				int c;
				std::cin >> c;
				list->addAtIndex(c, b);
				break;
			}
			case 4:
			{
				system("cls");
				std::cout << "podaj index to usuniecia: ";
				int b;
				std::cin >> b;
				list->destroyElement(b);
				break;
			}
			case 5:
			{
				system("cls");
				std::cout << "podaj index: ";
				int b;
				std::cin >> b;
				std::cout<<list->getElementAt(b);
				system("pause");
				break;
			}
			case 6:
			{
				system("cls");
				std::cout<<"Max: "<<list->findMax();
				system("pause");
				break;
			}
			case 7:
			{
				system("cls");
				std::cout << "\nSize: " << list->getSize() << std::endl;
				list->display();
				system("pause");
				break;
			}
			case 8:
			{
				delete list;
				return;
			}
			case 9:
			{
				std::cout << "podaj nazwe pliku ";
				std::string name;
				std::cin >> name;
				name += ".txt";
				std::ifstream file;
				file.open(name);
				if (file.is_open())
				{
					int i;
					file >> i;
					for (int j = 0; j < i; j++)
					{
						int val;
						file >> val;
						list->addBack(val);
					}
					std::cout << "done!!!"<<std::endl;
				}
				else
				{
					std::cout << "Error!!!" << std::endl;
				}

				system("pause");
				break;
			}
			case 10:
			{
				system("cls");
				list->destroyElement(list->getSize() - 1);
				break;
			}
			case 11:
			{
				system("cls");
				std::cout << "podaj element do znalezienia: ";
				int b;
				std::cin >> b;
				list->findVal(b);
				system("pause");
				break;
			}
			default:
			{
				system("cls");
				std::cout << "\t&&&  Try again!!   &&&" << std::endl;
				system("pause");
				break;
			}


		}
	}


}

void menuDoubleLinked()
{
	DoubleLinkedList* listDL = new DoubleLinkedList();
	while (true)
	{
		system("cls");
		std::cout << "----------------Lista Dwukierunkowa-------------------\n" << std::endl;
		std::cout << "1. Dodaj na poczatek." << std::endl;
		std::cout << "2. Dodaj na koniec." << std::endl;
		std::cout << "3. Usun glowe" << std::endl;
		std::cout << "4. Usun ogon " << std::endl;
		std::cout << "5. Pobierz element z poczatku" << std::endl;
		std::cout << "6. Pobierz element z konca." << std::endl;
		std::cout << "7. Pobierz element na pozycji" << std::endl;
		std::cout << "8. Znajdz Max." << std::endl;
		std::cout << "9. Wyswietl liste. " << std::endl;
		std::cout << "10. Pobierz z pliku. " << std::endl;
		std::cout << "11. Exit" << std::endl;
		std::cout << "12. Wyszukaj wartosc." << std::endl;
		std::cout << "13. Dodaj element na pozycji." << std::endl;
		std::cout << " 14. Usun element na pozycji." << std::endl;

		int a;
		std::cin >> a;
		switch (a)
		{
		case 1:
		{
			system("cls");
			std::cout << "podaj element: ";
			int b;
			std::cin >> b;
			listDL->addFront(b);
			break;
		}
		case 2:
		{
			system("cls");
			std::cout << "podaj element: ";
			int b;
			std::cin >> b;
			listDL->addBack(b);
			break;
		}
		case 3:
		{
			system("cls");
			listDL->deleteHead();
			break;
		}
		case 4:
		{
			system("cls");
			listDL->deleteTail();
			break;
		}
		case 5:
		{
			system("cls");
			std::cout << listDL->getFront();
			system("pause");
			break;
		}
		case 6:
		{
			system("cls");
			std::cout << listDL->getBack();
			system("pause");
			break;
		}
		case 7:
		{
			system("cls");
			std::cout << "podaj index: ";
			int b;
			std::cin >> b;
			std::cout << "turlaj dropsa :D ";
			std::cout << listDL->getElement(b) << std::endl;
			system("pause");
			break;
		}
		case 8:
		{
			system("cls");
			std::cout << "Max: " << listDL->findMax() << std::endl;
			system("pause");
			break;
		}
		case 9:
		{
			system("cls");
			std::cout << "Size: " << listDL->getSize() << std::endl;
			listDL->display();
			std::cout << std::endl;
			system("pause");
			break;
		}
		case 10:
		{
			std::cout << "podaj nazwe pliku ";
			std::string name;
			std::cin >> name;
			name += ".txt";
			std::ifstream file;
			file.open(name);
			if (file.is_open())
			{
				int i;
				file >> i;
				for (int j = 0; j < i; j++)
				{
					int val;
					file >> val;
					listDL->addBack(val);
				}
				std::cout << "done!!!" << std::endl;
			}
			else
			{
				std::cout << "Error!!!" << std::endl;
			}

			system("pause");
			break;
		}
		case 11:
		{
			delete listDL;
			return;
		}
		case 12:
		{
			system("cls");
			std::cout << "podaj element do znalezienia: ";
			int b;
			std::cin >> b;
			listDL->findVal(b);
			system("pause");
			break;
		}case 13:
		{
			system("cls");
			std::cout << "podaj element : ";
			int b;
			std::cin >> b;
			std::cout << " podaj pozycje: ";
			int c;
			std::cin >> c;
			listDL->addAt(c, b);
			system("pause");
			break;
		}
		case 14:
		{
			system("cls");
			std::cout << "podaj pozycje do usuniecia: ";
			int b;
			std::cin >> b;
			listDL->deleteAt(b);
			system("pause");
			break;
		}
		default:
		{
			system("cls");
			std::cout << "\t&&&  Try again!!   &&&" << std::endl;
			system("pause");
			break;
		}


		}
	}

}

void menuBinaryHeap()
{
	BinaryHeap* heap = new BinaryHeap();
	while (true)
	{
		system("cls");
		std::cout << "----------------Kopiec Binarny-------------------\n" << std::endl;
		std::cout << "1. Push." << std::endl;
		std::cout << "2. Pop." << std::endl;
		std::cout << "3. Znajdz Max." << std::endl;
		std::cout << "4. Wyswietl." << std::endl;
		std::cout << "5. Pobierz z pliku." << std::endl;
		std::cout << "6. Exit." << std::endl;
		std::cout << "7. Wyszukaj wartosc" << std::endl;
		char a;
		std::cin >> a;
		switch (a)
		{
			case'1':
			{
				system("cls");
				std::cout << "podaj element: ";
				int b;
				std::cin >> b;
				heap->push(b);
				break;
			}
			case '2':
			{
				system("cls");
				heap->pop();
				break;
			}
			case'3':
			{
				system("cls");
				std::cout << "Max: " << heap->findMax() << std::endl;
				system("pause");
				break;
			}
			case'4':
			{
				system("cls");
				heap->display();
				system("pause");
				break;

			}
			case '5':
			{
				std::cout << "podaj nazwe pliku ";
				std::string name;
				std::cin >> name;
				name += ".txt";
				std::ifstream file;
				file.open(name);
				if (file.is_open())
				{
					int i;
					file >> i;
					for (int j = 0; j < i; j++)
					{
						int val;
						file >> val;
						heap->push(val);
					}
					std::cout << "done!!!" << std::endl;;
				}
				else
				{
					std::cout << "Error!!!" << std::endl;
				}

				system("pause");
				break;
			}
			case '6':
			{
				delete heap;
				return;
			}
			case '7':
			{
				system("cls");
				std::cout << "podaj element do znalezienia: ";
				int b;
				std::cin >> b;
				heap->findVal(b);
				system("pause");
				break;
			}
			default:
			{
				system("cls");
				std::cout << "\t&&&  Try again!!   &&&" << std::endl;
				system("pause");
				break;
			}
		}
	}
}

void menuBST()
{
	BST* bst = new BST();
	while (true)
	{
		system("cls");
		std::cout << "----------------Drzewo BST-------------------\n" << std::endl;
		std::cout << "1. Dodaj" << std::endl;
		std::cout << "2. Znajd max" << std::endl;
		std::cout << "3. Usun wartosc" << std::endl;
		std::cout << "4. Wyswietl " << std::endl;
		std::cout << "5. Pobierz z pliku" << std::endl;
		std::cout << "6. Exit " << std::endl;
		std::cout << "7. Wyszukaj wartosc" << std::endl;

		char a;
		std::cin >> a;
		switch (a)
		{
		case '1':
		{
			system("cls");
			std::cout << "podaj element: ";
			int b;
			std::cin >> b;
			bst->add(b);
			break;
		}
		case '2':
		{
			system("cls");
			std::cout << "Max: " << bst->findMax() << std::endl;
			system("pause");
			break;
		}
		case '3':
		{
			system("cls");
			std::cout << " podaj wartosc: ";
			int b;
			std::cin >> b;
			bst->deleteAtIndex(b);
			break;
		}
		case '4':
		{
			system("cls");
			bst->display();
			system("pause");
			break;
		}
		case '5':
		{
			std::cout << "podaj nazwe pliku ";
			std::string name;
			std::cin >> name;
			name += ".txt";
			std::ifstream file;
			file.open(name);
			if (file.is_open())
			{
				int i;
				file >> i;
				for (int j = 0; j < i; j++)
				{
					int val;
					file >> val;
					bst->add(val);
				}
				std::cout << "done!!!" << std::endl;
			}
			else
			{
				std::cout << "Error!!!" << std::endl;
			}

			system("pause");
			break;
		}
		case '6':
		{
			delete bst;
			return;
		}
		case '7':
		{
			system("cls");
			std::cout << "podaj element do znalezienia: ";
			int b;
			std::cin >> b;
			bst->findVal(b);
			system("pause");
			break;
		}
		

		default:
		{
			system("cls");
			std::cout << "\t&&&  Try again!!   &&&" << std::endl;
			system("pause");
			break;
		}


		}
	}


}
void menuRBT()
{
	RBT* rbt = new RBT();
	while (true)
	{
		system("cls");
		std::cout << "----------------Drzewo RBT" << std::endl;
		std::cout << "1. Dodaj" << std::endl;
		std::cout << "2. Znajd max" << std::endl;
		std::cout << "3. Usun wartosc" << std::endl;
		std::cout << "4. Wyswietl " << std::endl;
		std::cout << "5. Pobierz z pliku" << std::endl;
		std::cout << "6. Exit " << std::endl;
		std::cout << "7. Wyszukaj wartosc." << std::endl;

		char a;
		std::cin >> a;
		switch (a)
		{
		case '1':
		{
			system("cls");
			std::cout << "podaj element: ";
			int b;
			std::cin >> b;
			rbt->add(b);
			break;
		}
		case '2':
		{
			system("cls");
			std::cout << "Max: " << rbt->findMax() << std::endl;
			system("pause");
			break;
		}
		case '3':
		{
			system("cls");
			std::cout << " podaj wartosc: ";
			int b;
			std::cin >> b;
			rbt->deleteAt(b);
			break;
		}
		case '4':
		{
			system("cls");
			rbt->display();
			system("pause");
			break;
		}
		case '5':
		{
			std::cout << "podaj nazwe pliku ";
			std::string name;
			std::cin >> name;
			name += ".txt";
			std::ifstream file;
			file.open(name);
			if (file.is_open())
			{
				int i;
				file >> i;
				for (int j = 0; j < i; j++)
				{
					int val;
					file >> val;
					rbt->add(val);
				}
				std::cout << "done!!!" << std::endl;
			}
			else
			{
				std::cout << "Error!!!" << std::endl;
			}

			system("pause");
			break;
		}
		case '6':
		{
			delete rbt;
			return;
		}
		case '7':
		{
			system("cls");
			std::cout << "podaj element do znalezienia: ";
			int b;
			std::cin >> b;
			rbt->findVal(b);
			system("pause");
			break;
		}


		default:
		{
			system("cls");
			std::cout << "\t&&&  Try again!!   &&&" << std::endl;
			system("pause");
			break;
		}


		}
	}


}

void testMenuArray()
{
	Array1* list = new Array1();

	while (true)
	{
		system("cls");
		std::cout << "----------------TEST MODE TABLICA-------------------\n" << std::endl;
		std::cout << "1. Dodaj na poczatek." << std::endl;
		std::cout << "2. Dodaj na koniec." << std::endl;
		std::cout << "3. Dodaj na pozycji." << std::endl;
		std::cout << "4. Usun element na pozycji poczatek. " << std::endl;
		std::cout << "5. Usun element na pozycji koniec" << std::endl;
		std::cout << "6. Usun element na pozycji rand" << std::endl;
		std::cout << "7. Exit." << std::endl;
		std::cout << "8. Wyszukaj wartosc" << std::endl;

		char a;
		std::cin >> a;
		switch (a)
		{
		case '1':
		{
			std::ofstream results;
			system("cls");
			std::cout << "Rozmiar testu: ";
			std::string fname;
			int c;
			std::cin >> c;
			fname = "rs-Array-AddP" + std::to_string(c);
			fname += ".txt";
			std::cout << fname << std::endl;
			system("pause");
			std::cout << "starting" << std::endl;
			results.open(fname);
			for (int j = 0; j < test_p; j++)
			{
				Array1* list2 = new Array1();
				for (int i = 0; i < c; i++)
				{
					list2->addFront(std::rand()%rG);
				}
				Sleep(5);
				int p = rand()%rG;
				startCounter();
				list2->addFront(p);
				results << getCounter() << std::endl;
				delete list2;
				std::cout << "test nr: " << j << " done" << std::endl;
			}
			break;
		}
		case '2':
		{
			std::ofstream results;
			system("cls");
			std::cout << "Rozmiar testu: ";
			std::string fname;
			int c;
			std::cin >> c;
			fname = "rs-Array-AddB" + std::to_string(c);
			fname += ".txt";
			std::cout << fname << std::endl;
			system("pause");
			std::cout << "starting" << std::endl;
			results.open(fname);
			for (int j = 0; j < test_p; j++)
			{
				Array1* list2 = new Array1();
				for (int i = 0; i < c; i++)
				{
					list2->addFront(std::rand()%rG);
				}
				Sleep(5);
				int p = rand()%rG;
				startCounter();
				list2->addBack(p);
				results << getCounter() << std::endl;
				delete list2;
				std::cout << "test nr: " << j << " done" << std::endl;
			}
			break;
		}
		case '3':
		{
			std::ofstream results;
			system("cls");
			std::cout << "Rozmiar testu: ";
			std::string fname;
			int c;
			std::cin >> c;
			fname = "rs-Array-AddRAND" + std::to_string(c);
			fname += ".txt";
			std::cout << fname << std::endl;
			system("pause");
			std::cout << "starting" << std::endl;
			results.open(fname);
			for (int j = 0; j < test_p; j++)
			{
				Array1* list2 = new Array1();
				for (int i = 0; i < c; i++)
				{
					list2->addFront(std::rand()%rG);
				}
				Sleep(5);
				int p = rand()%(list->getSize()-3)+2;
				startCounter();
				list2->addAtIndex(p,p);
				results << getCounter() << std::endl;
				delete list2;
				std::cout << "test nr: " << j << " done" << std::endl;
			}
			break;
		}
		case '4':
		{
			std::ofstream results;
			system("cls");
			std::cout << "Rozmiar testu: ";
			std::string fname;
			int c;
			std::cin >> c;
			fname = "rs-Array-DelP" + std::to_string(c);
			fname += ".txt";
			std::cout << fname << std::endl;
			system("pause");
			std::cout << "starting" << std::endl;
			results.open(fname);
			for (int j = 0; j < test_p; j++)
			{
				Array1* list2 = new Array1();
				for (int i = 0; i < c; i++)
				{
					list2->addFront(std::rand()%rG);
				}
				Sleep(5);
				int p = rand()%rG;
				startCounter();
				list2->destroyElement(0);
				results << getCounter() << std::endl;
				delete list2;
				std::cout << "test nr: " << j << " done" << std::endl;
			}
			break;
		}
		case '5':
		{
			std::ofstream results;
			system("cls");
			std::cout << "Rozmiar testu: ";
			std::string fname;
			int c;
			std::cin >> c;
			fname = "rs-Array-DelB" + std::to_string(c);
			fname += ".txt";
			std::cout << fname << std::endl;
			system("pause");
			std::cout << "starting" << std::endl;
			results.open(fname);
			for (int j = 0; j < test_p; j++)
			{
				Array1* list2 = new Array1();
				for (int i = 0; i < c; i++)
				{
					list2->addFront(std::rand()%rG);
				}
				Sleep(5);
				int p = list2->getSize() - 1;
				startCounter();
				list2->destroyElement(p);
				results << getCounter() << std::endl;
				delete list2;
				std::cout << "test nr: " << j << " done" << std::endl;
			}
			break;
		}
		case '6':
		{
			std::ofstream results;
			system("cls");
			std::cout << "Rozmiar testu: ";
			std::string fname;
			int c;
			std::cin >> c;
			fname = "rs-Array-DelRAND" + std::to_string(c);
			fname += ".txt";
			std::cout << fname << std::endl;
			system("pause");
			std::cout << "starting" << std::endl;
			results.open(fname);
			for (int j = 0; j < test_p; j++)
			{
				Array1* list2 = new Array1();
				for (int i = 0; i < c; i++)
				{
					list2->addFront(std::rand()%rG);
				}
				Sleep(5);
				int p = rand() % (list->getSize() - 3) + 2;
				startCounter();
				list2->destroyElement(p);
				results << getCounter() << std::endl;
				delete list2;
				std::cout << "test nr: " << j << " done" << std::endl;

			}
			break;
		}

		case '7':
		{
			return;
		}

		case '8':
		{
			std::ofstream results;
			system("cls");
			std::cout << "Rozmiar testu: ";
			std::string fname;
			int c;
			std::cin >> c;
			fname = "rs-Array-FIND" + std::to_string(c);
			fname += ".txt";
			std::cout << fname << std::endl;
			system("pause");
			std::cout << "starting" << std::endl;
			results.open(fname);
			for (int j = 0; j < test_p; j++)
			{
				Array1* list2 = new Array1();
				for (int i = 0; i < c; i++)
				{
					list2->addFront(std::rand() % (rG*1000));
				}
				Sleep(5);
				int p = rand() % rG;
				startCounter();
				list2->findVal(p);
				results << getCounter() << std::endl;
				delete list2;
				std::cout << "test nr: " << j << " done" << std::endl;
			}
			break;
		}
		
		default:
		{
			system("cls");
			std::cout << "\t&&&  Try again!!   &&&" << std::endl;
			system("pause");
			break;
		}


		}
	}


}

void testMenuDoubleLinked()
{

	while (true)
	{
		system("cls");
		std::cout << "----------------TEST Lista Dwukierunkowa-------------------\n" << std::endl;
		std::cout << "1. Dodaj na poczatek." << std::endl;
		std::cout << "2. Dodaj na koniec." << std::endl;
		std::cout << "3. Dodaj na RAND" << std::endl;
		std::cout << "4. Usun glowe " << std::endl;
		std::cout << "5. Usun ogon" << std::endl;
		std::cout << "6. Usun na RAND" << std::endl;
		std::cout << "7. Exit" << std::endl;
		std::cout << "8. Wyszukaj wartosc." << std::endl;

		int a;
		std::cin >> a;
		switch (a)
		{
		case 1:
		{
			std::ofstream results;
			system("cls");
			std::cout << "Rozmiar testu: ";
			std::string fname;
			int c;
			std::cin >> c;
			fname = "rs-DoubleLL-AddP" + std::to_string(c);
			fname += ".txt";
			std::cout << fname << std::endl;
			system("pause");
			std::cout << "starting" << std::endl;
			results.open(fname);
			for (int j = 0; j < test_p; j++)
			{
				DoubleLinkedList* list = new DoubleLinkedList();
				for (int i = 0; i < c; i++)
				{
					list->addFront(rand()%rG);
				}
				Sleep(5);
				int p = rand()%rG;
				startCounter();
				list->addFront(p);
				results << getCounter() << std::endl;
				delete list;
				std::cout << "test nr: " << j << " done" << std::endl;
			}
			break;
		}
		case 2:
		{
			std::ofstream results;
			system("cls");
			std::cout << "Rozmiar testu: ";
			std::string fname;
			int c;
			std::cin >> c;
			fname = "rs-DoubleLL-AddB" + std::to_string(c);
			fname += ".txt";
			std::cout << fname << std::endl;
			system("pause");
			std::cout << "starting" << std::endl;
			results.open(fname);
			for (int j = 0; j < test_p; j++)
			{
				DoubleLinkedList* list = new DoubleLinkedList();
				for (int i = 0; i < c; i++)
				{
					list->addFront(rand()%rG);
				}
				Sleep(5);
				int p = rand()%rG;
				startCounter();
				list->addBack(p);
				results << getCounter() << std::endl;
				delete list;
				std::cout << "test nr: " << j << " done" << std::endl;
			}
			break;
		}
		case 3:
		{
			std::ofstream results;
			system("cls");
			std::cout << "Rozmiar testu: ";
			std::string fname;
			int c;
			std::cin >> c;
			fname = "rs-DoubleLL-AddRAND" + std::to_string(c);
			fname += ".txt";
			std::cout << fname << std::endl;
			system("pause");
			std::cout << "starting" << std::endl;
			results.open(fname);
			for (int j = 0; j < test_p; j++)
			{
				DoubleLinkedList* list = new DoubleLinkedList();
				for (int i = 0; i < c; i++)
				{
					list->addFront(rand()%rG);
				}
				Sleep(5);
				int p = rand() % (list->getSize() - 2) + 1;
				int c = rand()%rG;
				startCounter();
				list->addAt(p,c);
				results << getCounter() << std::endl;
				delete list;
				std::cout << "test nr: " << j << " done" << std::endl;
			}
			break;
		}
		case 4:
		{
			std::ofstream results;
			system("cls");
			std::cout << "Rozmiar testu: ";
			std::string fname;
			int c;
			std::cin >> c;
			fname = "rs-DoubleLL-DelP" + std::to_string(c);
			fname += ".txt";
			std::cout << fname << std::endl;
			system("pause");
			std::cout << "starting" << std::endl;
			results.open(fname);
			for (int j = 0; j < test_p; j++)
			{
				DoubleLinkedList* list = new DoubleLinkedList();
				for (int i = 0; i < c; i++)
				{
					list->addFront(rand()%rG);
				}
				Sleep(5);
				int p = rand();
				startCounter();
				list->deleteHead();
				results << getCounter() << std::endl;
				delete list;
				std::cout << "test nr: " << j << " done" << std::endl;
			}
			break;
		}
		case 5:
		{
			std::ofstream results;
			system("cls");
			std::cout << "Rozmiar testu: ";
			std::string fname;
			int c;
			std::cin >> c;
			fname = "rs-DoubleLL_DelB" + std::to_string(c);
			fname += ".txt";
			std::cout << fname << std::endl;
			system("pause");
			std::cout << "starting" << std::endl;
			results.open(fname);
			for (int j = 0; j < test_p; j++)
			{
				DoubleLinkedList* list = new DoubleLinkedList();
				for (int i = 0; i < c; i++)
				{
					list->addFront(rand()%rG);
				}
				Sleep(5);
				int p = rand();
				startCounter();
				list->deleteTail();
				results << getCounter() << std::endl;
				delete list;
				std::cout << "test nr: " << j << " done" << std::endl;
			}
			break;
		}
		case 6:
		{
			std::ofstream results;
			system("cls");
			std::cout << "Rozmiar testu: ";
			std::string fname;
			int c;
			std::cin >> c;
			fname = "rs-DoubleLL-DelRAND" + std::to_string(c);
			fname += ".txt";
			std::cout << fname << std::endl;
			system("pause");
			std::cout << "starting" << std::endl;
			results.open(fname);
			for (int j = 0; j < test_p; j++)
			{
				DoubleLinkedList* list = new DoubleLinkedList();
				for (int i = 0; i < c; i++)
				{
					list->addFront(rand()%rG);
				}
				Sleep(5);
				int p = rand() % (list->getSize() - 3) + 2;
				startCounter();
				list->deleteAt(p);
				results << getCounter() << std::endl;
				delete list;
				std::cout << "test nr: " << j << " done" << std::endl;
			}
			break;
		}
		case 7:
		{
			return;
		}

		case 8:
		{
			std::ofstream results;
			system("cls");
			std::cout << "Rozmiar testu: ";
			std::string fname;
			int c;
			std::cin >> c;
			fname = "rs-DoubleLL-FIND" + std::to_string(c);
			fname += ".txt";
			std::cout << fname << std::endl;
			system("pause");
			std::cout << "starting" << std::endl;
			results.open(fname);
			for (int j = 0; j < test_p; j++)
			{
				DoubleLinkedList* list = new DoubleLinkedList();
				for (int i = 0; i < c; i++)
				{
					list->addFront(rand() % rG);
				}
				Sleep(5);
				int p = rand() % (rG*1000);
				startCounter();
				list->findVal(p);
				results << getCounter() << std::endl;
				delete list;
				std::cout << "test nr: " << j << " done" << std::endl;
			}
			break;
		}
		default:
		{
			system("cls");
			std::cout << "\t&&&  Try again!!   &&&" << std::endl;
			system("pause");
			break;
		}


		}
	}
}

void testMenuBinaryHeap()
{
	while (true)
	{
		system("cls");
		std::cout << "----------------Kopiec Binarny-------------------\n" << std::endl;
		std::cout << "1. Push." << std::endl;
		std::cout << "2. Pop." << std::endl;
		std::cout << "3. Exit." << std::endl;
		std::cout << "4. Wyszukaj wartosc." << std::endl;
		char a;
		std::cin >> a;
		switch (a)
		{
		case'1':
		{
			std::ofstream results;
			system("cls");
			std::cout << "Rozmiar testu: ";
			std::string fname;
			int c;
			std::cin >> c;
			fname = "rs-Heap-PUSH" + std::to_string(c);
			fname += ".txt";
			std::cout << fname << std::endl;
			system("pause");
			std::cout << "starting" << std::endl;
			results.open(fname);
			for (int j = 0; j < test_p; j++)
			{
				BinaryHeap* heap = new BinaryHeap();
				for (int i = 0; i < c; i++)
				{
					heap->push(std::rand()%rG);
				}
				Sleep(5);
				int p = rand()%rG;
				startCounter();
				heap->push(p);
				results << getCounter() << std::endl;
				delete heap;
				std::cout << "test nr: " << j << " done" << std::endl;
			}
			break;
		}
		case '2':
		{
			std::ofstream results;
			system("cls");
			std::cout << "Rozmiar testu: ";
			std::string fname;
			int c;
			std::cin >> c;
			fname = "rs-Heap-POP" + std::to_string(c);
			fname += ".txt";
			std::cout << fname << std::endl;
			system("pause");
			std::cout << "starting" << std::endl;
			results.open(fname);
			for (int j = 0; j < test_p; j++)
			{
				BinaryHeap* heap = new BinaryHeap();
				for (int i = 0; i < c; i++)
				{
					heap->push(std::rand()%rG);
				}
				Sleep(5);
				int p = rand();
				startCounter();
				heap->pop();
				results << getCounter() << std::endl;
				delete heap;
				std::cout << "test nr: " << j << " done" << std::endl;
			}
			break;
		}

		case '3':
		{
			return;
		}
		case'4':
		{
			std::ofstream results;
			system("cls");
			std::cout << "Rozmiar testu: ";
			std::string fname;
			int c;
			std::cin >> c;
			fname = "rs-Heap-FIND" + std::to_string(c);
			fname += ".txt";
			std::cout << fname << std::endl;
			system("pause");
			std::cout << "starting" << std::endl;
			results.open(fname);
			for (int j = 0; j < test_p; j++)
			{
				BinaryHeap* heap = new BinaryHeap();
				for (int i = 0; i < c; i++)
				{
					heap->push(std::rand() % rG);
				}
				Sleep(5);
				int p = rand() % (rG*1000);
				startCounter();
				heap->findVal(p);
				results << getCounter() << std::endl;
				delete heap;
				std::cout << "test nr: " << j << " done" << std::endl;
			}
			break;
		}
		default:
		{
			system("cls");
			std::cout << "\t&&&  Try again!!   &&&" << std::endl;
			system("pause");
			break;
		}
		}
	}
}

void testMenuBST()
{
	while (true)
	{
		system("cls");
		std::cout << "----------------TEST Drzewo BST-------------------\n" << std::endl;
		std::cout << "1. Dodaj" << std::endl;
		std::cout << "2. Usun" << std::endl;
		std::cout << "3. Exit " << std::endl;
		std::cout << "4. Wyszukaj wartosc" << std::endl;

		char a;
		std::cin >> a;
		switch (a)
		{
		case '1':
		{
			std::ofstream results;
			system("cls");
			std::cout << "Rozmiar testu: ";
			std::string fname;
			int c;
			std::cin >> c;
			fname = "rs-BST-Add" + std::to_string(c);
			fname += ".txt";
			std::cout << fname << std::endl;
			system("pause");
			std::cout << "starting" << std::endl;
			results.open(fname);
			for (int j = 0; j < test_p; j++)
			{
				BST* bst = new BST();
				for (int i = 0; i < c; i++)
				{
					bst->add(std::rand() % (rG * 10000));
				}
				Sleep(5);
				int p = rand() % (rG * 10000);
				startCounter();
				bst->add(p);
				results << getCounter() << std::endl;
				delete bst;
				std::cout << "test nr: " << j << " done" << std::endl;
			}
			break;
		}
		case '2':
		{
			std::ofstream results;
			system("cls");
			std::cout << "Rozmiar testu: ";
			std::string fname;
			int c;
			std::cin >> c;
			fname = "rs-BST-DELL" + std::to_string(c);
			fname += ".txt";
			std::cout << fname << std::endl;
			system("pause");
			std::cout << "starting" << std::endl;
			results.open(fname);
			for (int j = 0; j < test_p; j++)
			{
				BST* bst = new BST();
				for (int i = 0; i < c; i++)
				{
					bst->add(std::rand() % (rG * 10000));
				}
				Sleep(5);
				int p = bst->getRoot();
				startCounter();
				bst->deleteAtIndex(p);
				results << getCounter() << std::endl;
				delete bst;
				std::cout << "test nr: " << j << " done" << std::endl;
				
			}
			break;
		}
		case '3':
		{
			return;
		}

		case '4':
		{
			std::ofstream results;
			system("cls");
			std::cout << "Rozmiar testu: ";
			std::string fname;
			int c;
			std::cin >> c;
			fname = "rs-BST-FIND" + std::to_string(c);
			fname += ".txt";
			std::cout << fname << std::endl;
			system("pause");
			std::cout << "starting" << std::endl;
			results.open(fname);
			for (int j = 0; j < test_p; j++)
			{
				BST* bst = new BST();
				for (int i = 0; i < c; i++)
				{
					bst->add(std::rand() % (rG * 10000));
				}
				Sleep(5);
				int p = rand() % (rG * 10000000);
				startCounter();
				bst->findVal(p);
				results << getCounter() << std::endl;
				delete bst;
				std::cout << "test nr: " << j << " done" << std::endl;
			}
			break;
		}

		default:
		{
			system("cls");
			std::cout << "\t&&&  Try again!!   &&&" << std::endl;
			system("pause");
			break;
		}

		}
	}


}

void testMenuRBT()
{
	while (true)
	{
		system("cls");
		std::cout << "----------------TEST Drzewo RBT-------------------\n" << std::endl;
		std::cout << "1. Dodaj" << std::endl;
		std::cout << "2. Usun" << std::endl;
		std::cout << "3. Exit " << std::endl;
		std::cout << "4. Wyszukaj wartosc" << std::endl;

		char a;
		std::cin >> a;
		switch (a)
		{
		case '1':
		{
			std::ofstream results;
			system("cls");
			std::cout << "Rozmiar testu: ";
			std::string fname;
			int c;
			std::cin >> c;
			fname = "rs-RBT-Add" + std::to_string(c);
			fname += ".txt";
			std::cout << fname << std::endl;
			system("pause");
			std::cout << "starting" << std::endl;
			results.open(fname);
			for (int j = 0; j < test_p; j++)
			{
				RBT* rbt = new RBT();
				for (int i = 0; i < c; i++)
				{
					rbt->add(std::rand()%(rG*10000));
				}
				Sleep(5);
				int p = rand() % (rG * 10000);
				startCounter();
				rbt->add(p);
				results << getCounter() << std::endl;
				delete rbt;
				std::cout << "test nr: " << j << " done" << std::endl;
			}
			break;
		}
		case '2':
		{
			std::ofstream results;
			system("cls");
			std::cout << "Rozmiar testu: ";
			std::string fname;
			int c;
			std::cin >> c;
			fname = "rs-RBT-DELL" + std::to_string(c);
			fname += ".txt";
			std::cout << fname << std::endl;
			system("pause");
			std::cout << "starting" << std::endl;
			results.open(fname);
			for (int j = 0; j < test_p; j++)
			{
				RBT* rbt = new RBT();
				for (int i = 0; i < c; i++)
				{
					rbt->add(std::rand() % (rG * 10000));
				}
				Sleep(5);
				int p = rbt->getRoot();
				startCounter();
				rbt->deleteAt(p);
				results << getCounter() << std::endl;
				delete rbt;
				std::cout << "test nr: " << j << " done" << std::endl;

			}
			break;
		}
		case '3':
		{
			return;
		}

		case '4':
		{
			std::ofstream results;
			system("cls");
			std::cout << "Rozmiar testu: ";
			std::string fname;
			int c;
			std::cin >> c;
			fname = "rs-RBT-FIND" + std::to_string(c);
			fname += ".txt";
			std::cout << fname << std::endl;
			system("pause");
			std::cout << "starting" << std::endl;
			results.open(fname);
			for (int j = 0; j < test_p; j++)
			{
				RBT* rbt = new RBT();
				for (int i = 0; i < c; i++)
				{
					rbt->add(std::rand() % (rG * 10000));
				}
				Sleep(5);
				int p = rand() % (rG * 10000000);
				startCounter();
				rbt->findVal(p);
				results << getCounter() << std::endl;
				delete rbt;
				std::cout << "test nr: " << j << " done" << std::endl;
			}
			break;
		}

		default:
		{
			system("cls");
			std::cout << "\t&&&  Try again!!   &&&" << std::endl;
			system("pause");
			break;
		}

		}
	}


}

int main()
{
	srand(time(NULL));

	

	while (true)
	{
		system("cls");
		std::cout << "----------------MAIN MENU-------------------\n" << std::endl;
		std::cout << "1. Tablica." << std::endl;
		std::cout << "2. List dwukierunkowa." << std::endl;
		std::cout << "3. Kopiec Binarny. " << std::endl;
		std::cout << "4. Drzewo BST." << std::endl;
		std::cout << "5. Drzewo czerwono-czarne." << std::endl;
		std::cout << "6.Exit." << std::endl;
		std::cout << "7.TEST MODE" << std::endl;


		char a;
		std::cin >> a;
		switch (a)
		{
			case '1':
			{
				menuArray();
				break;
			}
			case '2':
			{
				menuDoubleLinked();
				break;
			}
			case '3':
			{
				menuBinaryHeap();
				break;
			}
			case '4':
			{
				menuBST();
				break;
			}
			case '5':
			{
				menuRBT();
				break;
			}
			case '6':
			{
				return 0;
			}
			case '7':
			{
				bool flag = false;
				while (true&&flag==false)
				{

					system("cls");
					std::cout << "----------------TEST MODE-------------------\n" << std::endl;
					std::cout << "1. Tablica." << std::endl;
					std::cout << "2. List dwukierunkowa." << std::endl;
					std::cout << "3. Kopiec Binarny. " << std::endl;
					std::cout << "4. Drzewo BST." << std::endl;
					std::cout << "5. Drzewo czerwono-czarne." << std::endl;
					std::cout << "6.Exit." << std::endl;
					std::cout << "7.NORMAL MODE" << std::endl;
					char b;
					std::cin >> b;
					switch(b)
					{
						case '1':
						{
							testMenuArray();
							break;
						}
						case '2':
						{
							testMenuDoubleLinked();
							break;
						}
						case '3':
						{
							testMenuBinaryHeap();
							break;
						}
						case '4':
						{
							testMenuBST();
							break;
						}
						case '5':
						{
							testMenuRBT();
							break;
						}
						case '6':
						{
							return 0;
						}
						case '7':
						{
							flag = true;
							break;
						}
						default:
						{
							system("cls");
							std::cout << "\t&&&  Try again!!   &&&" << std::endl;
							system("pause");
							break;
						}
					}
				}
			}
			default:
			{
				system("cls");
				std::cout << "\t&&&  Try again!!   &&&" << std::endl;
				system("pause");
					break;
			}
		}
	}
    return 0;
}

