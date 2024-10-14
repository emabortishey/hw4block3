#include <iostream>
using namespace std;

class human
{
	char* Name;
	char* Gender;
	int Age;
	char* Religion;
public:

	human()
	{ 
		Name = new char[100];
		Gender = new char[100];
		Religion = new char[100];

		cin.ignore();
		cout << "\n¬ведите им€ человека: ";
		gets_s(Name, 100);
		cout << "\n¬ведите пол человека: ";
		gets_s(Gender, 100);
		cout << "\n¬ведите возраст человека: ";
		cin >> Age;
		cin.ignore();
		cout << "\n¬ведите религию человека: ";
		gets_s(Religion, 100);
	
	}

	human(char* NameP) : human(NameP, 0, 0, 0) { }

	human(char* NameP, char* GenderP) : human(NameP, GenderP, 0, 0) { }

	human(char* NameP, char* GenderP, int AgeP) : human(NameP, GenderP, AgeP, 0) { }

	human(char* NameP, char* GenderP, int AgeP, char* ReligionP) :
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
	int get_a() { return Age; }
	char* get_r() { return Religion; }

	~human()
	{
		delete[] Name;
		delete[] Gender;
		delete[] Religion;
	}
};