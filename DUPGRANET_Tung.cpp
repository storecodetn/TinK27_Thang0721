#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<tuple<long long,int,int> > e;
long long n,m,r[N],level[N],cha[N],p[N][30],t[N][30];
vector<pair<int,long long> > a[N];
bool cmp(tuple<long long,int,int> x,tuple<long long,int,int> y)
{
    return get<0>(x)>get<0>(y);
}
void dfs(int u,int k)
{
    level[u]=k;
    for(auto v:a[u])
        if(level[v.first]==0)
            {
                dfs(v.first,k+1);
                cha[v.first]=u;
                t[v.first][0]=v.second;
            }
}
long long lca(int x,int y)
{
    long long ans=INT_MAX;
    if(level[y]>level[x])
        swap(x,y);
    for(int i=20;i>=0;i--)
        if((level[x]-(1<<i))>=level[y])
            {
                ans=min(t[x][i],ans);
                x=p[x][i];
            }
    if(x==y)
        return ans;
    for(int i=20;i>=0;i--)
        if(p[x][i]!=p[y][i] && p[x][i]!=-1)
    {
        ans=min({ans,t[x][i],t[y][i]});
        x=p[x][i];
        y=p[y][i];
    }
    ans=min({ans,t[x][0],t[y][0]});
    return ans;


}
int root(int u)
{
    while(r[u]!=u)
        {
            r[u]=r[r[u]];
            u=r[u];
        }
    return u;
}
void krus()
{
    sort(e.begin(),e.end(),cmp);
    for(int i=0;i<m;i++)
    {
        int ru=root(get<1>(e[i]));
        int rv=root(get<2>(e[i]));
        if(rv!=ru)
        {
            r[rv]=ru;
            a[get<1>(e[i])].push_back({get<2>(e[i]),get<0>(e[i])});
            a[get<2>(e[i])].push_back({get<1>(e[i]),get<0>(e[i])});
        }
    }
}
int main()
{
    freopen("DUPGRANET.INP","r",stdin);
    freopen("DUPGRANET.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        long long u,v,w;
        cin>>u>>v>>w;
        e.push_back(make_tuple(w,u,v));
    }
    for(int i=1;i<=n;i++)
        r[i]=i;
    krus();
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
                    t[j][i]=min(t[j][i-1],t[p[j][i-1]][i-1]);
                }
    long long res=0;
    for(int i=0;i<m;i++)
    {
        int u=get<1>(e[i]);
        int v=get<2>(e[i]);
        res+=lca(u,v)-get<0>(e[i]);
    }
    cout<<res;
}
