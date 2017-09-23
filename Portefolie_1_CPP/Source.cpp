#include "StringTokenizer.h"
#include <iostream>
#include <sstream>

using namespace std;

void main()
{
	string the_text;
	string startdelims;
	cout << "Enter the text you wish to analyse:" << endl;
	getline(cin, the_text);
	cout << "" << endl;
	cout << "Enter possible delimiters:" << endl;
	getline(cin, startdelims);
	cout << "" << endl;
	StringTokenizer test_text(the_text, startdelims);

	cout << "Select your needed action: " << endl << "1: Show the current text and all information about it!" <<
		endl << "2: Find the next token!" << endl << "3: Update the delimiters and then find the next token" << endl <<
		"4: Show how many tokens there is!" << endl << "5: Show how many delimiters there is!" << endl <<
		"6: Find out if a certain string is contained in the text!" << endl << "7: Exit program" << endl;
	again:
	int i = 0;
	string input = "";
	while (true)
	{
		cout << "" << endl;
		cout << "Enter a option: ";
		getline(cin, input);
		stringstream int_casting(input);
		if (int_casting >> i)
			break;
		cout << "Invalid number, please try again" << endl;
	}
	switch (i)
	{
	case 1:
		test_text.printContents();
		goto again;
	case 2:
		cout << test_text.nextToken() << endl;
		goto again;
	case 3:
		cout << "Enter new delimiters: ";
		getline(cin, input);
		cout << test_text.nextToken(input) << endl;
		goto again;
	case 4:
		cout << test_text.countAllTokens() << endl;
		goto again;
	case 5:
		cout << test_text.countAllDelimiters() << endl;
		goto again;
	case 6:
		cout << "Enter desired string to find: " << endl;
		getline(cin, input);
		if (test_text.contains(input))
		{
			cout << "The text contains the requested string!" << endl;
		}
		else
		{
			cout << "The text does not contains the requested string!" << endl;
		}
		goto again;
	case 7:
		cout << "See you later" << endl;
		system("pause");
		break;
	default:
		cout << "Invalid number, please try again" << endl;
		goto again;
	}
}
