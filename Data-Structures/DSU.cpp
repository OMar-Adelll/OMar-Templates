// بسم الله الرحمن الرحيم
// وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ
#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct DSU
{
    vector<int> parent, group;
    DSU(int n)
    {
        parent.resize(n + 1);
        group.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {

            parent[i] = i;
            group[i] = 1;
        }
    }

    int findLeader(int i)
    {
        if (parent[i] == i)
            return i;
        return parent[i] = findLeader(parent[i]);
    }

    bool sameGroup(int u, int v)
    {
        return findLeader(u) == findLeader(v);
    }

    void Union(int u, int v)
    {
        int leader1 = findLeader(u);
        int leader2 = findLeader(v);

        if (leader1 == leader2)
            return;

        if (group[leader1] < group[leader2])
            swap(leader1, leader2);

        group[leader1] += group[leader2];
        parent[leader2] = leader1;
    }
    int get_size(int u) { return group[findLeader(u)]; }
};

int main()
{
    return 0;
}