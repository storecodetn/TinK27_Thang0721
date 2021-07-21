#include <bits/stdc++.h>
using namespace std;

const int nmax=1e5+1;
int n,d[nmax],t[nmax][18];
vector<int> a[nmax];
long long res;
//-------------
void dfs(int u,int p)
{
    d[u]=d[p]+1;
    t[u][0]=p;
    for (int i=1;i<=17;i++)
        t[u][i]=t[t[u][i-1]][i-1];
    for (auto v:a[u])
    {
        if (v!=p)
            dfs(v,u);
    }
}
//-----------
int lca(int u,int v)
{
    if (d[u]<d[v])
        swap(u,v);
    int diff=d[u]-d[v];
    for (int i=0;i<=17;i++)
        if ((diff>>i)&1)
            u=t[u][i];
    if (u==v)
        return u;
    for (int i=17;i>=0;i--)
        if (t[u][i]!=t[v][i])
        {
            u=t[u][i];
            v=t[v][i];
        }
    return t[u][0];
}
//---------
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("btourist.inp","r",stdin);
    freopen("btourist.out","w",stdout);
    cin>>n;
    for (int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)
        for (int j=2*i;j<=n;j+=i)
    {
        int t=lca(i,j);
        res+=d[i]+d[j]-2*d[t]+1;
    }
    cout<<res;
    return 0;
}
