#include <bits/stdc++.h>
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

int t;
string s, s2, s4, s5;

int main(){
ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> t;
    while (t--)
    {
        cin >> s;
        int len = s.length();

        s2 = s.substr(len - 2, 2);
        if (s2 == "po")
        {
            cout << "FILIPINO" << "\n";
            continue;
        }

        s4 = s.substr(len - 4, 4);
        if (s4 == "desu" || s4 == "masu")
        {
            cout << "JAPANESE" << "\n";
            continue;
        }

        s5 = s.substr(len - 5, 5);
        if (s5 == "mnida")
        {
            cout << "KOREAN" << "\n";
            continue;
        }
    }
    return 0;
}
