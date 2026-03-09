// بسم الله الرحمن الرحيم
// وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ
// Free Palestine
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)x.size()
#define nl '\n'
#define memo(x) memset(x, -1, sizeof(x))

const int N = 1e3;
const int M = 1e5;
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

void mora_solve()
{
    init();

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }

    for (int u = 1; u <= n; u++)
    {
        cout << u << " : ";
        for (int e = head[u]; e != -1; e = nxt[e])
        {
            int v = to[e], w = wt[e];
            cout << v << " ";
        }

        cout << nl;
    }
}

int main()
{
    mora_solve();
    return 0;
}