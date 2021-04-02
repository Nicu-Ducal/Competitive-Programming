#include <bits/stdc++.h>
typedef unsigned int ui;
typedef long long ll;
using namespace std;

int main(){
ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

int t;
string str;
cin >> t;

while(t--)
{
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        if (i != str.length() - 1 && str[i] == str[i+1] && str[i] != '?')
        {
            cout << "-1\n";
            break;
        }
        if (str[i] == '?')
        {
            if (i == 0)
            {
                if (str[i + 1] == 'a') str[i] = 'b';
                if (str[i + 1] == 'b') str[i] = 'c';
                if (str[i + 1] == 'c') str[i] = 'a';
            }
            if (i == str.length() - 1 || str[i] == str[i + 1] )
            {
                if (str[i - 1] == 'a') str[i] = 'b';
                if (str[i - 1] == 'b') str[i] = 'c';
                if (str[i - 1] == 'c') str[i] = 'a';
            }
            if (str[i - 1] == str[i + 1])
            {
                if (str[i - 1] == 'a') str[i] = 'b';
                if (str[i - 1] == 'b') str[i] = 'c';
                if (str[i - 1] == 'c') str[i] = 'a';
            }
            if (str[i - 1] != str[i + 1] && str[i] != str[i+1])
            {
                if (str[i - 1] = 'a')
                {
                    if (str[i + 1] = 'b') str[i] = 'c';
                    if (str[i + 1] = 'c') str[i] = 'b';
                }
                if (str[i - 1] = 'b')
                {
                    if (str[i + 1] = 'c') str[i] = 'a';
                    if (str[i + 1] = 'a') str[i] = 'c';
                }
                if (str[i - 1] = 'c')
                {
                    if (str[i + 1] = 'b') str[i] = 'a';
                    if (str[i + 1] = 'a') str[i] = 'b';
                }

            }
        }
    }
    cout << str <<"\3333n";
}


return 0;
}
