#include <bits/stdc++.h>
using namespace std;

int ciurNum(int N){
    int num = 0;
    bool ciur[N+1];
    for (int i = 0; i<N+1; ++i){
        if (i == 0 || i == 1){
            ciur[i] = 0;
        } else {
            ciur[i] = 1;
        }
    }

    for (int i = 2; i <= N; i++){
        if (ciur[i] == 1){
            num++;
            for (int j = 2*i; j <= N; j += i){
                ciur[j] = 0;
            }
        }
    }
    return num;
}

int main(){

ifstream cin("ciur.in");
ofstream cout("ciur.out");

int N;
cin >> N;

cout << ciurNum(N);


return 0;
}
