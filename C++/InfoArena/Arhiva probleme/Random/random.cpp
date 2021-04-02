#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("random.in");
    ofstream cout("random.out");

    int n;
    cin >> n;
    switch (n){
        case 1982:
            cout << "Robert Tarjan"; break;
        case 1986:
            cout << "Leslie Valiant"; break;
        case 1990:
            cout << "Alexander Razborov"; break;
        case 1994:
            cout << "Avi Wigderson"; break;
        case 1998:
            cout << "Peter Shor"; break;
        case 2002:
            cout << "Madhu Sudan"; break;
        case 2006:
            cout << "Jon Kleinberg"; break;
        case 2010:
            cout << "Daniel Spielman"; break;
        case 2014:
            cout << "Subhash Khot"; break;
    }

    return 0;
}
