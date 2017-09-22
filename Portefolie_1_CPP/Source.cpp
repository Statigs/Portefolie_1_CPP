#include "StringTokenizer.h"
#include <iostream>

using namespace std;

void main()
{
	char i;
	StringTokenizer the_text("Jeg ......er, en gut"," .,:;");
	cout << the_text.nextToken() << endl;
	cout << the_text.nextToken() << endl;
	cout << the_text.nextToken() << endl;
	cout << the_text.nextToken() << endl;
	cout << the_text.countAllTokens() << endl;
	cout << the_text.countAllDelimiters() << endl;
	cin >> i;
}
