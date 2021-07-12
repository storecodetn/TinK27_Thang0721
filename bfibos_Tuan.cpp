#include <bits/stdc++.h>
using namespace std;

const long long m=1e9+7;
struct matrix
{
    long long val[4][4];
};
matrix a,c;
long long n;
//-----------
matrix nhan(matrix a, matrix b)
{
    matrix c;
    for (int i=1;i<=2;i++)
        for (int j=1; j<=2;j++)
        {
            c.val[i][j] = 0;
                for (int k=1;k<=2;k++)
                    c.val[i][j]=(c.val[i][j]%m + (a.val[i][k]%m * b.val[k][j]%m)%m)%m;
        }
    return c;
}
//----------
matrix mu(matrix a, long long k)
{
    matrix x;
    if (k==1) return a;
    x=mu(a,k/2);
    x=nhan(x,x);
    if (k%2) x=nhan(x,a);
    return x;
}
//----------
int main()
{
    freopen("bfibos.inp","r",stdin);
    freopen("bfibos.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    a.val[1][1]=1;
    a.val[1][2]=1;
    a.val[2][1]=1;
    a.val[2][2]=0;
    cin>>n;
    c=mu(a,n+1);
    cout<<(c.val[1][1]%m+c.val[1][2]%m-1+m)%m;
    return 0;
}
