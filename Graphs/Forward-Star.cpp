// بسم الله الرحمن الرحيم
// وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ
// Free Palestine
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define nl '\n'
#define sz(x) (int)(x).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define updmax(a, b) a = max(a, b)
#define updmin(a, b) a = min(a, b)
#define fixed(n) fixed << setprecision(n)
#define memo(arr) memset(arr, -1, sizeof(arr))
void debug() { cout << "[DEBUG]" << nl; }

const ll OO = (ll)4e18;
const int MOD = 1000000007;
const long double EPS = 1e-12;
const long double PI = acos(-1.0L);

struct ForwardStar
{
    static const int N = 1e3, M = 1e5;
    int head[N], to[M], nxt[M], wt[M], ne = 0;

    void init()
    {
        memo(head);
        ne = 0;
    }

    void addEdge(int u, int v, int w = 0)
    {
        to[ne] = v;
        wt[ne] = w;
        nxt[ne] = head[u];
        head[u] = ne++;
    }
};

void mora_solve()
{
    ForwardStar ds;
    ds.init();
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        ds.addEdge(u, v);
        ds.addEdge(v, u);
    }

    for (int u = 1; u <= n; u++)
    {
        cout << "[ " << u << " ] : ";
        for (auto e = ds.head[u]; e != -1; e = ds.nxt[e])
        {
            cout << ds.to[e] << " ";
        }
        cout << nl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q = 1;
    // cin >> q;
    for (int tc = 1; tc <= q; tc++)
    {
        mora_solve();
        // if (tc != q) cout << nl;
    }
    return 0;
}
