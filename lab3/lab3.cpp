// lab3.cpp: ���������� ����� ����� ��� ����������� ����������.
//������� 9.����� ���� ��� ����� ����� �����.����������, ������ �� ����������� �������� ������� �����, ��� ������������ �������� �������.

#include "stdafx.h"

int CheckMin(ifstream &file) //���������� ������������ �������� � �����.
{
	int Min=INT_MAX;
	int size;
	int temp=0;
	file.seekg(0, ios::end);
	size = file.tellg();
	file.seekg(0, ios::beg);
	
	while ((int)file.tellg() < size)
	{
		file.read((char *)&temp, sizeof(int));
		if (temp <= Min)
			Min = temp;
	}
	return Min;
}
int CheckMax(ifstream &file) //���������� ������������� �������� � �����.
{
	int Max = INT_MIN;
	int size;
	int temp = 0;
	file.seekg(0, ios::end);
	size = file.tellg();
	file.seekg(0, ios::beg);

	while ((int)file.tellg() < size)
	{
		file.read((char *)&temp, sizeof(int));
		if (temp >= Max)
			Max = temp;
	}
	return Max;
}

void FillFile(ofstream &file,int q) //�������� ��������� ����� � ���������� ����������.
{
	int temp;
	for (int i = 0; i != q; i++)
	{
		temp = rand() % 100 - 30;
		file.write((char *)&temp, sizeof(int));
	}
}

void FileWriteOut(ifstream &filei, ofstream &fileo, int q) //����� ��������� �������� � ���� ��� �������� ���������� ��������.
{
	int temp;
	for (int i = 0; i != q; i++)
	{
		filei.read((char *)&temp, sizeof(int));
		fileo << temp << " ";
	}
}

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "rus");

	int quontity;
	cout << "������� ����������� ���������� ��������� �����: " << endl;
	cin >> quontity;
	ofstream fileo_1("FileIn1.txt", ios::binary);
	ofstream fileo_2("FileIn2.txt", ios::binary);

	FillFile(fileo_1,quontity);//�������� ��������� �����
	fileo_1.close();

	FillFile(fileo_2,quontity);//�������� ��������� �����
	fileo_2.close();

	ifstream filei_1("FileIn1.txt", ios::binary);
	ifstream filei_2("FileIn2.txt", ios::binary);

	ofstream fileok_1("FileOut1.txt");
	ofstream fileok_2("FileOut2.txt");


	FileWriteOut(filei_1, fileok_1,quontity);//����� ����� � ������� ��� �������� ����
	FileWriteOut(filei_2, fileok_2,quontity);//����� ����� � ������� ��� �������� ����

	if(CheckMin(filei_1)>CheckMax(filei_2))
		cout << "����������� �������� ������� ����� ������ ��� ������������ �������� �������." << endl;
	else
		cout <<"����������� �������� ������� ����� ������ ��� ������������ �������� �������."<< endl;
	cout << CheckMin(filei_1) << " " << CheckMax(filei_2) << endl;
	fileok_1.close();
	fileok_2.close();
	return 0;
}

