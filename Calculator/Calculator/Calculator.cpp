// Calculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

using namespace std;

class Calculator {

private:

	float operand1, operand2, result;
	char operation;
	bool isRunning;

public:

	void input(){
	
		cout << "Enter your operation in the format operand1 [space] operation [space] operand 2" << endl;
		cin >> operand1 >> operation >> operand2;
		cout << endl;

	}

	void displayResult(){cout << "The result is: " << result << endl;}

	void add() { result = operand1 + operand2; }

	void subtract() { result = operand1 - operand2; }

	void divide() { result = operand1 / operand2; }

	void multiply() { result = operand1 * operand2; }

	void runDecisionLoop() {

		while (isRunning) {

			input();

			switch (operation)
			{
			case '+' :
				add();
				break;
			case '-' :
				subtract();
				break;
			case '*':
				multiply();
				break;
			case'/':
				divide();
				break;
			default:
				break;
			}

			displayResult();

			cout << "Do you want to run calculator again? (y/n)" << endl;

			char input;
			cin >> input;

			if (input == 'n') { isRunning = false; }
			else { isRunning = true; }
		
		}

	}

};

int main()
{

	Calculator c;

	c.runDecisionLoop();

    return 0;
}

