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
			addBook();
		}
		case 2:
		{

		}
		}
			

	}
	else
	{

	}
    return 0;
}

