#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll n, a[1005], sum = 0, pr3, last3, pr1, pr2, first1, first2;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("expresie.in");
    ofstream cout("expresie.out");

    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    pr3 = a[0] * a[1] * a[2];
    last3 = 2;
    for (ll i = 3; i < n; i++)
    {
        if (a[i] * a[i - 1] * a[i - 2] > pr3)
        {
            pr3 = a[i] * a[i - 1] * a[i - 2];
            last3 = i;
        }
        else if (a[i] * a[i - 1] * a[i - 2] == pr3 && (a[i] + a[i - 1] + a[i - 2] < a[last3] + a[last3 - 1] + a[last3 - 2]))
            last3 = i;
    }
    //cout << sum - a[last3] - a[last3 - 1] - a[last3 - 2] + pr3;
    for (ll i = 0; i < n; i++)
    {
        if (a[i] * a[i + 1] > pr1)
        {
            pr1 = a[i] * a[i + 1];
            first1 = i;
        }
        else if (a[i] * a[i + 1] >= pr2)
        {
            pr2 = a[i] * a[i + 1];
            first2 = i;
        }
    }
    //cout << pr1 << " " << pr2 << " ";
    cout << max(sum - a[first1] - a[first1 + 1] - a[first2] - a[first2 + 1] + pr1 + pr2, sum - a[last3] - a[last3 - 1] - a[last3 - 2] + pr3);

    return 0;
}
