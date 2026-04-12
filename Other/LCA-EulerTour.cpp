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

const int N = 2e5 + 5;
vector<vector<int>> adj;
vector<int> euler, dist, first;
void Euler_Tour(int node, int par, int d)
{
    if (first[node] == -1)
        first[node] = euler.size();

    euler.push_back(node);
    dist.push_back(d);
    for (auto &child : adj[node])
    {
        if (child != par)
        {
            Euler_Tour(child, node, d + 1);
            euler.push_back(node);
            dist.push_back(d);
        }
    }
}

class SparseTable
{
private:
    const int N = 500005;
    const int LOG = 23;
    vector<vector<int>> sparse;

    int merge(int x, int y)
    {
        if (dist[x] < dist[y])
            return x;
        return y;
    }

public:
    SparseTable()
    {
        sparse.assign(N, vector<int>(LOG, 0));
    }

    void build(vector<int> &nums)
    {
        int n = sz(nums);

        for (int i = 0; i < n; i++)
            sparse[i][0] = i;

        for (int k = 1; k < LOG; k++)
        {
            for (int i = 0; i + (1 << k) <= n; i++)
            {
                sparse[i][k] = merge(sparse[i][k - 1], sparse[i + (1LL << (k - 1))][k - 1]);
            }
        }
    }

    int query(int l, int r)
    {
        int len = r - l + 1;
        int ans = LLONG_MAX;
        for (int i = LOG - 1; i >= 0; i--)
        {
            if (len & (1LL << i))
            {
                ans = merge(ans, sparse[l][i]);
                l += (1LL << i);
            }
        }
        return ans;
    }

    int One_query(int l, int r)
    {
        /*
              Works only for idempotent associative operations,
              where overlapping segments do not affect the result.
              - Works on ( Minimum, Maximum, Gcd, And, Or, .... ).
              - Doesn't work on ( Sum, XOR, Product ...... ).
        */
        int len = r - l + 1;
        int k = 63 - __builtin_clzll(len);
        int ans = merge(sparse[l][k], sparse[r - (1LL << k) + 1][k]);
        return ans;
    }
};

void mora_solve()
{

    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    first.assign(n + 1, -1);
    for (int i = 2; i <= n; i++)
    {
        int v;
        cin >> v;
        adj[i].push_back(v);
        adj[v].push_back(i);
    }

    Euler_Tour(1, 0, 0);
    SparseTable ds;
    ds.build(dist);

    while (m--)
    {
        int u, v;
        cin >> u >> v;

        int l = first[u];
        int r = first[v];
        if (l > r)
            swap(l, r);

        int idx = ds.One_query(l, r);
        cout << euler[idx] << nl;
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