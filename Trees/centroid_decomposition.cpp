// بسم الله الرحمن الرحيم
// وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ
// Free Palestine
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)x.size()
#define nl '\n'

struct centroid_decomposition
{
    int N;
    vector<int> Sz, dist, par;
    vector<bool> vis;
    vector<vector<int>> adj;

    centroid_decomposition(int n, vector<vector<int>> &graph)
    {
        N = n;
        adj = graph;
        Sz.resize(n + 1), dist.resize(n + 1), par.resize(n + 1), vis.assign(n + 1, 0);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int get_subtree_Sz(int u, int p)
    {
        Sz[u] = 1;
        for (auto v : adj[u])
        {
            if (v == p || vis[v])
                continue;

            Sz[u] += get_subtree_Sz(v, u);
        }

        return Sz[u];
    }

    int get_centroid(int u, int p, int Si)
    {
        for (auto v : adj[u])
        {
            if (v == p || vis[v])
                continue;
            if (Sz[v] * 2 > Si)
                return get_centroid(v, u, Si);
        }

        return u;
    }

    void decompose(int u, int p = 0)
    {
        int comp_Sz = get_subtree_Sz(u, p);
        int centroid = get_centroid(u, p, comp_Sz);

        // calc your answer here

        vis[centroid] = true;
        par[centroid] = p;

        for (auto v : adj[centroid])
        {
            if (vis[v])
                continue;

            decompose(v, centroid);
        }
    }
};

int main()
{

    return 0;
}