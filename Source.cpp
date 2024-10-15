#include <iostream>
//#include "human.h"
//#include "flat.h"
#include "building.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");

	double count_pasta = 0, count_people = 0, suspected_cults = 0, suspicion_count = 0;

	building house; // ��� ������-���

	for (int i = 0; i < house.get_am(); i++)
	{
		for (int j = 0; j < house.get_flat_atributes(i)->get_am(); j++)
		{
			if (strcmp(house.get_hum_atributes(i,j)->get_r(), "Pastafarianism") == 0) // �������� ����� ������� �� ���������� � ����������������
				// (������� ����������� ��� ������� ����������� ������� ������ � ������� ����� � �� ��������, ��� ���� ������ ������� ��� ��������� ��� �������� � ��� �����
				// ������� �������� ��� � ��� ������ ����������� ������� ���������� ������� ���� ��� ������� ��������)
			{
				count_pasta++;
			}
			count_people++; // ������� ����� ���������� ����������� � ���� �����
		}
	}

	cout << "\n����� ���������� ����� ����������� � ����: " << count_people;
	cout << "\n���������� ����������� ������������ ��������������� � ������ ��������: " << count_pasta / count_people * 100 << "%"; //������� ���������� � ����� �����


	for (int i = 0; i < house.get_am(); i++)
	{
		for (int j = 0; j < house.get_flat_atributes(i)->get_am(); j++)
		{
			if (strcmp(house.get_hum_atributes(i, j)->get_r(), "Pastafarianism") == 0 && house.get_flat_atributes(i)->get_am()>=5)
			{
				suspicion_count++; // ������� ����� � �������� ���������� ���������������
			}
		}

		if (suspicion_count >= house.get_flat_atributes(i)->get_am()-1) //�������� �� ���������� ����� (���� �������������� ��� ������� (��� ������ �������� - 1) �� �������� ������������� � ��������� ����������� ����
		{
			suspected_cults++; 
		}

		suspicion_count = 0;
	}

	cout << "\n\n�� �������� �������, ��, � ������� ��������� ���� � ����� �������, ��� ���� ��� ���, ����� ������ (�������������� ��� � �������� 1 �������� �� ������� ����������� ������������ ����� ��������) �������� ��������������� ����������: " << suspected_cults;

	if (house.get_am() / 2 <= suspected_cults) // ���� ������������� ������ ���������� �������� ��� ������, ���������� ������� �� ������ ������������
	{
		cout << "\n\n\n�������! � ���� ����� ���������� ��������� �������, ������������� ����������������� ������� ��������������, ������ ������� ���� ������������!!! ��������� ������� ���������!!!\n\n\n";
	}

	return 0;
}