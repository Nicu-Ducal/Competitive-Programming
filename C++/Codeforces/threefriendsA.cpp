#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll a, b, c, q;
ll dist;
ll t[3];

int main()
{
    cin >> q;
    while(q--)
    {
        dist = 0;
        cin >> t[0] >> t[1] >> t[2];
        sort(t, t + 3);

        if (t[0] == t[1] && t[1] == t[2]){
            cout << dist << "\n";
            continue;
        }
        if (t[0] == t[1] || t[1] == t[2]){
            if (t[0] == t[1])
            {
                t[2]--;
                if (t[2] - t[1] >= 1){
                t[0]++; t[1]++;
                dist = 2 * abs(t[2] - t[1]);
                cout << dist << "\n";
                continue;
                }
                cout << "0\n";
                continue;
            }
            t[0]++;
                if (t[1] - t[0] >= 1)
                {
                t[1]--; t[2]--;
                dist = 2 * abs(t[1] - t[0]);
                cout << dist << "\n";
                continue;
                }
                cout << "0\n";
                continue;
        }
        t[0]++; t[2]--;
        dist = abs(t[1] - t[0]) + abs(t[2] - t[1]) + abs(t[2] - t[0]);
        cout << dist << "\n";
    }


    return 0;
}
