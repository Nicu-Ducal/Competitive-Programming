#include <bits/stdc++.h>
typedef unsigned int ui;
typedef long long ll;
using namespace std;

int t;
string s;

int main(){
ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
//ifstream cin(".in");
//ofstream cout(".out");

cin >> t;

while(t--)
{
    cin >> s;
    int len = s.length();
    s = '*' + s + '*';
    bool check = 0;
    for (int i = 1; i <= len; i++)
    {
        if (s[i] == s[i+1] && s[i] != '?') check = 1;
    }

    for (int i = 1; i <= len; i++)
    {
        if (s[i] != '?') continue;
        char c = 'a';
        if (s[i-1] == c || s[i+1] == c) c++;
        if (s[i-1] == c || s[i+1] == c) c++;
        s[i] = c;
    }
    if (check)
    {
        cout << "-1\n";
        continue;
    }
    for (int i = 1; i <= len; i++) cout << s[i];
    cout << "\n";
}

return 0;
}
