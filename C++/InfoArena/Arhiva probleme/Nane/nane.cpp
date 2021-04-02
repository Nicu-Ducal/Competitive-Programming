#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

const int maxN = 100005;
int n, k, a[maxN], l, r, b, bits[33];
ll ans;

int countBits(int bits[]) {
    int ans = 0;
    for (int i = 0; i <= 32; i++)
        if (bits[i])
            ans++;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("nane.in");
    ofstream cout("nane.out");

    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    l = 0;
    r = 0;
    while (r < n){
        b = 0;
        //Primul lucru: Adaugam a[right]
        for (int i = 1; i <= a[r]; i *= 2){
            if (a[r] & i)
                bits[b]++;
            b++;
        }

        //Verificam daca e ok numarul de biti, daca nu, scoatem pe rand a[left], a[left + 1], ...
        while (countBits(bits) > k){
            b = 0;
            for (int i = 1; i <= a[l]; i *= 2){
                if (a[l] & i)
                    bits[b]--;
                b++;
            }
            l++;
        }

        //Adaugam la solutie nr. de secvente
        ans += r - l + 1;

        //Trecem la urmatorul numar din dreapta
        r++;
    }

    cout << ans;

    return 0;
}
