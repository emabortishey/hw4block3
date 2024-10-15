#pragma once
#include "flat.h"
#include <iostream>
using namespace std;

class building
{
	flat* block;
	int number;
	int amount;

public:

	//����������� �� ��������� � ������ �� ������� ����������� � ������������ ������ ��� ���������� ���������� ��������������
	// ��� ��� ��� �������� ����� ��� ������������ ������� ������� ����� ������ �� �� ����� ������� ����, � ���� �������
	// ���������� � ������������ ���������� ����������� � ���������� ������ "none" ��� ���� ����, �� ���������� ����� ���������
	// �� ����������-������������ ��������, ��� ��� �� ��������� �������� � ������������ �������� ��������� (��������)

	building()
	{
		cout << "\n������� ���������� ������� � ����: ";
		cin >> amount;
		cin.ignore();
		cout << "\n������� ����� ����: ";
		cin >> number;
		cin.ignore();
		block = new flat[amount];
	}


	building(const flat*& obj) : building(obj, 1, 10) {} //������� ����� ����������� ������ �� ������, ����� �� ����������� ����� ����������
	building(const flat*& obj, int numberP) : building(obj, numberP, 10) {}
	building(const flat*& obj, int numberP, int amountP) : block{ new flat[amountP]{*obj} }, number{ numberP }, amount { amountP } {}


	void set_bl(const flat*& obj) // ���������� ������� � �����
	{
		for (int i = 0; i < amount; i++)
		{
			block[i] = obj[i];
		}
	}

	void set_index(int index)
	{
		
	}

	void set_nu(int numberP)
	{
		number = numberP;
	}
	void set_am(int amountP)
	{
		amount = amountP;
	}


	flat get_bl() // ��� ������������� �������� - ����� ���� ����, ������ ��� �� ���������� ����� �� ������ �������� ������� ���� ����
	{
		return *block; 
	}
	int& get_nu()
	{
		return number;
	}
	int& get_am()
	{
		return amount;
	}
	building* get_build_atributes()// ��� ���������� ����� ������ ������� ������
	{
		return this;
	}
	flat* get_flat_atributes(int index) // ���������� ����� ������ ������� ���� ���� ��� ��������� �������� ��� ��������� ������� � ������� ������ �����
	{
		return &block[index];
	} 
	//��� �� ���������� ����� ������ ����� ��� ��������� ������� � ������� ��� ������ � ���������� 
	// (� ��� ���� ���������� ��� ����� � ��� ���, �� ����� 
	// ������� �� ������ ��� �������, �� ������ ������ ����� �����
	human* get_hum_atributes(int index, int index2)
	{
		return block[index].get_hum_atributes(index2);
	}

	~building()
	{
		delete[] block;
	}

};