// Bookstore .cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

using namespace std;

class Book {

private:
	char name[20];
	int price;
	char publisher[20];

public:

	char getName() {
		return *name;
	}

	void setName(string nameStr) {
		strcpy_s(name, nameStr.c_str());
	}

};

int main()
{
	Book one ;
	one.setName("Random");
	cout << one.getName();
    return 0;
}

