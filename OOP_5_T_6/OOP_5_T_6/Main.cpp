#include<iostream>
#include<string>

using namespace std;

void pathString(const string &s)
{
	string::size_type pos = s.rfind("\\");
	string::size_type tmp = pos;
	if (pos != string::npos)
	{
		cout << "a) \"";
		for (size_t i = 0; i < pos; i++)
		{
			cout << s[i];
		}
		cout << "\"" << endl;
	}
	else
	{
		cout << "\"  \"" << endl;
		return;
	}

	pos = s.rfind("\\", tmp - 1);
	if (pos != string::npos)
	{
		cout << "b) \"";
		for (size_t i = pos + 1; i < tmp; i++)
		{
			cout << s[i];
		}
		cout << "\"" << endl;
	}
	else
	{
		cout << "\"  \"" << endl;
		return;
	}

	cout << "c) \"";
	for (size_t i = tmp + 1; i < s.size(); i++)
	{
		cout << s[i];
	}
	cout << "\"" << endl;

	pos = s.rfind(".");
	tmp = pos;
	if (pos != string::npos)
	{
		cout << "d) \"";
		for (size_t i = pos; i < s.size(); i++)
		{
			cout << s[i];
		}
		cout << "\"" << endl;
	}
	else
	{
		cout << "\"  \"" << endl;
		return;
	}

	pos = s.rfind("\\", tmp);
	if (pos != string::npos)
	{
		cout << "e) \"";
		for (size_t i = pos + 1; i < tmp; i++)
		{
			cout << s[i];
		}
		cout << "\"" << endl;
	}
	else
	{
		cout << "\"  \"" << endl;
		return;
	}
}

int main()
{
	string path{ "C:\\Step\\C++lesson_03\\Docs\\Less03.docx" };
	pathString(path);

	return 0;
}