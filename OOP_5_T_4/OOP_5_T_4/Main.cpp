#include<iostream>
#include<string>
#include<vector>

using namespace std;

string modString(const string &s)
{
    int factor = 10;
    int res = 0;
    string new_s;
    vector<int>v_int;
    vector<char>v_char;
    bool flag = false;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' and s[i] <= '9')
        {
            res = res * factor + s[i] - '0';
            continue;
        }
        if (s[i] == '+' or s[i] == '-')
        {
            v_char.push_back(s[i]);
            v_int.push_back(res);
            res = 0;
            flag = true;
            continue;
        }
        if (flag)
        {
            switch (v_char[0])
            {
            case '+':
                res = v_int[0] + res;
                break;
            case '-':
                res = v_int[0] - res;
                break;
            default:
                break;
            }
            new_s += to_string(res);
            new_s.push_back(s[i]);
            flag = false;
            res = 0;
            v_char.clear();
            v_int.clear();
        }
        else
        {
            new_s.push_back(s[i]);
        }
    }
    return new_s;
}

int main()
{
    string s{ "alpha 5+26 beta 72-35 gamma 32+45 etc" };
    cout << s << endl;
    cout << modString(s) << endl;

    return 0;
}