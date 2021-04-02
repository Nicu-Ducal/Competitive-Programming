#include <bits/stdc++.h>
typedef unsigned int ui;
typedef long long ll;
using namespace std;

string s;
string h = "hello";

int main(){
ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
//ifstream cin(".in");
//ofstream cout(".out");

cin >> s;
int n = s.length();
int ind = 0;
bool check = 1;

for (int i = 0; i < n; i++)
{
    if (s[i] == h[ind])
    {
        ind++;
        if (ind == 5)
        {
            cout << "YES";
            check = 0;
            break;
        }
    }
}

if (check) cout << "NO";

return 0;
}
