#include <bits/stdc++.h>
using namespace std;
int t,n,k,deg[2001],Max,x,h[2001];
vector<int> a[1001],ans;
bool f[1001];
void truy(int u,int par)
{
    if(x==0)
        return;
    ans.push_back(u);
    if(x==1)
        return;
    for(auto v:a[u])
        if(v!=par)
            {
                x--;
                truy(v,u);
                if(x==1)
                    break;
            }
    ans.push_back(u);
}
void truy3(int u,int par)
{
    if(x==0)
        return;
    ans.push_back(u);
    if(x==1)
        return;
    for(auto v:a[u])
        if(v!=par)
            {
                x--;
                truy3(v,u);
                if(x==1)
                    break;
            }
}
void truy2(int u,int par,int y)
{
    Max=0;
    for(auto v:a[u])
            if(h[Max]<h[v] && v!=par)
                Max=v;
        deg[Max]=min(deg[Max],k);
        ans.push_back(u);
         for(auto v:a[u])
            if(v!=Max && v!=par)
            {
                if(k<=0)
                    break;
                x=min(k,deg[v]);
                truy(v,u);
                ans.push_back(u);
                k-=deg[v];

            }
        if(h[Max]<deg[Max])
            truy2(Max,u,y-1);
        else
        {
            x=min(h[Max],deg[Max]);
                truy3(Max,deg[Max]);
     }

}
void dfs(int u)
{
    f[u]=true;
    deg[u]=1;
    h[u]=1;
    for(auto v:a[u])
     if(!f[v])
     {
         dfs(v);
         deg[u]+=deg[v];
         h[u]=max(h[u],h[v]+1);
     }
     if(u==1)
     {
         for(auto v:a[u])
            if(h[Max]<h[v])
                Max=v;
        deg[Max]=min(deg[Max],k);
        k-=h[Max];
        ans.push_back(u);
         for(auto v:a[u])
            if(v!=Max)
            {
                if(k<=0)
                    break;
                x=min(k,deg[v]);
                truy(v,u);
                ans.push_back(u);
                k-=deg[v];

            }
        x=deg[Max];
        if(h[Max]<deg[Max])
            truy2(Max,u,x);
        else
        {
            x=min(h[Max],deg[Max]);
            truy3(Max,u);
     }
     }
}
int main()
{
    freopen("CAID.inp","r",stdin);
    freopen("CAID.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        Max=0;
        k--;
        for(int i=1;i<n;i++)
        {
            int x;
            cin>>x;
            a[x].push_back(i+1);
            a[i+1].push_back(x);
        }
        dfs(1);
        cout<<ans.size()-1<<"\n";
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
        for(int i=1;i<=n;i++)
        {
            a[i].clear();
            deg[i]=0;
            f[i]=false;
            ans.clear();
            h[i]=0;
        }
        cout<<"\n";
    }
}
