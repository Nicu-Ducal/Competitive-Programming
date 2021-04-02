#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll cautbin(ll arr[], ll len, ll x)
{
    ll low = 0;
    ll high = len - 1;

    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            return mid + 1;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

ll cautbin0(ll arr[], ll len, ll x)
{
    ll low = 0;
    ll high = len - 1;

    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            while (arr[mid + 1] == arr [mid])
            {
                mid++;
            }
            return mid + 1;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

ll cautbin1(ll arr[], ll len, ll x)
{
    ll low = 0;
    ll high = len - 1;

    while (low < high)
    {
        ll mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            while (arr[mid + 1] == arr [mid])
            {
                mid++;
            }
            return mid + 1;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    //if (low = high)
    //{
        if (arr[low] == x){
            return low + 1;
        }
        if (arr[low] < x)
        {
            return low + 1;
        }
        else
        {
            return low;
        }
    //}
    return -1;
}

ll cautbin2(ll arr[], ll len, ll x)
{
    ll low = 0;
    ll high = len - 1;

    while (low < high)
    {
        ll mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            while (arr[mid - 1] == arr [mid])
            {
                mid--;
            }
            return mid + 1;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    //if (low == high)
    //{
        if (arr[low] == x){
            return low + 1;
        }
        if (arr[low] > x)
        {
            return low + 1;
        }
        else
        {
            return low + 2;
        }
    //}

    return -1;
}



int main()
{
    ifstream cin("cautbin.in");
    ofstream cout("cautbin.out");

    ll N;
    cin >> N;

    ll A[N];
    for (ll i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    ll num;
    cin >> num;

    ll caz, x;
    for (ll i = 0; i < num; i++)
    {
        cin >> caz >> x;
        if (caz == 0)
        {
            cout << cautbin0(A, N, x) << "\n";
        }
        else if (caz == 1)
        {
            cout << cautbin1(A, N, x) << "\n";
        }
        else if (caz == 2)
        {
            cout << cautbin2(A, N, x) << "\n";
        }
    }


    return 0;
}
