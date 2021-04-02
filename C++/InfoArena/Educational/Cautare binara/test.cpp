#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll M, N;
ll arr[1000001];
ll quest[2];

ll cautbin0(ll x){
    ll lo = arr[0];
    ll hi = arr[N-1];
    ll mid;

    while(lo <= hi){
        mid = lo + (hi-lo)/2;
        if (arr[mid] == x){
            /*while (arr[mid] == arr[mid+1]){
                ++mid;
            }*/
            return mid+1;
        }
        else if (arr[mid] < x){
            lo = arr[mid]+1;
        }
        else if (arr[mid] > x){
            hi = arr[mid]-1;
        }
    }
    return -1;
}


int main(){

//ifstream cin("cautbin.in");
//ofstream cout("cautbin.out");


cin >> N;

for (ll i = 0; i < N; ++i){
    cin >> arr[i];
}

cin >> M;

for (ll i = 0; i<M; ++i){
    cin >> quest[0] >> quest[1]; //Vectorii cu 0 (1,2) x
    //cout << quest[0] << " " << quest[1] << "\n";
    if (quest[0] == 0){                                          //Cea mai mare poziție pe care se află un element cu valoarea lui x
        cout << cautbin0(quest[1]) << "\n";
    }
   /* else if (quest[0] == 1){
        cout << cautbin012(quest[0],quest[1]) << "\n";
    }
    else if (quest[0] == 2){
        cout << cautbin012(quest[0],quest[1]) << "\n";
    } */
}


return 0;
}
