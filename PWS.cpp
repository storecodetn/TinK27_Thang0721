#include <bits/stdc++.h>
using namespace std;
FILE *fi = freopen("PWS.inp","r",stdin);
FILE *fo = freopen("PWS.out","w",stdout);
const long long Mod = 1e9 + 7;
typedef pair <int,int> ii;
const int Maxn = 2e5 + 10;
int n,k;
string s;
int dp[1<<17];
bool check(int len)
{
    vector <int> a[20];
    for(int c = 0;c < k;c++)
    {
        queue <int> q;
        for(int i = 1;i<=n;i++)
        {
            if(c + 'a' != s[i] && s[i] != '?')
                q.push(i);
            while(i >= len && q.size() && q.front() <= i - len)
            {
                q.pop();
            }
            if(!q.size() && i >= len)
                a[c].push_back(i - len + 1);
        }
    }
    for(int i = 0;i<1<<k;i++)
        dp[i] = 1e9;
    dp[0] = 0;
    for(int mask = 1;mask < 1<<k;mask++)
    {
        for(int j = 0;j < k;j++)
        {
            if(!(mask & (1<<j)))
                continue;
            int x = dp[mask ^ (1<<j)];
            if(x == 1e9)
                continue;
            auto k = upper_bound(a[j].begin(),a[j].end(),x);
            if(k == a[j].end())
                continue;
            dp[mask] = min(dp[mask],(*k) + len - 1);
        }
    }
    return dp[(1<<k)-1] <= n;
}
int main()
{
    iostream::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    cin>>s;
    s = '.' + s;
    int l = 1;
    int r = n;
    int ans = 0;
    while(l<=r)
    {
        int mid = l + r >> 1;
        if(check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout<<ans;
    return 0;
}
