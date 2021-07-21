#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,q,cha[N],p[N][30];
long long level[N],d[N],t[N][30];
vector<pair<int,long long> > a[N];
void dfs(int u,int k)
{
    level[u]=k;
    for(auto v:a[u])
        if(level[v.first]==0)
            {
                dfs(v.first,k+1);
                cha[v.first]=u;
                t[v.first][0]=v.second;
                d[u]=max(d[u],v.second+d[v.first]);
            }
}
long long lca(int x,int y)
{
    long long ans=0;
    if(level[y]>level[x])
        swap(x,y);
    for(int i=20;i>=0;i--)
        if((level[x]-(1<<i))>=level[y])
            {
                ans+=t[x][i];
                x=p[x][i];
            }
    if(x==y)
        return ans;
    for(int i=20;i>=0;i--)
        if(p[x][i]!=p[y][i] && p[x][i]!=-1)
    {
        ans+=t[x][i];
        ans+=t[y][i];
        x=p[x][i];
        y=p[y][i];
    }
    ans+=t[x][0]+t[y][0];
    return ans;


}
int main()
{
    freopen("CTREEDGE.inp","r",stdin);
    freopen("CTREEDGE.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<n;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }
    dfs(1,1);
    cha[1]=-1;
    for(int i=0;i<=20;i++)
        for(int j=1;j<=n;j++)
            p[j][i]=-1;
    for(int i=1;i<=n;i++)
        p[i][0]=cha[i];
    for(int i=1;i<=20;i++)
        for(int j=1;j<=n;j++)
            if(p[j][i-1]!=-1)
                {
                    p[j][i]=p[p[j][i-1]][i-1];
                    t[j][i]=t[j][i-1]+t[p[j][i-1]][i-1];
                }
    for(int i=1;i<=q;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        cout<<max(lca(u,v),d[v]+d[u]+w)<<"\n";
    }


}
