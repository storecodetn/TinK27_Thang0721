#include <bits/stdc++.h>
using namespace std;
FILE *fi = freopen("BMARATHON.inp", "r", stdin);
FILE *fo = freopen("BMARATHON.out", "w", stdout);
const int maxn = 1e5+10;
int n, q;
int depth[maxn], T[maxn][17], par[maxn];
vector<int> g[maxn];

void dfs(int u, int p)
{
  depth[u] = depth[p] + 1;
  T[u][0]=p;
  for (int i=1; i<17; i++)
    T[u][i] = T[T[u][i-1]][i-1];
  for (auto v: g[u])
  {
    if(v == p) continue;
    dfs(v, u);
  }
}

int Lca(int u, int v)
{
  if(depth[u] < depth[v])
    swap(u, v);
  int diff = depth[u] - depth[v];
  for (int i=0; i<17; i++)
    if((diff>>i)&1)
      u = T[u][i];
  if(u == v) return u;
  for (int i=16; i>=0; i--)
  {
    if(T[u][i] != T[v][i])
    {
      u = T[u][i];
      v = T[v][i];
    }
  }
  return T[u][0];
}

int dist(int u, int v)
{
  return depth[u] + depth[v] - 2*(depth[Lca(u,v)]);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  cin>>n>>q;
  for (int i=1; i<n; i++)
  {
    int u, v;
    cin>>u>>v;
    par[v] = 1;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i=1; i<=n; ++i)
  if(par[i] == 0)
    {
      dfs(i, 0);
      break;
    }
  while(q--)
  {
    int u, v, w;
    cin>>u>>v>>w;
    if(dist(u, v) == dist(u, w) + dist(v, w))
      cout<<1;
    else cout<<0;
    cout<<"\n";
  }
  return 0;
}