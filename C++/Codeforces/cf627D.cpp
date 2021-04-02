#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define inf 0x3f3f3f3f
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll nCk(ll n, ll k){
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    int result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}
/*
ll binarysearch(ll a[], ll num, ll left, ll right){
    int n = right + 1;
    if (num > a[right])
        return n;
    while(left < right){
        ll mid = left + (right - left) / 2;
        //cout << num << " " << mid << '\n';
        if(a[mid] == num){
            if(a[mid] == a[mid - 1])
                right = mid - 1;
            else
                return mid;
        }

        else if (a[mid] > num)
            right = mid - 1;
        else
            left = mid + 1;
    }
    if (left == right){
        if (a[left - 1] - (num - 1) > 0)
            return left - 1;
        if (a[left] - (num - 1) > 0)
            return left;
        else if (a[left + 1] - (num - 1) > 0)
            return left + 1;
        else
            return n;
    }
}*/

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    ll n, poz = 0;
    cin >> n;
    ll a[n], b[n], diff[n];
    for(ll i = 0; i < n; i++)
        cin >> a[i];
    for(ll i = 0; i < n; i++){
        cin >> b[i];
        diff[i] = a[i] - b[i];
        if (diff[i] > 0) poz++;
    }

    sort(diff, diff + n);

    set < pair <ll, ll> > diffset;
    for (ll i = 0; i < n; i++)
        diffset.insert({diff[i],i});

    ll num = 0;
    for (ll i = 0; i < n; i++){
        if (diff[i] < 0){
            auto el = diffset.lower_bound({-diff[i] + 1, std::numeric_limits<ll>::min()});
            if (el != diffset.end()){
                //cout << (*el).fi << " " << (*el).se << '\n';
                num += (n - (*el).se);
            }
        }
        else if (diff[i] == 0){
            num += poz;
        }
        else{
            num += nCk(n - i, 2);
            break;
        }
    }

    cout << num;

    return 0;
}
