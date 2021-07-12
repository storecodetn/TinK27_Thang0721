#include <bits/stdc++.h>

using namespace std;
FILE *fi = freopen("AUNLOCK.inp", "r", stdin);
FILE *fo = freopen("AUNLOCK.out", "w", stdout);
const int M = 1e9 + 7;
long long chinhhop(int k, int n)
{
    long long res = 1;
    for(int i = n - k + 1; i <= n; i++)
        res = (res%M*i%M)%M;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        cout << chinhhop(n, k) << "\n";
    }
    return 0;
}
