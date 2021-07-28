#include <bits/stdc++.h>

using namespace std;
FILE *fi = freopen("CAID.inp", "r", stdin);
FILE *fo = freopen("CAID.out", "w", stdout);
const int nxm = 1e3 + 10;
int n, k, s, p[nxm], d[nxm];
vector <int> g[nxm], ans, path;
bool f[nxm];
void dfs(int u)
{
    if(d[u] > d[s] && d[u] <= k)
        s = u;
    for(auto v:g[u])
    {
        d[v] = d[u] + 1;
        dfs(v);
    }
}
void dfs2(int u)
{
    ans.push_back(u);
    for(auto v:g[u])
        if(!f[v] && k > 0)
        {
            k--;
            dfs2(v);
            ans.push_back(u);
        }
}
void solve()
{
    cin >> n >> k;
    for(int i = 0; i <= n; i++)
    {
        g[i].clear();
        p[i] = 0;
        f[i] = 0;
    }
    ans.clear();
    path.clear();
    for(int i = 1; i <= n - 1; i++)
    {
        cin >> p[i + 1];
        g[p[i + 1]].push_back(i + 1);
    }
    d[1] = 1;
    s = 1;
    dfs(s);
    k -= d[s];
    int u = s;
    while(u)
    {
        path.push_back(u);
        f[u] = 1;
        u = p[u];
    }
    reverse(path.begin(), path.end());
    for(int i = 0; i < path.size(); i++)
        dfs2(path[i]);
    cout << ans.size() - 1 << "\n";
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
