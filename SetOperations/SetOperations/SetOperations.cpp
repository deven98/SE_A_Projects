/*
Created by DEVEN on 25/7/2017
*/

// SetOperations.cpp : Defines the entry point for the console application.
// Author : Deven Joshi
//GitHub : www.github.com/deven98

#include "stdafx.h"
#include<iostream>
#include<stdlib.h>
#include<string>
#include<cstring>

using namespace std;

class Set {

private:
	int set[100];
	int numberOfElements;

public:

	Set() {

		numberOfElements = 0;

	}

	bool isEmpty() {
		
		if (numberOfElements == 0) { return 1; }
		else { return 0; }

	}

	void append(int a) {

		set[numberOfElements] = a;
		numberOfElements++;

	}

	void display() {

		for (int i = 0; i < numberOfElements; i++) {
			cout << set[i];
		}

	}

	int getNumberOfElements() {

		return numberOfElements;

	}

	int get(int i) {

		return set[i];

	}

	void setElement(int i,int element) {

		set[i] = element ;

	}

	void Union(Set B) {

		int result[200];
		int elementsInResult = 0;

		for (int i = 0; i < numberOfElements; i++) {

			result[i] = set[i];
			elementsInResult++;

		}

		bool repeatedElement = false;

		for (int i = 0; i < B.getNumberOfElements(); i++) {

			for (int j = 0; j < numberOfElements; j++) {

				if ( set[j] == B.get(i)) {
					repeatedElement = true;
					elementsInResult++;
				}

			}

			if (!repeatedElement) {
				result[elementsInResult] = B.get(i);
			}

		}

		for (int i = 0; i < elementsInResult; i++) {

			cout << result[i] << endl;

		}

	}

	void Intersection(Set B) {

		//Write code for intersection

	}

	void difference(Set B) {

		cout << B.set[0];

	}

};

int main()
{
	Set A,B;

	A.append(50);
	A.append(45);
	A.append(20);
	
	B.append(50);
	B.append(23);
	B.append(1);

	A.Union(B);

	//A.display();

    return 0;
}

