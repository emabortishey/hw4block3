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

	//конструктор по умолчанию в каждом из классов запрашивает у пользователя данные для начального заполнения самостоятельно
	// так как при передаче нулей при присваивании размера массиву через стрлен он не может считать ноль, а если сделать
	// получаемые в конструкторе переменные константами и передавать строку "none" или типо того, то невозможно будет присвоить
	// их переменным-динамическим массивам, так как не получится передать в динамический параметр константу (вродекак)

	building()
	{
		cout << "\nВведите количество квартир в доме: ";
		cin >> amount;
		cin.ignore();
		cout << "\nВведите номер дома: ";
		cin >> number;
		cin.ignore();
		block = new flat[amount];
	}


	building(const flat*& obj) : building(obj, 1, 10) {} //передаём везде константную ссылку на массив, чтобы не создавалась новая переменная
	building(const flat*& obj, int numberP) : building(obj, numberP, 10) {}
	building(const flat*& obj, int numberP, int amountP) : block{ new flat[amountP]{*obj} }, number{ numberP }, amount { amountP } {}


	void set_bl(const flat*& obj) // заполнение массива в цикле
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


	flat get_bl() // тип возвращаемого значения - адрес типа флат, потому что мы возвращаем адрес на первое значение массива типа флат
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
	building* get_build_atributes()// тут возвращаем адрес самого обьекта класса
	{
		return this;
	}
	flat* get_flat_atributes(int index) // возвращаем адрес ячейки массива типа флат под указанным индексом для получения доступа к методам класса хуман
	{
		return &block[index];
	} 
	//тут мы возвращаем адрес ячейки хуман для получения доступа к методам для работы с атрибутами 
	// (я уже сама запуталась что нужно а что нет, но много 
	// методов не бывает так сказать, на всякий случай пусть будет
	human* get_hum_atributes(int index, int index2)
	{
		return block[index].get_hum_atributes(index2);
	}

	~building()
	{
		delete[] block;
	}

};