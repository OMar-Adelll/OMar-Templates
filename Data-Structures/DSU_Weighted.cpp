// بسم الله الرحمن الرحيم
// وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ
// Free Palestine
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)x.size()
#define nl '\n'

struct WeightedDSU
{
    vector<int> parent, group;
    vector<int> weight;
    int comp;

    WeightedDSU(int n)
    {
        parent.assign(n + 1, 0);
        group.assign(n + 1, 0);
        weight.assign(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            group[i] = 1;
            weight[i] = 0;
        }

        comp = n;
    }

    int merge(int a, int b)
    {
        return a + b;
    }

    pair<int, int> find(int x)
    {
        if (parent[x] == x)
        {
            return {x, 0};
        }

        auto [root, w] = find(parent[x]);
        weight[x] = merge(weight[x], w);
        parent[x] = root;

        return {root, weight[x]};
    }

    bool Union(int u, int v, int w)
    {
        auto [lu, wu] = find(u);
        auto [lv, wv] = find(v);

        if (lu == lv)
            return false;

        if (group[lu] < group[lv])
        {
            swap(lu, lv);
            w = -w;
        }

        weight[lv] = wv - wu + w;

        group[lu] += group[lv];
        parent[lv] = lu;

        comp--;
        return true;
    }

    int query(int u, int v)
    {
        auto [lu, wu] = find(u);
        auto [lv, wv] = find(v);

        if (lv != lu)
            return INT_MIN;

        return wv - wu;
    }

    bool same(int u, int v) { return find(u).first == find(v).first; }
    int Size(int u) { return group[find(u).first]; }
};

int main()
{

    return 0;
}