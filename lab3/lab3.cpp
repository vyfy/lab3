// lab3.cpp: определяет точку входа для консольного приложения.
//Вариант 9.Пусть даны два файла целых чисел.Определите, больше ли минимальное значение первого файла, чем максимальное значение второго.

#include "stdafx.h"

int CheckMin(ifstream &file) //Нахождение минимального значения в файле.
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
int CheckMax(ifstream &file) //Нахождение максимального значения в файле.
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

void FillFile(ofstream &file,int q) //Создание бинарного файла с случайными значениями.
{
	int temp;
	for (int i = 0; i != q; i++)
	{
		temp = rand() % 100 - 30;
		file.write((char *)&temp, sizeof(int));
	}
}

void FileWriteOut(ifstream &filei, ofstream &fileo, int q) //Вывод случайных значений в файл для удобства дальнейшей проверки.
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
	cout << "Введите необходимое количество случайных чисел: " << endl;
	cin >> quontity;
	ofstream fileo_1("FileIn1.txt", ios::binary);
	ofstream fileo_2("FileIn2.txt", ios::binary);

	FillFile(fileo_1,quontity);//Создание бинарного файла
	fileo_1.close();

	FillFile(fileo_2,quontity);//Создание бинарного файла
	fileo_2.close();

	ifstream filei_1("FileIn1.txt", ios::binary);
	ifstream filei_2("FileIn2.txt", ios::binary);

	ofstream fileok_1("FileOut1.txt");
	ofstream fileok_2("FileOut2.txt");


	FileWriteOut(filei_1, fileok_1,quontity);//Вывод файла в удобном для проверки виде
	FileWriteOut(filei_2, fileok_2,quontity);//Вывод файла в удобном для проверки виде

	if(CheckMin(filei_1)>CheckMax(filei_2))
		cout << "Минимальное значение первого файла БОЛЬШЕ чем максимальное значение второго." << endl;
	else
		cout <<"Минимальное значение первого файла МЕНЬШЕ чем максимальное значение второго."<< endl;
	cout << CheckMin(filei_1) << " " << CheckMax(filei_2) << endl;
	fileok_1.close();
	fileok_2.close();
	return 0;
}

