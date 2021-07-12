#include <bits/stdc++.h>
using namespace std;
int n,res,a[1000000],dem;
bool f[1000000];
vector<int> c;
void xuly(int x)
{
    int l,r;
    for( r=x+1;r<=n;r++)
        if(a[r]%a[x]!=0)
            {
                r--;
                break;
            }
        else
        {
            f[r]=true;

        }
    if(r>n)
        r=n;
    for( l=x-1;l>=1;l--)
        if(a[l]%a[x]!=0)
            {
                l++;
                break;
            }
        else
            f[l]=true;
    if(l<1)
        l=1;
    if(r-l>res)
    {
        res=r-l;
        dem=1;
        c.clear();
        c.push_back(l);
    }
    else
        if(r-l==res)
    {
        dem++;
        c.push_back(l);
    }
}
int main()
{
    freopen("CNUMOFPAIRS.inp","r",stdin);
    freopen("CNUMOFPAIRS.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        if(!f[i])
            xuly(i);
    cout<<dem<<" "<<res<<"\n";
    sort(c.begin(),c.end());
    for(auto v:c)
        cout<<v<<" ";
}
