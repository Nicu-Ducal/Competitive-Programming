#include <bits/stdc++.h>
typedef unsigned int ui;
typedef long long ll;
using namespace std;

int N, M, S;
int dist[100005];
bool viz[100005];

vector <int> V[100005];
queue <int> Q;


int main(){

ifstream cin("bfs.in");
ofstream cout("bfs.out");

cin >> N >> M >> S;
//N varfuri, M arce


for (int i = 1; i <= N; i++)
{
    dist[i] = -1;
}


int a, b;

for (int i = 0; i < M; i++)
{
    cin >> a >> b;
    V[a].push_back(b);
    //V[b].push_back(a); //pentru ca e orientat
}

Q.push(S);
dist[S] = 0;
viz[S] = 1;
while (!Q.empty())
{
    int curr = Q.front();
    Q.pop();
   // cout << curr << " ";

    for (int i = 0; i < V[curr].size(); i++)
    {
        if (!viz[V[curr][i]])
        {
            Q.push(V[curr][i]);
            viz[V[curr][i]] = 1;
            dist[V[curr][i]] = dist[curr] + 1;
        }
    }
}

for (int i = 1; i <= N; i++)
{
    cout << dist[i] << " ";
}






return 0;
}
