// بسم الله الرحمن الرحيم
// وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define OO 2e18

int n;
struct node
{
    int val;
    int cost;
};
vector<vector<node>> adj;

vector<int> Dijkstra()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    vector<int> ans(n + 1, OO);
    q.push({0, 1});
    ans[1] = 0;
    while (!q.empty())
    {
        auto [cst, nd] = q.top();
        q.pop();
        if (cst > ans[nd])
            continue;
        for (node &ch : adj[nd])
        {
            if (cst + ch.cost < ans[ch.val])
            {
                ans[ch.val] = cst + ch.cost;
                q.push({ans[ch.val], ch.val});
            }
        }
    }
    return ans;
}

int main()
{
    return 0;
}