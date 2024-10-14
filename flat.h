#pragma once
#include "human.h"
#include <iostream>
using namespace std;

class flat
{
private:
	human *apartament;
	int number;
	int amount;

public:

	flat()
	{
		cout << "\n¬ведите количество людей проживающих в квартире: ";
		cin >> amount;
		cin.ignore();
		cout << "\n¬ведите номер квартиры: ";
		cin >> number;
		cin.ignore();
		apartament = new human[amount];
	}


	flat(const human*& obj) : flat(obj, 1, 10) {}
	flat(const human*& obj, int numberP) : flat(obj, number, 10) {}
	flat(const human*& obj, int numberP, int amountP) : apartament{ new human[amountP]{*obj} }, number{ numberP }, amount { amountP } {}


	void set_ap(const human*& obj)
	{ 
		for (int i = 0; i < amount; i++)
		{
			apartament[i] = obj[i];
		}
	}
	void set_nu(int numberP)
	{
		number = numberP;
	}
	void set_am(int amountP)
	{
		amount = amountP;
	}


	human* get_ap()
	{
		return apartament;
	}
	int get_nu()
	{
		return number;
	}
	int get_am()
	{
		return amount;
	}

	~flat()
	{
		delete[] apartament;
	}
}; 