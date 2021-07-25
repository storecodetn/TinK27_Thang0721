#include <bits/stdc++.h>

using namespace std;

FILE *fi=freopen("Sjekira.inp","r",stdin);
FILE *fo=freopen("Sjekira.out","w",stdout);

const int N=1e5+1;

int n,T=1,p[N];
long long c[N],kq=0;
vector<int> a[N];
vector<int> b[N];
map<int,int> m;

void nhap()
{
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>c[i];
        p[i]=i;
        if (!m[c[i]])
            m[c[i]]=T++;
        b[m[c[i]]].push_back(i);
    }
    for (int i=1;i<n;++i)
    {
        int u,v;
        cin>>u>>v;
        if (c[u]<c[v])
            swap(u,v);
        a[u].push_back(v);
    }
}

int root(int u)
{
    if (p[u]!=u)
        p[u]=root(p[u]);
    return p[u];
}

void process()
{
    for (auto i:m)
    {
        for (auto u:b[i.second])
        {
            for (auto v:a[u])
            {
                int ru=root(u),rv=root(v);
                p[rv]=ru;
                kq+=c[rv]+c[ru];
                c[ru]=max(c[rv],c[ru]);
            }
        }
    }
    cout<<kq;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    nhap();
    process();
    return 0;
}
