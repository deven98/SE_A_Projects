// ExceptionDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<exception>

using namespace std;

class Value_Out_Of_Bounds_Exception : public exception {
public:
	const char * what() const throw()
	{
		return "Value is out of bounds!\n";
	}
};

int main()
{
	

    return 0;
}

