#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,q;
int d[maxn];
int p[maxn][19];
vector <int> g[maxn];
void open()
{
    freopen("CTREEQ.inp","r",stdin);
    freopen("CTREEQ.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}
void dfs(int u,int pa)
{
    d[u]=d[pa]+1;
    p[u][0]=pa;
    for(int v:g[u])
        if(pa!=v) dfs(v,u);
}
int lca(int u,int v)
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
    return d[begin_u]+d[begin_v]-2*d[u];
}
int main()
{
    open();
    int u,v,a,b,k;
    int d1,d2,d3,res;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,1);
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i<=n;i++)
            p[i][j]=p[p[i][j-1]][j-1];
    cin>>q;
    while(q--)
    {
        res=2e9;
        cin>>u>>v>>a>>b>>k;
        d1=lca(a,b);
        d2=lca(a,u) + lca(b,v) + 1;
        d3=lca(a,v) + lca(b,u) + 1;
        if(d1%2 == k%2) res=min(res,d1);
        if(d2%2 == k%2) res=min(res,d2);
        if(d3%2 == k%2) res=min(res,d3);
        if(res<=k && res!=2e9) cout<<"1\n";
        else cout<<"0\n";
    }
}
