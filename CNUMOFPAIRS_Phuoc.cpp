#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+100;
int n,res,tmp;
int arr[maxn],lg2[maxn];
int rmqGcd[maxn][20],rmqMin[maxn][20];
vector <int> pos;
int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
void init()
{
    lg2[1]=0;
    for(int i=2;i<=n;i++) lg2[i]=lg2[i/2]+1;
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            rmqGcd[i][j]=gcd(rmqGcd[i][j-1],rmqGcd[i+(1<<(j-1))][j-1]);
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            rmqMin[i][j]=min(rmqMin[i][j-1],rmqMin[i+(1<<(j-1))][j-1]);
}
int getGcd(int l,int r)
{
    int k=lg2[r-l+1];
    return gcd(rmqGcd[l][k],rmqGcd[r-(1<<k)+1][k]);
}
int getMin(int l,int r)
{
    int k=lg2[r-l+1];
    return min(rmqMin[l][k],rmqMin[r-(1<<k)+1][k]);
}
bool check(int x)
{
    for(int i=1;i<=n-x;i++)
        if(getGcd(i,i+x)==getMin(i,i+x)) return true;
    return false;
}
void bs()
{
    int l=0,r=n-1,mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(check(mid))
        {
            l=mid+1;
            res=max(res,mid);
        }
        else r=mid-1;
    }
}
void truy_vet()
{
    for(int i=1;i<=n-res;i++)
        if(getGcd(i,i+res)==getMin(i,i+res)) pos.push_back(i);
}
int main()
{
    freopen("CNUMOFPAIRS.inp","r",stdin);
    freopen("CNUMOFPAIRS.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<maxn;i++)
        for(int j=1;j<20;j++) rmqMin[i][j]=1e9;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        rmqGcd[i][0]=arr[i];
        rmqMin[i][0]=arr[i];
    }
    init();
    bs();
    truy_vet();
    cout<<pos.size()<<" "<<res<<"\n";
    for(int id:pos) cout<<id<<" ";
}
