#include <bits/stdc++.h>
using namespace std;


int main(){

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int a, b;
cin >> a >> b;

int v1[a], v2[b];
for (int i = 0; i<a; ++i){
    cin >> v1[i];
}

for (int i = 0; i<b; ++i){
    cin >> v2[i];
}
/* Verficarea vectorilor
for (int i = 0; i<a; ++i){
    cout << v1[i] <<" ";
}
cout << "\n";

for (int i = 0; i<b; ++i){
    cout << v2[i] <<" ";
}
cout << "\n";
*/
int matrix[b+1][a+1];
for (int i = 0; i<=b; ++i){
    matrix[i][0] = 0;
}
for (int i = 0; i<=a; ++i){
    matrix[0][i] = 0;
}

for (int i = 1; i <= b; i++){
    for (int j = 1; j <= a; j++){
        if (v2[i-1] == v1[j-1]){
            matrix[i][j] = matrix[i-1][j-1]+1;
        } else{
            matrix[i][j] = max(matrix[i][j-1], matrix[i-1][j]);
        }
    }
}
int n = matrix[b][a];
int m = matrix[b][a];
int LCS[m];
int i = b;
int j = a;

while (m != 0){
        if (v2[i-1] == v1[j-1]){
            LCS[m-1] = v1[j-1];
            --m;
            --i;
            --j;
            continue;
        }
        if (matrix[i][j-1] > matrix[i-1][j]){
           --j;
           continue;
        }
        else {
            --i;
            continue;
        }
}

cout << n << "\n";
for (int i = 0; i<n; ++i){
    cout << LCS[i] << " ";
}

/* Afisarea matricei, verificare
 for (int i = 0; i<=b; i++){
    for (int j = 0; j<=a; j++){
        cout << matrix[i][j] <<" ";
    }
    cout << "\n";
}
*/

return 0;
}
