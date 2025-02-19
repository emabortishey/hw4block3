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


	//����������� �� ��������� � ������ �� ������� ����������� � ������������ ������ ��� ���������� ���������� ��������������
    // ��� ��� ��� �������� ����� ��� ������������ ������� ������� ����� ������ �� �� ����� ������� ����, � ���� �������
	// ���������� � ������������ ���������� ����������� � ���������� ������ "none" ��� ���� ����, �� ���������� ����� ���������
	// �� ����������-������������ ��������, ��� ��� �� ��������� �������� � ������������ �������� ��������� (��������)

public:
	flat()
	{
		cout << "\n������� ���������� ����� ����������� � ��������: ";
		cin >> amount;
		cin.ignore();
		cout << "\n������� ����� ��������: ";
		cin >> number;
		cin.ignore();
		apartament = new human[amount];
	}


	flat(const human*& obj) : flat(obj, 1, 10) {} //������� ����� ����������� ������ �� ������, ����� �� ����������� ����� ����������
	flat(const human*& obj, int numberP) : flat(obj, number, 10) {}
	flat(const human*& obj, int numberP, int amountP) : apartament{ new human[amountP]{*obj} }, number{ numberP }, amount { amountP } {}


	void set_ap(const human*& obj, int index) // ���������� ������� � �����
	{ 
		apartament[index] = *obj;
	}
	void set_nu(int numberP)
	{
		number = numberP;
	}
	void set_am(int amountP)
	{
		amount = amountP;
	}


	const human* get_ap()// ��� ������������� �������� - ����� ���� �����, ������ ��� �� ���������� ����� �� ������ �������� ������� ���� �����
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
	flat* get_flat_atributes() // ��� ���������� ����� ������ ������� ������
	{
		return this;
	}
	human* get_hum_atributes(int index) //��� �� ����� � ���������� ����� �� ���������� ������ ����� ��� ��������� �������� ��� ��������� ������� � ������� ������ �����
	{
		return &apartament[index];
	}

	~flat()
	{
		delete[] apartament;
	}
}; 