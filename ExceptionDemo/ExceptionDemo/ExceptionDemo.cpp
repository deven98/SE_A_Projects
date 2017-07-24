// ExceptionDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<exception>
#include<string>
#include<stdlib.h>

using namespace std;

class Value_Out_Of_Bounds_Exception : public exception {
public:
	const char * what() const throw()
	{
		return "Value is out of bounds!\n";
	}
};

class Person {

private:
	int age;
	bool hasFourWheeler;
	int income;
	string city;

public:

	void checkValidity() {

		Value_Out_Of_Bounds_Exception v;
		if ((age < 15 || age>55) || !hasFourWheeler || (income < 50000 || income >100000) || ((city != "Pune") && (city != "Bangalore") && (city != "Mumbai") && (city != "Chennai")))
		throw v;
	}

	void setData() {

		cout << "Enter your city : " << endl;
		getline(cin, city);
		cout << "Enter your age : " << endl;
		cin >> age;
		cout << "Enter your income : " << endl;
		cin >> income;
		cout << "Press 1 if you have a 4-wheeler and 0 if you do not : " << endl;
		cin >> hasFourWheeler;
	
	}

};

int main()
{
	Person p;
	p.setData();
	p.checkValidity();

    return 0;
}

