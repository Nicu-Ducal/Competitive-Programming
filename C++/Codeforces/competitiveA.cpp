#include <bits/stdc++.h>
#include <string>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

int n;
string s;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> n;
    while (n--)
    {
        cin >> s;
        bool zero = 0;
        int two = 0;
        int sum = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int temp = s[i] - '0';
            sum += temp;
            if (temp == 0 && !zero) zero = 1;
            if (temp % 2 == 0 && two != 2 ) two++;
        }
        if (sum % 3 == 0 && zero && two == 2)
        {
            cout << "red\n";
            continue;
        }
        else
        {
            cout << "cyan\n";
        }
    }
    return 0;
}
