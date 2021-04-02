#include <bits/stdc++.h>
typedef unsigned int ui;
typedef long long ll;
using namespace std;

int a[20], n;
int ind = 0;

void thanosSort(int left, int right)
{
     if (is_sorted(a + left, a + right))
        {
            ind = max (ind , right - left);
        }
        else
        {
            int mid = left + (right - left) / 2;
            thanosSort(left, mid);
            thanosSort(mid, right);
        }
}

int main(){
ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
//ifstream cin(".in");
//ofstream cout(".out");

cin >> n;
for (int i = 0; i < n; i++)
{
    cin >> a[i];
}

thanosSort(0, n);
cout << ind;

return 0;
}
