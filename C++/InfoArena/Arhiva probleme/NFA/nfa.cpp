#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define len length()
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll t, n, m, k, q0, st1, st2, Q;
unordered_set<int> fin;
char ch;
vector<int> delta[305][30];
string word;
bool accepted;

void check(string word, int pos, int st){
    if (accepted)
        return;

    if (pos == word.length()){
        if (fin.find(st) != fin.end())
            accepted = 1;
        return;
    }

    if (delta[st][word[pos] - 'a'][0] == -1)
        return;

    for (auto &stare: delta[st][word[pos] - 'a']){
        check(word, pos + 1, stare);
    }
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("nfa.in");
    ofstream cout("nfa.out");

    for (int i = 0; i <= 301; i++){
        for (int j = 0; j <= 26; j++)
            delta[i][j].resize(1, -1);
    }

    cin >> n >> m >> k >> q0;
    for (int i = 0; i < k; i++){
        cin >> t;
        fin.insert(t);
    }

    for (int i = 0; i < m; i++){
        cin >> st1 >> st2 >> ch;
        if (delta[st1][ch - 'a'].size() == 1 and delta[st1][ch - 'a'][0] == -1)
            delta[st1][ch - 'a'][0] = st2;
        else
            delta[st1][ch - 'a'].pb(st2);
    }

    cin >> Q;
    while(Q--){
        cin >> word;
        accepted = 0;
        check(word, 0, q0);
        if (accepted)
            cout << "1\n";
        else
            cout << "0\n";
    }

    return 0;
}
