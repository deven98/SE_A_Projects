// RecursionFactorial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

using namespace std;

int fact(int n) {

	if (n == 1) { return 1; }

	int factorial = 0;

	factorial = fact(n - 1)*n;

	return factorial;

}

int main()
{
	cout<< fact(5);

    return 0;
}

