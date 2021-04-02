#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

bool isPrime[100010];
void Prime()
{
    for (ll i = 0; i < 100010; i++)
        isPrime[i] = 1;
    isPrime[0] = isPrime[1] = 0;
    for (ll i = 2; i < 100010; i++)
        if (isPrime[i])
            for (ll j = 2 * i; j < 100010; j += i)
                isPrime[j] = 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    Prime();
    ll n, m, t, sum;
    cin >> n >> m;
    ll l[n][m];
    ll min = 1e9;
    for (ll i = 0; i < n; i++)
    {
        sum = 0;
        for (ll j = 0; j < m; j++)
        {
            cin >> t;
            for (int k = t;;k++)
                if(isPrime[k])
                {
                    l[i][j] = k - t;
                    break;
                }
            sum += l[i][j];
        }
        if (sum < min) min = sum;
    }
    for (ll i = 0; i < m; i++)
    {
        sum = 0;
        for (ll j = 0; j < n; j++)
            sum += l[j][i];
        if (sum < min) min = sum;
    }


    cout << min;
    return 0;
}

/* Python:
def isPrime(n):
    if n == 2:
        return True
    if n % 2 == 0 or n == 1 or n == 0 or n < 0:
        return False
    for i in range(3, int((n ** 0.5)) + 1, 2):
        if n % i == 0:
            return False
    return True

n, m = map(int, input().split())
l = []
for i in range(n):
    l.append([int(x) for x in input().split()])

mtxsum = [[0 for i in range(m)] for j in range(n)]

for i in range(n):
    for j in range(m):
        init = l[i][j]
        if not isPrime(l[i][j]):
            while isPrime(l[i][j]) != True:
                if l[i][j] == 1:
                    l[i][j] += 1
                elif l[i][j] % 2 == 0:
                    l[i][j] += 1
                else:
                    l[i][j] += 2
        mtxsum[i][j] = (l[i][j] - init)

s = 10000000000
for i in range(n):
    if s > sum(mtxsum[i]):
        s = sum(mtxsum[i])

for j in range(m):
    temp = 0
    for i in range(n):
        temp += mtxsum[i][j]
    if s > temp:
        s = temp

print(s)
*/
