#include<iostream>
#include<string>

using namespace std;

string deleteSpace(string &s)
{
	string new_string{ "" };
	size_t count = 0;
	if (s.find(" ") == 0)
	{
		string::iterator start = s.begin();
		do
		{
			new_string.push_back(*start);
			start++;
			count++;
		} while (*start == ' ');
	}

	for (size_t i = count; i < s.length(); i++)
	{
		if (s[i] == ' ' and s[i + 1] == ' ')
		{
			new_string.push_back(s[i]);
			while (s[i + 1] == ' ')
			{
				i++;
			}
		}
		else
		{
			new_string.push_back(s[i]);
		}
	}
	return new_string;
}

int main()
{
	string s{ "  adshfjkh kajdjk   a; kdjflkadj      akdfjklajdflka.  " };
	cout << s << endl;
	cout << deleteSpace(s);

	return 0;
}