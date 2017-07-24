/*
Created by DEVEN on 24/7/2017
*/

// MultipleInheritanceDemo.cpp : Defines the entry point for the console application.
// Author: Deven Joshi
// GitHub: www.github.com/deven98

#include "stdafx.h"
#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<string>

using namespace std;

class PersonalRecord{

private:
	string name;
	string bloodGroup;

public:

	void setPersonalRecord() {

		cout << "Enter your name : " << endl;
		getline(cin, name);
		cout << "Enter your blood group" << endl;
		getline(cin, bloodGroup);

	}

	void displayPersonalRecord() {

		cout << "Name : " << name << endl;
		cout << "Blood Group : " << bloodGroup << endl;

	}

};

class AcademicRecord{

private:
	float CGPA;
	string college;
	string degree;

public:
	float getCGPA() { return CGPA; }
	string getCollege() { return college; }
	string getDegree() { return degree; }

	void setAcademicRecord() {

		cout << "Enter your degree : " << endl;
		getline(cin, degree);
		cout << "Enter your college : " << endl;
		getline(cin, college);
		cout << "Enter your CGPA : " << endl;
		cin >> CGPA;

	}

	void displayAcademicRecord() {

		cout << "Degree : " << degree << endl;
		cout << "College : " << college << endl;
		cout << "CGPA : " << CGPA << endl;

	}

};

class ProfessionalRecord{

private:
	float yearsOfExperience;

public:
	
	void setProfessionalRecord(){
		
		cout << "Enter your years of experience : " << endl;
		cin >> yearsOfExperience;

	}

	void displayProfessionalRecord() {

		cout << "Experience : " << yearsOfExperience << " years" << endl;

	}

};

class Person :public PersonalRecord, public AcademicRecord, public ProfessionalRecord {

public:

	void setBiodata() {

		setPersonalRecord();
		setAcademicRecord();
		setProfessionalRecord();

	}


	void displayBiodata() {

		system("cls");

		displayPersonalRecord();
		displayAcademicRecord();
		displayProfessionalRecord();

	}

};

int main()
{
	cout << "Hello random person" << endl;

	Person person1;

	person1.setBiodata();

	person1.displayBiodata();

    return 0;
}

