// BookStoreNew.cpp : Defines the entry point for the console application.
//Author : Deven Joshi
//GitHub : www.github.com/deven98

#include "stdafx.h"
//Remove the above line if you want to execute this single CPP file. Keep it there if you have checked out / cloned the project from Github.
#include<iostream>
#include<cstring>
#include<string>

using namespace std;

class Book {

	//Declaring variables for individual books

private:

	string author;
	string title;
	int price;
	
public:

	//Static variables to store number of books as it is not an independent quantity
	//Static variables are not part of the object , rather all classes share the same static variable, so any increment is an increment to all of them.

	static int numberOfBooks;

	//Getters and setters

	string getAuthor() { return author; }
	string getTitle() { return title; }
	int getPrice() { return price; }

};

int main()
{
	bool isSeller = false;
	//This boolean is used to check whether the person is the buyer or the seller and display menus accordingly.
	//If true then the seller menu is displayed or else the buyer menu is displayed.

	cout << "Enter 1 for Seller mode and 2 to purchase books" << endl;

	return 0;
}

