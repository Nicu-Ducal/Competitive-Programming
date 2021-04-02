#include <bits/stdc++.h>
typedef unsigned int ui;
typedef long long ll;
using namespace std;

int n;
int k[16] = {15, 14, 12, 13, 8, 9, 10, 11, 0, 1, 2, 3, 4, 5, 6, 7};

int main(){
ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
//ifstream cin(".in");
//ofstream cout(".out");

cin >> n;
cout << k[n];

return 0;
}
