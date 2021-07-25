#include <bits/stdc++.h>

using namespace std;

FILE *fi=freopen("bajka.inp","r",stdin);
FILE *fo=freopen("bajka.out","w",stdout);

const int N=3005;

int n,m,next_char[N];
long long d[N][N];
string s,t;
vector<int> pos[N];

void process()
{
    for (int i=1;i<=m;++i)
        for (int j=1;j<=n;++j)
            d[i][j]=INT_MAX;
    for (int j=1;j<=n;++j)
        if (s[j]==t[1])
            d[1][j]=0;
    for (int i=2;i<=m;++i)
    {
        for (int j=1;j<=n;++j)
        {
            if (s[j]!=t[i])
                continue;
            for (int k=-1;k<2;k+=2)
            {
                if (k+j<=0 || k+j>n)
                    continue;
                d[i][j]=min(d[i][j],d[i-1][k+j]+1);
            }
            d[i][next_char[j]]=min(d[i][next_char[j]],d[i][j]+next_char[j]-j);
        }
        long long last=INT_MAX;
        for (int j=n;j>0;--j)
        {
            last++;
            if (s[j]!=t[i])
                continue;
            if (last>d[i][j])
                last=d[i][j];
            else
                d[i][j]=last;
        }
    }
    long long kq=INT_MAX;
    for (int j=1;j<=n;++j)
    {
        if (d[m][j]<kq)
            kq=d[m][j];
    }
    if (kq==INT_MAX)
        cout<<-1;
    else cout<<kq;
}

void init()
{
    for (int i=1;i<=n;++i)
        pos[s[i]].push_back(i);
    for (int i='a';i<='z';++i)
    {
        pos[i].push_back(n+1);
        for (int j=1;j<pos[i].size();++j)
            next_char[pos[i][j-1]]=pos[i][j];
    }
}

int main()
{
    cin>>n>>m>>s>>t;
    s="1"+s;
    t="1"+t;
    init();
    process();
    return 0;
}
