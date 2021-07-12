#include <bits/stdc++.h>
using namespace std;
FILE *fi = freopen("CNUMOFPAIRS.inp", "r", stdin);
FILE *fo = freopen("CNUMOFPAIRS.out", "w", stdout);
const int maxn = 5e5+10;
int n, a[maxn];
bool d[maxn*10], vis[maxn*10];
int save[maxn];
int64_t gcd(int64_t a, int64_t b)
{
  if(b == 0) return a;
  return gcd(b, a%b);
}
void solve()
{
  int64_t res = a[1], begin = 1, cnt = 0, end, len = 0;
  for (int i=1; i<=n; )
  {
    begin = i;
    end = i;
    while(begin >= 1 && a[begin] % a[i] ==0 ) begin--;
    while(end <= n && a[end] % a[i] == 0) end ++;
    begin ++;
    end --;
    i = end + 1;
    int64_t num = end - begin;
    if(num == len) save[++cnt] = begin;
    else if(num > len)
      {
        len = num;
        cnt = 0;
        save[++cnt] = begin;
      }
  }
  cout<<cnt<<" "<<len<<"\n";
  for (int i=1; i<=cnt; i++)
  {
    cout<<save[i]<<" ";
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin>>n;
  for (int i=1; i<=n; ++i) 
  {
    cin>>a[i];
    d[a[i]] = 1;
  }
  solve();
  return 0;
}