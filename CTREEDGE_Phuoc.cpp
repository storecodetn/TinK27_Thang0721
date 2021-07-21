#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
const int maxn=2e5+10;
int n,q;
int d[maxn];
int p[maxn][19];
long long f[maxn],dis[maxn];
vector <ii> g[maxn];
void open()
{
    freopen("CTREEDGE.inp","r",stdin);
    freopen("CTREEDGE.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}
void dfs(int u,int pa)
{
    p[u][0]=pa;
    d[u]=d[pa]+1;
    for(auto [w,v]:g[u])
        if(pa!=v)
        {
            dis[v]=dis[u]+w;
            dfs(v,u);
            f[u]=max(f[u],f[v]+w);
        }
}
long long lca(int u,int v)
{
    int begin_u=u,begin_v=v;
    if(d[u]>d[v]) swap(u,v);
    for(int j=17;j>=0;j--)
        if(d[p[v][j]]>= d[u]) v=p[v][j];
    for(int j=17;j>=0;j--)
        if(p[u][j]!=p[v][j])
        {
            u=p[u][j];
            v=p[v][j];
        }
    while(u!=v)
    {
        u=p[u][0];
        v=p[v][0];
    }
    return dis[begin_u]+dis[begin_v]-2*dis[u];
}
int main()
{
    open();
    int u,v,w;
    long long res1,res2;
    cin>>n>>q;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v>>w;
        g[u].push_back({w,v});
        g[v].push_back({w,u});
    }
    dfs(1,1);
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i<=n;i++)
            p[i][j]=p[p[i][j-1]][j-1];
    while(q--)
    {
        cin>>u>>v>>w;
        res1=f[u]+f[v]+w;
        res2=lca(u,v);
        cout<<max(res1,res2)<<"\n";
    }
}
