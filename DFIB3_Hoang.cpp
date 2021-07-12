#include <bits/stdc++.h>

using namespace std;
FILE *fi = freopen("DFIB3.inp", "r", stdin);
FILE *fo = freopen("DFIB3.out", "w", stdout);

struct matrix
{
    long long val[4][4];
};
long long a, b, c, k, n;
matrix mt, mt0, mt1, mt2, ans;
matrix nhan(matrix f, matrix m)
{
    matrix res;
    memset(res.val, 0, sizeof res.val);
    for(int i = 1; i <= 3; i++)
        for(int j = 1; j <= 3; j++)
        {
            for(int t = 1; t <= 3; t++)
            {
                res.val[i][j] += (f.val[i][t]*m.val[t][j] + k)%k;
            }
            res.val[i][j] %= k;
        }
    return res;
}
void init()
{
    mt0.val[1][2] = mt1.val[1][1] = mt2.val[1][3] = a;
    mt0.val[1][3] = mt1.val[1][2] = mt2.val[1][1] = b;
    mt0.val[1][1] = mt1.val[1][3] = mt2.val[1][2] = c;
    mt0.val[2][1] = mt1.val[2][1] = mt2.val[2][1] = 1;
    mt0.val[3][2] = mt1.val[3][2] = mt2.val[3][2] = 1;
    memset(ans.val, 0, sizeof ans.val);
    ans.val[1][1] = ans.val[2][2] = ans.val[3][3] = 1;
    mt = nhan(mt0, mt2);
    mt = nhan(mt, mt1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> a >> b >> c >> k >> n)
    {
        init();
        if(n <= 3)
        {
            cout << n%k;
            continue;
        }
        long long x = n/3 - 1;
        for(; x > 0; mt = nhan(mt, mt))
        {
            if(x & 1) ans = nhan(ans, mt);
            x /= 2;
        }
        if(n % 3 == 1)
            ans = nhan(mt1, ans);
        if(n % 3 == 2)
            ans = nhan(nhan(mt2, mt1), ans);
        long long kq = 3*ans.val[1][1] + 2*ans.val[1][2] + ans.val[1][3];
        while(kq < 0)
            kq += k;
        cout << kq%k << "\n";
    }
    return 0;
}
