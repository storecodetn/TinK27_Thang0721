#include <bits/stdc++.h>
using namespace std;
int n,m,dem,ans,k,d[100001],s[100001];
vector<int> a[100001],c;
pair<int,int> b[100001];
bool f[100001];
void dfs(int u)
{
    f[u]=true;
    d[u]=dem;
    s[dem]--;
    for(auto v:a[u])
        if(!f[v])
            dfs(v);
}
int main()
{
    freopen("BSONP.inp","r",stdin);
    freopen("BSONP.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
        for(int i=1;i<=m;i++)
            {
                int u,v;
                cin>>u>>v;
                a[u].push_back(v);
                a[v].push_back(u);
                b[i].first=u;
                b[i].second=v;
            }
        for(int i=1;i<=n;i++)
            if(!f[i])
        {
            dem++;
            dfs(i);
            c.push_back(-s[dem]);
            s[dem]++;
        }
        for(int i=1;i<=m;i++)
            s[d[b[i].first]]++;
        for(int i=1;i<=dem;i++)
            ans+=s[i];
    if(c.size()>k)
        cout<<"-1";
    else
        cout<<ans+(k-c.size());
}
