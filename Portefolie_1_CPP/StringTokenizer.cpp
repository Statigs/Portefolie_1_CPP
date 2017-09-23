#include "StringTokenizer.h"
#include <string>
#include <iostream>
using namespace std;

StringTokenizer::StringTokenizer(string a_text)
{
	text = a_text;
	index = 0;
}

StringTokenizer::StringTokenizer(string a_text, string a_delim)
{
	text = a_text;
	delim = a_delim;
	index = 0;
}

string StringTokenizer::nextToken()
{
	string temp_text = "";
	if (!hasMoreTokens())
	{
		return temp_text;
	}
	while (isDelimiter(text[index]))
	{
		index++;
	}
	while (!isDelimiter(text[index]))
	{
		temp_text += text[index];
		index++;
		if (index == text.length())
			return temp_text;
	}
	return temp_text;
}

string StringTokenizer::nextToken(string a_delim)
{
	delim = a_delim;
	return nextToken();
}

int StringTokenizer::countAllTokens()
{
	int saved_index = index;
	index = 0;
	int count = 0;
	while (index < text.length() && hasMoreTokens())
	{
		nextToken();
		count++;
	}
	index = saved_index;
	return count;
}

int StringTokenizer::countAllDelimiters()
{
	int count = 0;
	for(int i = 0; i <= text.length(); i++)
	{
		if (isDelimiter(text[i]))
		{
			count++;
		}
	}
	return count;
}

bool StringTokenizer::contains(string a_string)
{
	int location = text.find(a_string);
	if (location == string::npos)
	{
		return false;
	}
	if (!isDelimiter(text[location - 1]))
	{
		return false;
	}
	if (!isDelimiter(text[location + a_string.length()]))
	{
		return false;
	}
	return true;
}

void StringTokenizer::printContents()
{
	cout << "The text is \"" + text + "\"" << endl;
	cout << "There is " << countAllTokens() << " tokens." << endl;
	cout << "There is " << countAllDelimiters() << " delimiters." << endl;

}


bool StringTokenizer::hasMoreTokens()
{
	for (int i = index; i < text.length(); i++)
	{
		if (!isDelimiter(text[i]))
		{
			return true;
		}
	}
	return false;
}


bool StringTokenizer::isDelimiter(char a_char)
{
	return (delim.find_first_of(a_char) != string::npos);
}



StringTokenizer::~StringTokenizer()
{
}
