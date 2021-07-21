#include <bits/stdc++.h>

using namespace std;
FILE *fi = freopen("CVOTREE.inp", "r", stdin);
FILE *fo = freopen("CVOTREE.out", "w", stdout);
const int nxm = 1e5 + 10;
int tree[4*nxm], depth[nxm], n, q, t[nxm][18];
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
void build(int node, int l, int r)
{
    if(l > r)
        return;
    if(l == r)
    {
        tree[node] = l;
        return;
    }
    int mid = (l + r)/2;
    build(node*2, l, mid);
    build(node*2 + 1, mid + 1, r);
    tree[node] = lca(tree[node*2], tree[node*2 + 1]);
}
int query(int node, int l, int r, int u, int v)
{
    if(l > r)
        return 0;
    if(l > v || r < u)
        return u;
    if(l >= u && r <= v)
        return tree[node];
    int mid = (l + r)/2;
    return lca(query(node*2, l, mid, u, v), query(node*2 + 1, mid + 1, r, u, v));
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
    build(1, 1, n);
    for(int i = 1; i <= q; i++)
    {
        int u, v;
        cin >> u >> v;
        cout << query(1, 1, n, u, v) << "\n";
    }
    return 0;
}
