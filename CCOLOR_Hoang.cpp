#include <bits/stdc++.h>

using namespace std;
FILE *fi = freopen("CCOLOR.inp", "r", stdin);
FILE *fo = freopen("CCOLOR.out", "w", stdout);
const int nxm = 1e5 + 10;
int u[nxm], d[nxm], c[nxm], n, m, q, ans[nxm];
vector <int> g[nxm];
bool f[nxm][11];
void dfs(int u, int d, int c)
{
    if(d < 0 || f[u][d])
        return;
    f[u][d] = 1;
    if(!ans[u])
        ans[u] = c;
    for(auto v:g[u])
        dfs(v, d - 1, c);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> q;
    for(int i = 1; i <= q; i++)
        cin >> u[i] >> d[i] >> c[i];
    for(int i = q; i >= 1; i--)
        dfs(u[i], d[i], c[i]);
    for(int i = 1; i <= n; i++)
        cout << ans[i] << "\n";
    return 0;
}
