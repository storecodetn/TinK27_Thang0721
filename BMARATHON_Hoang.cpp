#include <bits/stdc++.h>

using namespace std;
const int nxm = 1e5 + 10;
FILE *fi = freopen("BMARATHON.inp", "r", stdin);
FILE *fo = freopen("BMARATHON.out", "w", stdout);
int t[nxm][18], depth[nxm], n, q;
vector <int> g[nxm];
void dfs(int u, int p)
{
    depth[u] = depth[p] + 1;
    t[u][0] = p;
    for(int i = 1; i <= 17; i++)
        t[u][i] = t[t[u][i - 1]][i - 1];
    for(auto v:g[u])
        if(v == p)
            continue;
        else
            dfs(v, u);
}
int lca(int u, int v)
{
    if(depth[u] < depth[v])
        swap(u, v);
    int diff = depth[u] - depth[v];
    for(int i = 0; i <= 17; i++)
        if((diff >> i) & 1)
            u = t[u][i];
    if(u == v)
        return u;
    for(int i = 17; i >= 0; i--)
        if(t[u][i] != t[v][i])
        {
            u = t[u][i];
            v = t[v][i];
        }
    return t[u][0];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    for(int i = 1; i <= q; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        int x = lca(u, w), y = lca(v, w), z = lca(u, v);
        if((lca(u, w) == w || lca(v, w) == w) && depth[z] <= max(depth[x], depth[y]))
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }
    return 0;
}
