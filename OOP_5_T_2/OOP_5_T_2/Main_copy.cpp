
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

void print(const vector<char> &v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		if (v[i] == '\n')
		{
			cout << endl;
		}
		else
		{
			cout << v[i];
		}
	}
}

void deleteComment(string &s)
{
	string::size_type pos = s.rfind("//");
	string::size_type _pos = s.rfind(";");

	if (pos != string::npos and _pos != string::npos and pos < _pos)
	{
		return;
	}
	while (pos != string::npos)
	{
		s.erase(pos);
		pos = s.find("//", pos + 1);
	}
}

void deleteComment_2(string &s, vector<char> &v)
{
	for (size_t i = 0; i < s.length(); i++)
	{
		v.push_back(s[i]);
	}
	v.push_back('\n');
	int start_i = -1;
	int end_i = -1;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == '/')
		{
			if (v[i + 1] == '*')
			{
				start_i = i;
			}
		}
		else if (v[i] == '*')
		{
			if (v[i + 1] == '/')
			{
				end_i = i + 1;
				if (end_i - start_i > 0)
				{
					v.erase(v.begin() + start_i, v.begin() + end_i + 1);
					start_i = -1;
					end_i = -1;
				}
			}
		}
	}
}

int main()
{
	const string PATH{ "Main.cpp" };
	const string PATH_COPY{ "Main_copy.cpp" };

	ofstream f_out;
	f_out.open(PATH_COPY, ios::out);
	ifstream f_in;
	f_in.open(PATH, ios::in);

	
	string tmp_string{ "" };
	vector<char>buffer;

	if (f_in.is_open()) 
	{
		while (getline(f_in, tmp_string))
		{
			deleteComment(tmp_string);
			deleteComment_2(tmp_string, buffer);
		}
	}

	for (size_t i = 0; i < buffer.size(); i++)
	{
		f_out << buffer[i];
	}

	f_out.close(); 
	f_in.close();

	
	print(buffer);

	return 0;
}
