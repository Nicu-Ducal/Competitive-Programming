#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll n, k ,t, v[100005], diffmax;
deque <ll> deqmax, deqmin;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("vila2.in");
    ofstream cout("vila2.out");

    cin >> n >> k;
    for (ll i = 1; i <= n; i++)
        cin >> v[i];
    deqmax.push_back(1), deqmin.push_back(1);

    for (ll i = 2; i <= n; i++){
        while(!deqmax.empty() && v[deqmax.back()] < v[i])
            deqmax.pop_back();
        deqmax.push_back(i);
        while(!deqmin.empty() && v[deqmin.back()] > v[i])
            deqmin.pop_back();
        deqmin.push_back(i);
        while(deqmax.back() - deqmax.front() > k)
            deqmax.pop_front();
        while(deqmin.back() - deqmin.front() > k)
            deqmin.pop_front();
        if (v[deqmax.front()] - v[deqmin.front()] > diffmax)
            diffmax = v[deqmax.front()] - v[deqmin.front()];
    }
    cout << diffmax;

    return 0;
}
