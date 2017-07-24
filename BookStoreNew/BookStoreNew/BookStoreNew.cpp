/*
Created by DEVEN on 24/7/17
*/

// BookStoreNew.cpp : Defines the entry point for the console application.
//Author : Deven Joshi
//GitHub : www.github.com/deven98

#include "stdafx.h"
//Remove the above line if you want to execute this single CPP file. Keep it there if you have checked out / cloned the project from Github.
#include<iostream>
#include<cstring>
#include<string>
#include<stdlib.h>
//If you are using any other compiler than Visual studio , you may need to edit the header files with '.h'.

//IMPORTANT : I've used static functions to avoid creating objects for every single function call.
// I recommend you read up on static functions because of their usefulness in reducing boilerplate code and instantiation.
// You can read the code without a knowledge of static functions as well. 

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
	static int itemsInCart;

	//Constructor
	Book() {}

	//Getters and setters
	string getAuthor() { return author; }
	string getTitle() { return title; }
	int getPrice() { return price; }

	void setDetails() {

		system("cls");
		cout << "Enter the title of the book:" << endl;
		cin.ignore();
		getline(cin, title);
		cout << "Enter the author:" << endl;
		cin.ignore();
		getline(cin, author);
		cout << "Enter the price:" << endl;
		cin >> price;
		numberOfBooks++;
		system("cls");

	}

	//Display Function

	void displayDetails() {

		cout << "Title : " << title << endl;
		cout << "Author : " << author << endl;
		cout << "Price : " << price << endl;

	}

	//Static functions to avoid creating objects :-P

	//Used to display the list of books available
	static void displayBooks(Book books[200]) {

		system("cls");

		for (int i = 0; i < numberOfBooks; i++) {

			cout << i + 1 << ". " << endl;
			books[i].displayDetails();

		}

	}

	//Used to display books in cart
	static void displayCart(Book books[10]) {

		system("cls");

		for (int i = 0; i < itemsInCart; i++) {

			books[i].displayDetails();

		}
	}
	//Used to search by author
	static void searchByAuthor(Book books[200], string Author) {

		system("cls");

		for (int i = 0; i < numberOfBooks; i++) {

			if (Author == books[i].getAuthor()) {
				books[i].displayDetails();
			}
		}
	}

	//Used to search title
	//Not overloaded because of same parameter types. Another option is to add a third boolean parameter to identify operation.
	static void searchByTitle(Book books[200] , string Title) {

		system("cls");

		for (int i = 0; i < numberOfBooks; i++) {

			if (Title == books[i].getTitle()) {
				books[i].displayDetails();
			}
		}
	}

};

//Displays a starline. Only for presentation , no actual use.
void starLine() { cout << "*************************" << endl; }


// Initializing static members. 
int Book::numberOfBooks = 0;
int Book::itemsInCart = 0;

int main()
{
	bool isSeller = false;
	//This boolean is used to check whether the person is the buyer or the seller and display menus accordingly.
	//If true then the seller menu is displayed or else the buyer menu is displayed.

	//An array of type Book for storing all books
	//Cart is the array that stores the books the user wants to purchase.
	Book books[200];
	Book cart[10];

	starLine();
	cout << "Welcome to <placeholder> Book Store!" << endl;
	cout << "Enter 1 for Seller mode and 2 to purchase books" << endl;
	starLine();
	
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
				
			//This only runs if user has chosen the seller option

			do { 
			
				cout << "1.Add book"<<endl;
				cout << "2.Total Number of books" << endl;
				cout << "3.Search Book" << endl;
				cout << "4.Display books" << endl;
				cout << "5.Switch to buyer mode" << endl;

				int input;
				cin >> input;
				string in;
				switch (input) {

				case 1:
					books[Book::numberOfBooks].setDetails();
					break;
						
				case 2:	
					cout << "Total number of books are : " << Book::numberOfBooks << endl;
					break;

				case 3:
					cout << "Press 1 or searching by title or 2 for author" << endl;
					cin >> input;
					
					//Nested switch-case for identifying search option
					switch (input)
					{
					case 1:
						cout << "Enter the title of the book" << endl;
						cin >> in;
						Book::searchByTitle(books,in);
					case 2:
						cout << "Enter the author of the book" << endl;
						cin >> in;
						Book::searchByAuthor(books, in);
					default:
						cout << "Invalid command" << endl;
						break;
					}
					break;

				case 4:
					Book::displayBooks(books);
					break;

				case 5:
					isSeller = false;
					system("cls");
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

				int sum = 0;
				string in;
				int input;
				cin >> input;
				switch (input) {

				case 1:
					Book::displayBooks(books);
					cout << "Enter the number of the book you want to add: "<<endl;
					cin >> input;
					cart[Book::itemsInCart] = books[input - 1];
					Book::itemsInCart++;
					break;

				case 2:
					cout << "Press 1 or searching by title or 2 for author" << endl;
					cin >> input;

					//Nested switch-case to identify search option

					switch (input)
					{
					case 1:
						cout << "Enter the title of the book" << endl;
						cin >> in;
						Book::searchByTitle(books, in);
						break;
					case 2:
						cout << "Enter the author of the book" << endl;
						cin >> in;
						Book::searchByAuthor(books, in);
						break;
					default:
						cout << "Invalid command" << endl;
						break;
					}
					break;

				case 3:
					Book::displayCart(books);
					break;

				case 4:

					for (int i = 0; i < Book::itemsInCart; i++) {
						sum = sum + cart[i].getPrice();
					}
					system("cls");
					cout << "Your total is : " << sum << endl;
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

