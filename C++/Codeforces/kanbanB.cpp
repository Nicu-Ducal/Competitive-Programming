#include <bits/stdc++.h>
typedef unsigned int ui;
typedef long long ll;
using namespace std;

int n;

string kanban(int n)
{
    if (n % 10 == 1 || n % 10 == 7 || n % 10 == 9 || (n >= 9 && n <= 11) || (n >= 13 && n <= 29) || (n >= 70 && n <= 79) || (n >= 90 && n <= 99) )
        return "NO";
    return "YES";
}

int main(){
ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
//ifstream cin(".in");
//ofstream cout(".out");

cin >> n;
cout << kanban(n);

return 0;
}
