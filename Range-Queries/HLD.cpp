// بسم الله الرحمن الرحيم
// وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ
// Free Palestine
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)x.size()
#define nl '\n'

class HLD
{
private:
    void dfs(int node, const vector<vector<int>> &adj)
    {
        for (auto &child : adj[node])
        {
            if (child == parent[node])
                continue;

            parent[child] = node;
            depth[child] = depth[node] + 1;

            dfs(child, adj);
            Size[node] += Size[child];

            if (BigChild[node] == -1 || Size[child] > Size[BigChild[node]])
                BigChild[node] = child;
        }
    }

    void flatten(int node, const vector<vector<int>> &adj)
    {
        Id[node] = nextId++;

        if (BigChild[node] != -1)
        {
            head[BigChild[node]] = head[node];
            flatten(BigChild[node], adj);
        }

        for (auto &child : adj[node])
        {
            if (child == BigChild[node] || child == parent[node])
                continue;

            head[child] = child;
            flatten(child, adj);
        }
    }

public:
    vector<int> parent, BigChild, head, Size, depth, Id;
    int nextId;

    HLD(int n, vector<vector<int>> &adj) : parent(n + 1), BigChild(n + 1, -1), head(n + 1), Size(n + 1, 1), depth(n + 1), Id(n + 1)
    {
        dfs(1, adj);

        this->nextId = 1;
        head[1] = 1;

        flatten(1, adj);
    }

    vector<pair<int, int>> paths(int u, int v)
    {
        vector<pair<int, int>> rs;
        while (true)
        {
            if (head[u] == head[v])
            {
                if (depth[u] > depth[v])
                {
                    swap(u, v);
                }
                rs.push_back({Id[u], Id[v]});

                return rs;
            }

            if (depth[head[u]] > depth[head[v]])
                swap(u, v);

            rs.push_back({Id[head[v]], Id[v]});
            v = parent[head[v]];
        }
    }
};

int main()
{

    return 0;
}