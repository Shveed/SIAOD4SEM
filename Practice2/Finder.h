#pragma once

#include <iostream>
#include <string>
using namespace std;

class Finder
{
private:
	string Line = "";
public:
	Finder(string line);
	~Finder();
	string getLine();
	string toLower(string line);
	int Excercise1(string shape, bool caseSensitive);
};

