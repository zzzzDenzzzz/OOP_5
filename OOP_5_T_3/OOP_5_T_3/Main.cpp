#include<iostream>
#include<string>

using namespace std;

string stringMod(const string &s1, const string &s2)
{
	string tmp_s1 = s1;
	string tmp_s2 = "(" + s2 + ")";

	string::size_type pos = s1.find(s2);
	while (pos != string::npos)
	{
		tmp_s1.replace(pos, s2.length(), tmp_s2);
		pos = tmp_s1.find(s2, pos + tmp_s2.length() - s2.length());
	}

	return tmp_s1;
}

int main()
{
	string s1{ "fdagjjfjoeijjfkjoijlkpoqjjffpoerfwejjffd" };
	string s2{ "jjf" };
	string s3{ stringMod(s1, s2) };

	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;

	return 0;
}