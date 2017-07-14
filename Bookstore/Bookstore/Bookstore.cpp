// Bookstore.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>

using namespace std;
//Initial commit

class Book
{
private:
	string name, price, pub;
	int price;
	Book *next;

public:
	void insert()
	{
		Book *newBook = new Book;
		cout << "Enter the book name\n";
		cin >> name;
		cout << "Enter the price";
		cin >> price;
		cout << "Enter the publisher's name\n";
		cin >> pub;
		if (head == NULL) //create a head
		{
			newBook->next = NULL;
			head = newBook;
		}
		else// insert at head
		{
			newBook->next = head;
			head = newBook;
		}
	}
};

Book *head = NULL;



int main()
{
	bool isSeller;
	cout << "Enter 1 to buy books\nEnter 2 to sell\n";
	int c;
	cin >> c;
	if (c == 1)
		isSeller = false;
	else
		isSeller = true;

	if (isSeller)
	{

	}
	else
	{
		do {

			cout << "Welcome to the book store" << endl;
			cout << "1. Search book" << endl;
			cout << "2. Display Books" << endl;
			cout << "3. Check cart" << endl;
			cout << "4. Checkout" << endl;

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
			default:
				cout << "Invalid input";
			}

		} while (true);
	
	}
    return 0;
}

