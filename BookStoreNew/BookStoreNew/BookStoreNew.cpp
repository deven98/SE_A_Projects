// BookStoreNew.cpp : Defines the entry point for the console application.
//Author : Deven Joshi
//GitHub : www.github.com/deven98

#include "stdafx.h"
//Remove the above line if you want to execute this single CPP file. Keep it there if you have checked out / cloned the project from Github.
#include<iostream>
#include<cstring>
#include<string>
#include<stdlib.h>

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

	//Constructor
	Book() {}

	//Getters and setters
	string getAuthor() { return author; }
	string getTitle() { return title; }
	int getPrice() { return price; }

	void setDetails() {

		cout << "Enter the title of the book:" << endl;
		cin >> title;
		cout << "Enter the author:" << endl;
		cin >> author;
		cout << "Enter the price:" << endl;
		cin >> price;
		numberOfBooks++;
	}

	//Display Function

	void displayDetails() {

		cout << "Title : " << title << endl;
		cout << "Author : " << author << endl;
		cout << "Price : " << price << endl;
	
	}

	static void displayBooks(Book books[200]) {

		for (int i = 0; i < numberOfBooks; i++) {

			books[i].displayDetails();

		}

	}

};


// Initializing static members. 
int Book::numberOfBooks = 0;

int main()
{
	bool isSeller = false;
	//This boolean is used to check whether the person is the buyer or the seller and display menus accordingly.
	//If true then the seller menu is displayed or else the buyer menu is displayed.

	//An array of type Book for storing all books
	//Cart is the array that stores the books the user wants to purchase.
	Book books[200];
	Book cart[10];

	cout << "Welcome to <placeholder> Book Store!" << endl;
	cout << "Enter 1 for Seller mode and 2 to purchase books" << endl;
	
	//while loop keeps repeating until input is correct. If input is valid , loop breaks or else it gives an invalid command error.

	while (1) {
		int input;
		cin >> input;

		//Checks for valid input
		if (input == 1 || input == 2)
		{
			//If input is valid then decides if user is seller or buyer and assigns to bool accordingly.
			if (input == 1) { isSeller = true; }
			else { isSeller = false; }
			break;
		}
		cout << "Invalid command!" << endl;
	}

	//Now we have to display two menus using switch case. One if person is the buyer and the other if he's the seller.

	do{
		// if(isSeller) is equivalent to if(isSeller == true)
		if (isSeller) {
				
			do { 
			
				cout << "1.Add book"<<endl;
				cout << "2.Total Number of books" << endl;
				cout << "3.Search Book" << endl;
				cout << "4.Display books" << endl;
				cout << "5.Switch to buyer mode" << endl;

				int input;
				cin >> input;
				switch (input) {

				case 1:
					books[Book::numberOfBooks].setDetails();
					break;
						
				case 2:	
					cout << "Total number of books are : " << Book::numberOfBooks;
					break;

				case 3:
					//Search code
					break;

				case 4:
					Book::displayBooks(books);
					break;

				case 5:
					isSeller = false;
					break;

				default:
					cout << "Invalid command";
					break;
	
				}
		
			} while (isSeller);

		}
		else {

			//This will execute if the user selects buyer.

			do {
				cout << "1.List of Books" << endl;
				cout << "2.Search Book" << endl;
				cout << "3.Cart" << endl;
				cout << "4.Generate bill" << endl;
				cout << "5.Switch to seller mode" << endl;

				int input;
				cin >> input;
				switch (input) {

				case 1:
					break;

				case 2:
					break;

				case 3:
					break;

				case 4:
					break;

				case 5:
					isSeller = true;

				default:
					break;

				}

			} while (!isSeller);

		}
	
	} while (1);

	return 0;
}

