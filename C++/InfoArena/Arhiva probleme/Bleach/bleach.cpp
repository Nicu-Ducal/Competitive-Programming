#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

const int maxN = 1000005;
int n, k, v[maxN];
ll start = 0, now = 0;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("bleach.in");
    ofstream cout("bleach.out");

    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> v[i];
    sort(v, v + n);
    start = v[0];
    now = 2 * start;
    for(int i = 1; i < n; i++){
        if (v[i] > now)
            start += v[i] - now;
        now += max(v[i] - now, 0LL) + v[i];
        //cout << now << " ";
    }

    cout << start;


    return 0;
}
