#include <bits/stdc++.h>
using namespace std;

int Adunare(int x, int y){
    return x+y;
}

int main(){

ifstream cin("adunare.in");
ofstream cout("adunare.out");

int x,y;
cin >> x >> y;
cout << Adunare(x,y);

return 0;
}
