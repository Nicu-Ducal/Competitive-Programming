#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

const int maxN = 100005;
int n, a[maxN], b[maxN], poz[maxN], x;
ll swaps = 0;

void interclasare(int a[], int left, int mid, int right){
    int i = left;
    int j = mid + 1;
    int index = left;

    while (i <= mid && j <= right){
        if (a[i] < a[j]){
            poz[index] = a[i];
            index++; i++;
        }
        else{
            poz[index] = a[j];
            index++; j++;
            swaps += (ll) (mid - i + 1);
        }
    }

    while(i <= mid){
        poz[index] = a[i];
        index++; i++;
    }

    while(j <= right){
        poz[index] = a[j];
        index++; j++;
    }

    for (int i = left; i <= right; i++)
        a[i] = poz[i];
}

void mergesort(int a[], int left, int right){
    if (left < right){
        int mid = left + (right - left) / 2;
        mergesort(a, left, mid);
        mergesort(a, mid + 1, right);
        interclasare(a, left, mid, right);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("permutariab.in");
    ofstream cout("permutariab.out");

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        poz[a[i]] = i;
    }
    for (int i = 1; i <= n; i++){
        cin >> x;
        b[i] = poz[x];
    }

    mergesort(b, 1, n);
    cout << swaps;

    return 0;
}
