// بسم الله الرحمن الرحيم
// وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ
#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Ancestor
{
private:
    vector<vector<int>> adj, anc;
    vector<int> dist;
    const int N = 500005;
    const int LOG = 23;

public:
    Ancestor() {}

    void init(vector<vector<int>> &nums)
    {
        int n = nums.size();
        adj = nums;
        anc = vector<vector<int>>(N, vector<int>(LOG, 0));
        dist = vector<int>(n, 0);

        dfs(1, 0);
    }

    void dfs(int node, int parent)
    {
        anc[node][0] = parent;
        for (int i = 1; i < LOG; i++)
        {
            int p = anc[node][i - 1];
            anc[node][i] = anc[p][i - 1];
        }

        for (auto &child : adj[node])
        {
            if (child != parent)
            {
                dist[child] = dist[node] + 1;
                dfs(child, node);
            }
        }
    }

    int kth_Ancestor(int node, int k)
    {

        for (int i = LOG - 1; i >= 0; i--)
        {
            if (k & (1LL << i))
            {
                node = anc[node][i];
            }
        }

        return node;
    }

    int LCA(int u, int v)
    {

        if (dist[v] > dist[u])
            swap(u, v);

        u = kth_Ancestor(u, dist[u] - dist[v]);

        if (u == v)
            return u;

        for (int i = LOG - 1; i >= 0; i--)
        {
            if (anc[u][i] != anc[v][i])
            {
                u = anc[u][i];
                v = anc[v][i];
            }
        }

        return anc[u][0];
    }

    int distance(int u, int v)
    {
        int w = LCA(u, v);
        return dist[u] + dist[v] - 2 * dist[w];
    }
};

int main()
{
    return 0;
}