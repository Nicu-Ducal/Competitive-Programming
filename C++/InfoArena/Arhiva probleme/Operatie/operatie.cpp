#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << "\n"
#define all(x) (x).begin(),(x).end()
#define len(x) (x).length()
#define size(x) (x).size()
#define sqr(x) (x) * (x)
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>

using ull = unsigned long long;
using ll = long long;
using namespace std;

template <typename T>
ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template <typename A, typename B>
ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

const int INF = INT_MAX, maxB = 30, maxN = 1010;
int t, n, b;
int v[maxN], w[maxN][maxN];
int bits1[maxB], bits2[maxB], bits3[maxB];

void makeBits(int a[], int n) {
    for (int p = 0, bz = 1; p < b; p++, bz <<= 1) {
        if (n & bz)
            a[p] = 1;
        else
            a[p] = 0;
    }
}

int makeNum(int a[]) {
    int ans = 0;
    for (int p = 0, bz = 1; p < b; p++, bz <<= 1) {
        if (a[p])
            ans += bz;
    }
    return ans;
}

int findLeft(int num1[], int num2[], int num3[]) {
    for (int i = 0; i < b; i++) {
        if (num2[i] == 0) {
            num1[i] = num3[i] ^ 1;
        }
        else if (num2[i] == 1 and num3[i] == 0) {
            return -1;
        }
        else {
            num1[i] = -1;
        }
        //cout << num1[i];
    }
    //cout << "\n";
    return 1;
}

int findRight(int num1[], int num2[], int num3[]) {
    for (int i = 0; i < b; i++) {
        if (num1[i] == 1) {
            if (num2[i] == -1)
                num2[i] = num3[i];
            else if (num2[i] != num3[i])
                return -1;
        }
        else if (num1[i] == 0) {
            if (num3[i] == 0)
                return -1;
        }
        //cout << num1[i];
    }
    //cout << "\n";
    return 1;
}

int implica(int num1, int num2) {
    int ans = 0;
    for (int p = 0, bz = 1; p < b; p++, bz <<= 1) {
        int bit1, bit2;
        if (num1 & bz)
            bit1 = 1;
        else
            bit1 = 0;

        if (num2 & bz)
            bit2 = 1;
        else
            bit2 = 0;

        if (bit2 == 1 or bit1 == 0)
            ans += bz;
    }
    return ans;
}

bool check() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i + j) % 4 == 0) {
                if (w[i][j] != (v[i] ^ v[j]))
                    return 0;
            } else if ((i + j) % 4 == 2) {
                if (w[i][j] != (v[i] & v[j]))
                    return 0;
            } else {
                if (w[i][j] != implica(v[i], v[j]))
                    return 0;
            }
        }
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ifstream cin("operatie.in");
    ofstream cout("operatie.out");

    cin >> n >> b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> w[i][j];
            if ((i + j) % 4 == 2 and i == j) {
                v[i] = w[i][j];
            }
        }
    }
    for (int i = 0; i < n; i += 2) {
        makeBits(bits2, v[1]);
        makeBits(bits3, w[i][1]);

        if (findLeft(bits1, bits2, bits3) == -1) {
            cout << -1;
            return 0;
        }
        makeBits(bits3, w[1][i]);
        if (findRight(bits2, bits1, bits3) == -1) {
            cout << -1;
            return 0;
        }

        v[i] = makeNum(bits1);
    }

    if (!check()) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }

    return 0;
}
