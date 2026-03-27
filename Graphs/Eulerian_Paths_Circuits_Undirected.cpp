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

/*
   ## EULER TOUR & EULER CIRCUIT ##
   ## IMPORTANT NOTE : These methods is for graphs only

    [1] UNDIRECTED GRAPH
        Euler Tour (path):
            - Exactly 2 vertices with ODD degree
            - Start at one odd-degree vertex, end at the other

        Euler Circuit:
            - ALL vertices have EVEN degree  (0 odd-degree vertices)
            - Start and end at the same vertex

        Connectivity (both cases):
            - All vertices with non-zero degree must be CONNECTED


    [2] DIRECTED GRAPH
        Euler Tour (path):
            - Exactly 1 vertex where  (out_degree - in_degree = +1)  --> start node
            - Exactly 1 vertex where  (out_degree - in_degree = -1)  --> end node
            - All other vertices:      in_degree == out_degree
            - Graph must be WEAKLY CONNECTED

        Euler Circuit:
            - EVERY vertex:  in_degree == out_degree
            - Graph must be STRONGLY CONNECTED
            - Start and end at the same vertex

*/

int n, m;
vector<vector<pair<int, int>>> adj; // this will include the vertex and edge id
vector<int> deg;
bool Undirected_Euler() // this function for path & circuit
{
    int st = -1, cycle_st = -1, odds = 0;
    for (int u = 1; u <= n; u++)
    {
        if (deg[u] & 1)
            odds++, (st == -1 ? st = u : st);
        if (!adj[u].empty())
            cycle_st = u;
    }

    if (odds > 2 || odds == 1)
        return false;
    if (st == -1)
        st = cycle_st;

    if (cycle_st == -1)
    {
        cout << "Yes" << nl << 0 << nl << nl;
        return true;
    }

    vector<int> nodes, edges, vis(m);
    auto dfs = [&](auto &&dfs, int u) -> void
    {
        while (!adj[u].empty())
        {
            auto [v, e] = adj[u].back();
            adj[u].pop_back();

            if (vis[e])
                continue;

            vis[e] = 1;
            dfs(dfs, v);
            nodes.push_back(v);
            edges.push_back(e);
        }
    };

    dfs(dfs, st);
    if (edges.size() != m)
        return false;

    nodes.push_back(st);
    ::reverse(edges.begin(), edges.end());
    ::reverse(nodes.begin(), nodes.end());

    cout << "Yes" << endl;

    for (auto &i : nodes)
        cout << i - 1 << ' ';
    cout << endl;

    for (auto &i : edges)
        cout << i << ' ';
    cout << endl;

    return true;
}

void solve()
{
    cin >> n >> m;
    adj.assign(n + 1, {});
    deg.assign(n + 1, 0);
    for (int e = 0; e < m; e++)
    {
        int u, v;
        cin >> u >> v;
        u++, v++;
        adj[u].push_back({v, e});
        adj[v].push_back({u, e});

        deg[u]++, deg[v]++;
    }

    if (!Undirected_Euler())
        cout << "No" << nl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q = 1;
    cin >> q;
    for (int tc = 1; tc <= q; tc++)
    {
        solve();
        // if (tc != q) cout << nl;
    }
    return 0;
}