// Prac2 - SAOD.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <windows.h>
#include <iostream>
#include "Finder.h"

using namespace std;

void main()
{
	string text = "";
	string shape = "";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Введите текст(латиницей)" << endl;
	getline(cin, text);
	Finder *finder = new Finder(text);
	cout << "Введите образ(латиницей)" << endl;
	getline(cin, shape);
	int indexE1 = finder->Excercise1(shape, true);
	if (indexE1 != -1) {
		cout << "Найден образ по индексу " << indexE1 << endl;
	}
	else {
		cout << "Данный образ не найден." << endl;
	}

	system("pause");
}


