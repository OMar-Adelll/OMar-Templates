// بسم الله الرحمن الرحيم
// وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ
// Free Palestine
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)x.size()
#define nl '\n'

struct DSU
{
    vector<int> parent, group;
    stack<array<int, 4>> st;
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

        if (group[leader1] > group[leader2])
        {
            swap(leader1, leader2);
        }

        array<int, 4> p = {0, 0, 0, 0};
        p[0] = leader2, p[1] = group[leader2];
        p[2] = leader1, p[3] = parent[leader1];
        st.push(p);

        if (leader1 == leader2)
        {
            return;
        }

        group[leader2] += group[leader1];
        parent[leader1] = leader2;
    }

    void rollback()
    {
        if (st.empty())
            return;
        auto &[a, b, c, d] = st.top();

        group[a] = b;
        parent[c] = d;

        st.pop();
    }

    int get_size(int u) { return group[findLeader(u)]; }
};

int main()
{

    return 0;
}