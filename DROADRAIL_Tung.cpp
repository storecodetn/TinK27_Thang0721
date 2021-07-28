#include <bits/stdc++.h>
using namespace std;
int n,m,l,q;
vector<pair<int,long long> > a[3][1001];
long long d[1001][4][1005],ss[1001][4];
bool f[1001][4][1005];
#define pp pair<pair<long long,long long>,pair<long long,long long> >
#define fi first
#define se second
void distra()
{
    priority_queue<pp,vector<pp> ,greater<pp> > q;
    d[1][0][0]=0;
    q.push({{0,1},{0,0}});   // val - dinh - so lan -  dinh truoc do
    while(!q.empty())
    {
        pp k=q.top();
        q.pop();
        long long u=k.fi.se;
        long long w=k.fi.fi;
        long long lan=k.se.fi;
        long long trc=k.se.se;
        if(w>d[u][trc][lan])
            continue;
        if(d[u][trc][lan]>d[u][trc][ss[u][trc]] && lan>ss[u][trc])
            continue;
        f[u][trc][lan]=true;
        for(auto v:a[1][u])
        {
            long long x=v.fi;
            long long y=v.se;
            if(d[x][1][lan+1-(1==trc)]>w+y)
            {
                d[x][1][lan+1-(1==trc)]=w+y;
                if(d[x][1][ss[x][1]]>w+y)
                    ss[x][1]=lan+1-(1==trc);
                q.push({{w+y,x},{lan+1-(1==trc),1}});
            }
        }
        for(auto v:a[2][u])
        {
            long long x=v.fi;
            long long y=v.se;
            if(d[x][2][lan+1-(2==trc)]>w+y)
            {
                d[x][2][lan+1-(2==trc)]=w+y;
                if(d[x][2][ss[x][2]]>w+y)
                    ss[x][2]=lan+1-(2==trc);
                q.push({{w+y,x},{lan+1-(2==trc),2}});
            }
        }
    }
}
int main()
{
    freopen("DROADRAIL.inp","r",stdin);
    freopen("DROADRAIL.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>l>>q;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        u++;
        v++;
        a[1][u].push_back({v,w});
    }
    for(int i=1;i<=l;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        u++;
        v++;
        a[2][u].push_back({v,w});
    }
    for(int i=0;i<=n;i++)
        for(int j=0;j<=1001;j++)
            d[i][1][j]=d[i][2][j]=1e18;
    distra();
    for(int i=1;i<=q;i++)
    {
        long long c,t;
        cin>>c>>t;
        t++;
        long long Min=1e18;
        for(long long j=1;j<=1001;j++)
        {
            Min=min(d[t][1][j]+(j-1)*c,Min);
            Min=min(d[t][2][j]+(j-1)*c,Min);
        }
        if(t==1)
            Min=0;
        if(Min==1e18)
            Min=-1;
        cout<<Min<<"\n";
    }
}
