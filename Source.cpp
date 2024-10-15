#include <iostream>
//#include "human.h"
//#include "flat.h"
#include "building.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");

	double count_pasta = 0, count_people = 0, suspected_cults = 0, suspicion_count = 0;

	building house; // наш обьект-дом

	for (int i = 0; i < house.get_am(); i++)
	{
		for (int j = 0; j < house.get_flat_atributes(i)->get_am(); j++)
		{
			if (strcmp(house.get_hum_atributes(i,j)->get_r(), "Pastafarianism") == 0) // проверка графы религии на совпадение с пастафарианизмом
				// (давайте предположим что система безошибочно вбивает именно с большой буквы и на латинице, мне лень искать функцию дл€ сравнени€ без регистра и так далее
				// поэтому допустим что у нас крута€ безизь€нна€ система заполнени€ личного дела дл€ каждого человека)
			{
				count_pasta++;
			}
			count_people++; // подсчЄт общег количества проживающих в доме людей
		}
	}

	cout << "\nќбщее количество людей проживающих в доме: " << count_people;
	cout << "\nпроцентное соотношение преверженцев пастафарианства к другим религи€м: " << count_pasta / count_people * 100 << "%"; //подсчЄт процентажа к общей сумме


	for (int i = 0; i < house.get_am(); i++)
	{
		for (int j = 0; j < house.get_flat_atributes(i)->get_am(); j++)
		{
			if (strcmp(house.get_hum_atributes(i, j)->get_r(), "Pastafarianism") == 0 && house.get_flat_atributes(i)->get_am()>=5)
			{
				suspicion_count++; // подсчет людей в кваритре €вл€ющихс€ пастафарианцами
			}
		}

		if (suspicion_count >= house.get_flat_atributes(i)->get_am()-1) //проверка на количество людей (если пастафарианцем как минимум (все жильцы кваритры - 1) то квартира подозреваетс€ в культизме макаронного бога
		{
			suspected_cults++; 
		}

		suspicion_count = 0;
	}

	cout << "\n\nѕо подсчЄту кваритр, те, в которых проживает п€ть и более человек, при этом все они, кроме одного (предполагаетс€ что в кваритре 1 младенец не имеющий религиозных предпочтений ввиду возраста) €вл€ютс€ пастафарианцами составл€ет: " << suspected_cults;

	if (house.get_am() / 2 <= suspected_cults) // если подозреваемые культы составл€ют половину или больше, включаетс€ тревога на захват рептилойдами
	{
		cout << "\n\n\n“–≈¬ќ√ј! ¬ ƒќћ≈ ЅќЋ≈≈ ѕя“»ƒ≈—я“» ѕ–ќ÷≈Ќ“ќ¬  ¬ј–“»–, ѕ–»ЌјƒЋ≈∆јў»’ ѕ–≈ƒѕќЋќ∆»“≈Ћ№Ќџћ  ”Ћ№“јћ ѕј—“ј‘ј–»јЌ÷≈¬, ”√–ќ«ј «ј’¬ј“ј ƒќћј –≈ѕ“»Ћќ…ƒјћ»!!! “–≈Ѕ”≈“—я —–ќ„Ќјя Ё¬ј ”ј÷»я!!!\n\n\n";
	}

	return 0;
}