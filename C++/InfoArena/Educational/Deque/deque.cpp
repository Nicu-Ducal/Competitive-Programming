#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll n, k, num, sum;
deque < pair<ll, ll> > deq;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("deque.in");
    ofstream cout("deque.out");

    cin >> n >> k;
    for (ll i = 1; i <= n; i++){
        cin >> num;
        if ((i - deq.front().se) - k >= 0 && !deq.empty())
            deq.pop_front();
        while (!deq.empty() && deq.back().fi >= num)
            deq.pop_back();
        deq.push_back({num, i});
        if (i >= k)
            sum += deq.front().fi;
    }
    cout << sum;

    return 0;
}
