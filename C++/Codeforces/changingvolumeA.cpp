#include <bits/stdc++.h>
typedef unsigned int ui;
typedef long long ll;
using namespace std;

int T, a, b;
int rem[3] = {1,2,5};

int main(){
ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

cin >> T;
for (int i = 0; i < T; i++)
{
    cin >> a >> b;
    int num = 0;
    int ab = abs(a - b);
        for (int j = 2; j >= 0; j--)
        {
            int d = ab / rem[j];
            if (d > 0 && (ab-d*rem[j]) >= 0)
            {
                ab -= d*rem[j];
                num += d;
            }
            if (ab == 0) break;
        }
    cout << num << "\n";
}



return 0;
}
