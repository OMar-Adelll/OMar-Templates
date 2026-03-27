// بسم الله الرحمن الرحيم
// وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ
#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct DSU
{
    vector<int> parent, group;
    int comp;
    DSU(int n)
    {
        parent.resize(n + 1);
        group.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {

            parent[i] = i;
            group[i] = 1;
        }
        comp = n;
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    bool Union(int u, int v)
    {
        int lu = find(u), lv = find(v);

        if (lu == lv)
            return false;

        if (group[lu] < group[lv])
            swap(lu, lv);

        group[lu] += group[lv];
        parent[lv] = lu;
        comp--;
        
        return true;
    }

    bool same(int u, int v) { return find(u) == find(v); }
    int Size(int u) { return group[find(u)]; }
};

int main()
{
    return 0;
}
