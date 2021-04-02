#include <bits/stdc++.h>
typedef unsigned int ui;
typedef long long ll;
using namespace std;

void Swap (ll* a, ll* b)
{
    ll t = *a;
    *a = *b;
    *b = t;
}

ll Partition(ll arr[], ll low, ll high)
{
    ll pivot = arr[high];
    ll i = low - 1;

    for (ll j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            Swap(&arr[i], &arr[j]);
        }
    }
    Swap(&arr[i+1], &arr[high]);
    return (i + 1);
}

void quickSort(ll arr[], ll low, ll high)
{
    if (low < high)
    {
        ll pi = Partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(){

ifstream cin("algsort.in");
ofstream cout("algsort.out");

ll N;
cin >> N;

ll A[N];

for (ll i = 0; i < N; i++)
{
    cin >> A[i];
}

shuffle(A, A+N, default_random_engine(0));

quickSort(A, 0, N - 1);

for (ll i = 0; i < N; i++)
{
    cout << A[i] << " ";
}


return 0;
}
