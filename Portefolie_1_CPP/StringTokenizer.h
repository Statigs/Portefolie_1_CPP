#pragma once
#include <string>

using namespace std;

class StringTokenizer
{
public:
	StringTokenizer(string text);
	StringTokenizer(string text, string delim);
	~StringTokenizer();

	string nextToken();
	string nextToken(string);
	int countAllTokens();
	int countAllDelimiters();
	bool contains(string);
	void printContents();
private:
	bool isDelimiter(char);
	bool hasMoreTokens();
	string text;
	string delim;
	int index;
};

