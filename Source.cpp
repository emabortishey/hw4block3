#include <iostream>
//#include "human.h"
//#include "flat.h"
#include "building.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");

	double count_pasta = 0, count_people = 0, procent = 0;

	building house;

	for (int i = 0; i < house.get_am(); i++)
	{
		for (int j = 0; j < house.get_flat_atributes(i)->get_am(); j++)
		{
			if (strcmp(house.get_hum_atributes(i,j)->get_r(), "Pastafarianism") == 0)
			{
				count_pasta++;
			}
			count_people++;
		}
	}

	cout << "\nОбщее количество людей проживающих в доме: " << count_people;
	cout << "\nпроцентное соотношение преверженцев пастафарианства к другим религиям: " << count_pasta / count_people * 100 << "%";

	return 0;
}