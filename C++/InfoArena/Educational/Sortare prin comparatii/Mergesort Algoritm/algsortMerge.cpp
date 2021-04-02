#include <bits/stdc++.h>
typedef unsigned int ui;
typedef long long ll;
using namespace std;

void Merge(ll arr[], ll left, ll mid, ll right)
{
    ll i, j, k;
    ll n1 = mid - left + 1;
    ll n2 = right - mid;

    ll L[n1], R[n2];

    for (i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(ll arr[], ll left, ll right)
{
    if (left < right)
    {
        ll mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        Merge(arr, left, mid, right);
    }
}

int main(){

ifstream cin("algsort.in");
ofstream cout("algsort.out");

ll N;
cin >> N;

ll A[N];
for (ll i = 0; i < N; ++i){
    cin >> A[i];
}

int left = 0;
int right = N-1;

mergeSort(A, left, right);

for (ll i = 0; i < N; ++i){
    cout << A[i] << " ";
}

return 0;
}
