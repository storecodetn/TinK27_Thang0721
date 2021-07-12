#include <bits/stdc++.h>

using namespace std;

FILE *fi = freopen("CFORMATION.inp", "r", stdin);
FILE *fo = freopen("CFORMATION.out", "w", stdout);
const int nxm = 1e3 + 10;
int n;
long long x[nxm], y[nxm], ans;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
    map<pair<long long, pair<long long, long long> >, int> d;
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
        {
            ans += d[{(x[j] - x[i])*(x[j] - x[i]) + (y[j] - y[i])*(y[j] - y[i]), {x[i] + x[j], y[i] + y[j]}}];
            d[{(x[j] - x[i])*(x[j] - x[i]) + (y[j] - y[i])*(y[j] - y[i]), {x[i] + x[j], y[i] + y[j]}}]++;
        }
    cout << ans;
    return 0;
}
