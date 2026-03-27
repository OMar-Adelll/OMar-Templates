// بسم الله الرحمن الرحيم
// وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ
// Free Palestine
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)x.size()
#define nl '\n'

vector<vector<int>> adj;
vector<int> vis;
int dfs(int u, int p)
{
    vis[u] = 1;
    for (auto &v : adj[u])
    {
        if (!vis[v])
        {
            if (dfs(v, u))
                return true;
        }
        else if (v != p)
        {
            return true;
        }
    }

    vis[u] = 2;
    return false;
}

bool is_bipartite(int n)
{
    vector<int> col(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        if (col[i] == -1)
        {
            queue<int> q;
            q.push(i);
            col[i] = 0;
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                for (auto &v : adj[u])
                {
                    if (col[v] == -1)
                    {
                        col[v] = col[u] ^ 1;
                        q.push(v);
                    }
                    else
                    {
                        if (col[v] == col[u])
                            return false;
                    }
                }
            }
        }
    }

    return true;
}

void mora_solve()
{
    int n, m;
    cin >> n >> m;
    adj.assign(n + 1, {});
    vis.assign(n + 1, false);

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool cycle = false;
    for (int i = 1; i <= n; i++)
        if (!vis[i] && dfs(i, i))
            cycle = true;

    if (!cycle)
        return void(cout << "You Don't have cycles" << nl);

    cout << (is_bipartite(n) ? "All cycles is Even" : "Include Odd Cycles") << nl;
}

int main()
{

    return 0;
}
