// بسم الله الرحمن الرحيم
// وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) x.size()

vector<vector<int>> adj;
function<pair<int, int>(int, int)> Diameter = [&](int node, int parent)
{
    int mx1 = 0, mx2 = 0, cur_diameter = 0;
    for (auto &child : adj[node])
    {
        if (child == parent)
            continue;

        auto cur = Diameter(child, node);

        cur_diameter = max(cur_diameter, cur.first);

        int cur_h = cur.second;

        if (cur_h >= mx1)
        {
            mx2 = mx1;
            mx1 = cur_h;
        }
        else if (cur_h > mx2)
        {
            mx2 = cur_h;
        }
    }

    int height = 1 + mx1;
    int diameter = max(cur_diameter, mx1 + mx2);

    return make_pair(diameter, height);
};

int main()
{
    return 0;
}