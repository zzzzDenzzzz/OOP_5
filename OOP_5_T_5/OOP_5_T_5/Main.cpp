#include<iostream>
#include<string>

using namespace std;

string f(const char &c, const string &_S1, const string &_S2, const string &_S3)
{
	string s_tmp{ "" };
	if (c == '0')
	{
		return s_tmp;
	}
	else
	{
		if (c < '4')
		{
			for (char i = '1'; i <= c; i++)
			{
				s_tmp += _S1;
			}
		}
		else if (c == '4')
		{
			s_tmp = _S1 + _S2;
		}
		else if (c > '4' and c < '9')
		{
			s_tmp = _S2;
			for (char i = '6'; i <= c; i++)
			{
				s_tmp += _S1;
			}
		}
		else
		{
			s_tmp = _S1 + _S3;
		}
	}

	return s_tmp;
}

string romanNumber(const string &s)
{
	string s_tmp;
	char c, cc, ccc, cccc;

	switch (s.length())
	{
	case 1:
		c = *s.begin();
		s_tmp = f(c, "I", "V", "X");
		break;
	case 2:
		c = *s.begin();
		cc = *(s.begin() + 1);
		s_tmp = f(c, "X", "L", "C") + f(cc, "I", "V", "X");
		break;
	case 3:
		c = *s.begin();
		cc = *(s.begin() + 1);
		ccc = *(s.begin() + 2);
		s_tmp = f(c, "C", "D", "M") + f(cc, "X", "L", "C") + f(ccc, "I", "V", "X");
		break;
	case 4:
		c = *s.begin();
		cc = *(s.begin() + 1);
		ccc = *(s.begin() + 2);
		cccc = *(s.begin() + 3);
		if (c == '0')
		{
			return s_tmp;
		}
		else
		{
			if (c < '4')
			{
				for (char i = '1'; i <= c; i++)
				{
					s_tmp += "M";
				}
				s_tmp = s_tmp + f(cc, "C", "D", "M") + f(ccc, "X", "L", "C") + f(cccc, "I", "V", "X");
			}
		}
		break;
	default:
		break;
	}

	return s_tmp;
}

int main()
{
	string number{ "3999" };
	string roman_number{ romanNumber(number) };

	cout << number << " = " << roman_number << endl;

	return 0;
}