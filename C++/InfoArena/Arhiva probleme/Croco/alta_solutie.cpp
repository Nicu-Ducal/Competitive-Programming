#include <bits/stdc++.h>
using namespace std;

ifstream fin("croco.in");
ofstream fout("croco.out");

class Graph {
private:
  int n, s, t;
  vector<vector<int>> ad, cap, cpy;

  bool bfs(vector<int>& father) {
    fill(father.begin(), father.end(), -1);
    father[s] = -10;
    queue<int> q; q.push(s);
    while (!q.empty()) {
      int node = q.front(); q.pop();
      for (int nghb : ad[node])
        if (father[nghb] == -1 && cap[node][nghb]) {
          father[nghb] = node;
          if (nghb != t)
            q.push(nghb);
        }
    }
    return father[t] != -1;
  }

  void dfs(int node, vector<bool>& vis) {
    vis[node] = true;
    for (int nghb : ad[node])
      if (!vis[nghb] && cap[node][nghb])
        dfs(nghb, vis);
  }

public:
  int flux;
  Graph(int n) :
          n(n), s(1), ad(n + 1),
          cpy(n + 1, vector<int>(n + 1)) { }

  void addEdge(int x, int y, int z) {
    ad[x].push_back(y);
    cpy[x][y] = z;
  }

  int maxFlow() {
    cap = cpy;
    vector<bool> vis(n + 1);
    vector<int> father(n + 1);
    int maxFlow = 0;
    while (bfs(father))
      for (int nghb : ad[t])
        if (father[nghb] != -1 && cap[nghb][t]) {
          int flow = 1e9;
          father[t] = nghb;
          for (int i = t; i != s; i = father[i])
            flow = min(flow, cap[father[i]][i]);
          for (int i = t; i != s; i = father[i]) {
            cap[father[i]][i] -= flow;
            cap[i][father[i]] += flow;
          }
          maxFlow += flow;
        }
    return maxFlow;
  }

  vector<int> minCut() {
    int best = 1e9, idx = n;
    for (int i = 2; i <= n; i++) {
      t = i;
      int cur_flow = maxFlow();
      if (cur_flow < best) {
        best = cur_flow;
        idx = i;
      }
    }
    t = idx;
    vector<int> cut;
    flux = maxFlow();

    vector<bool> vis(n + 1);
    dfs(s, vis);
    for (int i = 1; i <= n; i++)
      if (vis[i])
        cut.push_back(i);
    return cut;
  }
};

int main() {
  int n; fin >> n;
  Graph graph(n);
  int sum = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      int x; fin >> x; sum += x;
      if (x) graph.addEdge(i, j, x);
    }

  auto cut = graph.minCut();
  fout << sum / 2 - graph.flux << ' ' << cut.size() << '\n';
  for (int node : cut)
    fout << node << ' ';
  fout << '\n';

  fout.close();
  return 0;
}