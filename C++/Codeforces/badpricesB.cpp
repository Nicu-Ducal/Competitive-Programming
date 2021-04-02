#include <bits/stdc++.h>
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll t, n;

int main(){
ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

cin >> t;
while (t--)
{
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    stack <int> s;
    ll d = 0;
    s.push(a[0]);
    for (int i = 1; i < n; i++)
    {
        int curr = s.top();
        if (a[i] >= curr)
        {
            s.push(a[i]);
            continue;
        }
        if (a[i] < curr)
        {
            while (a[i] < curr && !s.empty())
            {
                d++;
                s.pop();
                if (!s.empty()) curr = s.top();
            }
            s.push(a[i]);
        }
    }
    cout << d << "\n";

}
return 0;
}
