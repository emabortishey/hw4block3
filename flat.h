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


	//конструктор по умолчанию в каждом из классов запрашивает у пользователя данные для начального заполнения самостоятельно
    // так как при передаче нулей при присваивании размера массиву через стрлен он не может считать ноль, а если сделать
	// получаемые в конструкторе переменные константами и передавать строку "none" или типо того, то невозможно будет присвоить
	// их переменным-динамическим массивам, так как не получится передать в динамический параметр константу (вродекак)

public:
	flat()
	{
		cout << "\nВведите количество людей проживающих в квартире: ";
		cin >> amount;
		cin.ignore();
		cout << "\nВведите номер квартиры: ";
		cin >> number;
		cin.ignore();
		apartament = new human[amount];
	}


	flat(const human*& obj) : flat(obj, 1, 10) {} //передаём везде константную ссылку на массив, чтобы не создавалась новая переменная
	flat(const human*& obj, int numberP) : flat(obj, number, 10) {}
	flat(const human*& obj, int numberP, int amountP) : apartament{ new human[amountP]{*obj} }, number{ numberP }, amount { amountP } {}


	void set_ap(const human*& obj, int index) // заполнение массива в цикле
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


	const human* get_ap()// тип возвращаемого значения - адрес типа хуман, потому что мы возвращаем адрес на первое значение массива типа хуман
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
	flat* get_flat_atributes() // тут возвращаем адрес самого обьекта класса
	{
		return this;
	}
	human* get_hum_atributes(int index) //тут мы берем и возвращаем адрес на переменную класса хуман под указанным индексом для получения доступа к методам класса хуман
	{
		return &apartament[index];
	}

	~flat()
	{
		delete[] apartament;
	}
}; 