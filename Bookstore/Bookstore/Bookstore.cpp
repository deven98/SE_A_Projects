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
	int price, stock;
	Book *next;

public:
	void addBook()
	{
		Book *newBook = new Book;
		cout << "Enter the book name\n";
		cin >> name;
		cout << "Enter the price";
		cin >> price;
		cout << "Enter the publisher's name\n";
		cin >> pub;
		cout << "Enter the number of books\n";
		cin >> stock;
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
	string cart[10];
	int totalPrice[10];

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
		int choice;
		cout << "Enter 1 to add a book\nEnter 2 to display all the books\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			head->addBook();
		}
		case 2:
		{

		}
		}
			

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
				head->searchBook();
				break;
			case 2:
				head->displayBook();
				break;
			case 3:
				for (int i = 0; i < cart->size; i++) {
					cout <<i+1<<". "<< cart[i] << endl;
				}
				break;
			case 4:
				int sum = 0;
				for (int i = 0; i < sizeof(totalPrice); i++) {
					cout <<i+1<<". "<< totalPrice[i]<<endl;
					sum = sum + totalPrice[i];
				}
				cout << "Your total is : " << sum;
				break;
			default:
				cout << "Invalid input";
			}

		} while (true);
	
	}
    return 0;
}

