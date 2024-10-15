#include <iostream>
using namespace std;

class human
{
	char* Name;
	char* Gender;
	int Age;
	char* Religion;

	//конструктор по умолчанию в каждом из классов запрашивает у пользователя данные для начального заполнения самостоятельно
	// так как при передаче нулей при присваивании размера массиву через стрлен он не может считать ноль, а если сделать
	// получаемые в конструкторе переменные константами и передавать строку "none" или типо того, то невозможно будет присвоить
	// их переменным-динамическим массивам, так как не получится передать в динамический параметр константу (вродекак)

public:
	human()
	{ 
		Name = new char[100];
		Gender = new char[100];
		Religion = new char[100];

		cout << "\nВведите имя человека: ";
		gets_s(Name, 100);
		cout << "\nВведите пол человека: ";
		gets_s(Gender, 100);
		cout << "\nВведите возраст человека: ";
		cin >> Age;
		cin.ignore();
		cout << "\nВведите религию человека: ";
		gets_s(Religion, 100);
	
	}

	human(char* NameP) : human(NameP, 0, 0, 0) { }

	human(char* NameP, char* GenderP) : human(NameP, GenderP, 0, 0) { }

	human(char* NameP, char* GenderP, int AgeP) : human(NameP, GenderP, AgeP, 0) { }

	human(char* NameP, char* GenderP, int AgeP, char* ReligionP) : // строка у нас стрлен от переданной переменной +1 в каждом динамическом массиве ведь больше нам попросту не понадобится
		Name{ new char[strlen(NameP) + 1] { *NameP } },
		Gender{ new char[strlen(GenderP) + 1] { *GenderP } },
		Age{ AgeP },
		Religion{ new char[strlen(ReligionP) + 1] { *ReligionP } }
	{ }

	human(const human& obj) :
		Name{ new char[strlen(obj.Name) + 1] { *obj.Name } },
		Gender{ new char[strlen(obj.Gender) + 1] { *obj.Gender } },
		Age{ obj.Age },
		Religion{ new char[strlen(obj.Religion) + 1] { *obj.Religion } }
	{ }


	void set_n(char* NameP) { strcpy_s(Name, strlen(Name), NameP); }
	void set_g(char* GenderP) { strcpy_s(Gender, strlen(Gender), GenderP); }
	void set_a(int AgeP) { Age = AgeP; }
	void set_r(char* ReligionP) { strcpy_s(Religion, strlen(Religion), ReligionP); }

	char* get_n() { return Name; }
	char* get_g() { return Gender; }
	int& get_a() { return Age; }
	char* get_r() { return Religion; }

	~human()
	{
		delete[] Name;
		delete[] Gender;
		delete[] Religion;
	}

	// тут особо нечего писать в коммментариях, самый простой класс
};