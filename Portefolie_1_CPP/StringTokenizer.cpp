#include "StringTokenizer.h"
#include <string>
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
	while (isDelimiter(text[index]))
	{
		index++;
	}
	string temp_text = "";
	while (!isDelimiter(text[index]))
	{
		temp_text += text[index];
		index++;
		if (index == text.length())
		{
			break;
		}
	}
	return temp_text;
}

string StringTokenizer::nextToken(string a_delim)
{
	delim += a_delim;
	return nextToken();
}

int StringTokenizer::countAllTokens()
{
	int saved_index = index;
	index = 0;
	int count = 0;
	while (index < text.length())
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
	
}

void StringTokenizer::printContents()
{
	
}


bool StringTokenizer::hasMoreTokens()
{
	
}


bool StringTokenizer::isDelimiter(char a_char)
{
	return (delim.find_first_of(a_char) != string::npos);
}



StringTokenizer::~StringTokenizer()
{
}
