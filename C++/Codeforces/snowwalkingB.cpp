#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

string s;
int q;
int t[4];
char l[4] = {'U', 'D', 'L', 'R'};

int main()
{
    cin >> q;
    while (q--)
    {
        t[0] = t[1] = t[2] = t[3] = 0;
        cin >> s;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'U') t[0]++;
            else if (s[i] == 'D') t[1]++;
            else if (s[i] == 'L') t[2]++;
            else if (s[i] == 'R') t[3]++;
        }

        ll minUD = min (t[0], t[1]);
        ll minLR = min (t[2], t[3]);

        if (minUD == 0 && minLR == 0)
        {
            cout << 0 << "\n\n";
            continue;
        }
        else if (minUD == 0)
        {
            cout << 2 << "\n" << "LR" << "\n";
            continue;
        }
        else if (minLR == 0)
        {
            cout << 2 << "\n" << "UD" << "\n";
            continue;
        }
        else
        {
            cout << 2 * (minLR + minUD) << "\n";
            for (int i = 0; i < minUD; i++) cout << "U";
            for (int i = 0; i < minLR; i++) cout << "R";
            for (int i = 0; i < minUD; i++) cout << "D";
            for (int i = 0; i < minLR; i++) cout << "L";
            cout << "\n";
        }
    }
    return 0;
}
