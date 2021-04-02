#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << "\n"
#define all(x) (x).begin(),(x).end()
#define len length()
#define sz size()
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>

using ull = unsigned long long;
using ll = long long;
using namespace std;

const int INF = INT_MAX;
ll t, n, p;

string a[205];
bool good[205];

bool isSubstring(string a, string b){
    if (a.len > b.len or (a.len == b.len and a != b))
        return 0;
    int i = 0, j = 0;
    while (i < b.len and j < a.len){
        if (b[i] == a[j])
            j++;
        i++;
    }
    return j == a.len;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("interesant.in");
    ofstream cout("interesant.out");

    cin >> p >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    if (p == 1){
        string mx = "";
        for (int i = 0; i < n; i++){
            if (a[i].len > mx.len or (a[i].len == mx.len and a[i] < mx))
                mx = a[i];
        }
        cout << mx;
    } else {
        //sort(a, a + n, [](string a, string b) { return a.len < b.len; });
        int ans = 0;
        for (int i = 0; i < n; i++){
            bool ok = 1;
            for (int j = 0; j < n; j++){
                if (i != j and isSubstring(a[i], a[j])){
                    ok = 0; break;
                }
            }
            if (ok) good[i] = true, ans++;
        }
        cout << ans << "\n";
        for (int i = 0; i < n; i++)
            if (good[i]) cout << a[i] << "\n";
    }
    return 0;
}
