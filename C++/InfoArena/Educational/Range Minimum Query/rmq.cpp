#include <iostream>
#include <fstream>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

const int maxN = 1e5 + 10;
int n, m, a[maxN], sparce[maxN][17], x, y;
int log2[maxN];

int RMQ(int i, int j){
    int l = j - i + 1;
    int k = log2[l];
    return min(a[sparce[i][k]], a[sparce[i + l - (1 << k)][k]]);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("rmq.in");
    ofstream cout("rmq.out");

    log2[1] = 0;
    for (int i = 2; i < maxN; i++)
        log2[i] = 1 + log2[i / 2];

    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sparce[i][0] = i;
    }

    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 0; i + (1 << j) - 1 < n; i++){
            if (a[sparce[i][j - 1]] < a[sparce[i + (1 << (j - 1))][j - 1]])
                sparce[i][j] = sparce[i][j - 1];
            else
                sparce[i][j] = sparce[i + (1 << (j - 1))][j - 1];
        }

    for (int query = 0; query < m; query++){
        cin >> x >> y;
        cout << RMQ(--x, --y) << "\n";
    }

    return 0;
}
