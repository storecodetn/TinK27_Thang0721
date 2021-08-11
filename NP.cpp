#include <bits/stdc++.h>

using namespace std;
FILE *fi = freopen("NP.inp", "r", stdin);
FILE *fo = freopen("NP.out", "w", stdout);
int n, q, s;
const int Max = 6e5 + 11;
typedef pair<long long, long long> ii;
vector<ii> a[Max];
long long Dist[Max];
struct Segmentree
{
    int l[Max];
    int r[Max];
    int leaf[Max];
    void debug(int u, int v)
    {
        cerr << l[u] << "," << r[u] << "---> " << l[v] << "," << r[v] << "\n";
    }
    int cnt = 0;
    int id1[Max];
    int id2[Max];
    void build(int i, int j, int x)
    {
        l[x] = i;
        r[x] = j;
        id1[x] = ++cnt;
        id2[x] = ++cnt;
        if (i == j)
        {
            leaf[i] = x;
            a[id1[x]].push_back({i, 0});
            a[i].push_back({id2[x], 0});
            return;
        }
        int mid = i + j >> 1;
        build(i, mid, 2 * x);
        build(mid + 1, j, 2 * x + 1);
        int u = id1[x];
        int c1 = id1[2 * x];
        int c2 = id1[2 * x + 1];
        a[u].push_back({c1, 0});
        a[u].push_back({c2, 0});
        u = id2[x];
        c1 = id2[2 * x];
        c2 = id2[2 * x + 1];
        a[c1].push_back({u, 0});
        a[c2].push_back({u, 0});
    }
    int st;
    int qi, qj;
    int u;
    long long w;
    void update(int x)
    {
        if (l[x] > qj || r[x] < qi)
            return;
        if (l[x] >= qi && r[x] <= qj)
        {
            if (st == 1 || st == 2)
            {
                a[u].push_back({id1[x], w});
            }
            else
            {
                a[id2[x]].push_back({u, w});
            }
            return;
        }
        update(2 * x);
        update(2 * x + 1);
    }
} tree;
int main()
{
    cin >> n >> q >> s;
    tree.cnt = n;
    tree.build(1, n, 1);
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            tree.st = t;
            cin >> tree.u;
            cin >> tree.qi;
            tree.qj = tree.qi;
            cin >> tree.w;
            tree.update(1);
        }
        else
        {
            tree.st = t;
            cin >> tree.u >> tree.qi >> tree.qj >> tree.w;
            tree.update(1);
        }
    }
    for (int i = 1; i <= Max - 1; i++)
    {
        Dist[i] = 1e18;
    }
    Dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> h;
    h.push({0, s});
    while (h.size())
    {
        ii x = h.top();
        h.pop();
        int u = x.second;
        long long du = x.first;
        for (auto v : a[u])
        {
            if (Dist[v.first] > du + v.second)
            {
                Dist[v.first] = du + v.second;
                h.push({Dist[v.first], v.first});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (Dist[i] == 1e18)
            Dist[i] = -1;
        cout << Dist[i] << " ";
    }
    return 0;
}
