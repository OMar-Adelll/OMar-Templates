// بسم الله الرحمن الرحيم
// وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ
// Free Palestine
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)x.size()
#define nl '\n'

class TopoSort
{
private:
    int n;
    vector<vector<int>> adj;
    vector<int> ans;
    vector<bool> vis;
    void dfs(int node)
    {
        vis[node] = true;
        for (auto &child : adj[node])
            if (!vis[child])
                dfs(child);
        ans.push_back(node);
    }

    void Topological_sort()
    {
        vis.assign(n + 1, false);
        ans.clear();
        for (int node = 1; node <= n; node++)
            if (!vis[node])
                dfs(node);

        reverse(ans.begin(), ans.end());
    }

public:
    TopoSort(vector<vector<int>> adj)
    {
        this->adj = adj;
        this->n = adj.size() - 1;
        Topological_sort();
    }

    vector<int> getSorted()
    {
        return ans;
    }
};

int main()
{

    return 0;
}