#include <bits/stdc++.h>

using namespace std;
int t,m,x;
set<int> s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("bestate.inp","r",stdin);
    freopen("bestate.out","w",stdout);
    cin>>t;
    while (t--)
    {
        s.clear();
        cin>>m;
        for (int i=1;i<=2*m;i++)
            {
                cin>>x;
                s.insert(x);
            }
        cout<<s.size()<<"\n";
    }
    return 0;
}
