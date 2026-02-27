// بسم الله الرحمن الرحيم
// وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ
// Free Palestine
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)x.size()
#define nl '\n'

// General DataStructures
const int N = 5e5 + 5;
int cl[N], ans[N] = {}, Size[N] = {}, Big[N] = {};
vector<int> adj[N];

// Customized DataStructures to fit with Problem requirements
int freq[N]{}, sum[N]{};
int mx = 0;

void DSU(int node, int parent)
{
    Size[node] = 1;
    for (auto &child : adj[node])
    {
        if (child != parent)
        {
            DSU(child, node);

            Size[node] += Size[child];

            if (!Big[node] || Size[child] > Size[Big[node]])
                Big[node] = child;
        }
    }
}

// Update function: modify this according to problem requirements
void update(int node, int d)
{
    int c = cl[node];

    sum[freq[c]] -= c;
    freq[c] += d;
    sum[freq[c]] += c;

    mx = max(mx, freq[c]);
}

void collect(int node, int parent, int d)
{
    update(node, d);
    for (auto &child : adj[node])
    {
        if (child != parent)
        {
            collect(child, node, d);
        }
    }
}

void dfs(int node, int parent, bool keep)
{

    for (auto &child : adj[node])
    {
        if (child != parent && child != Big[node])
        {
            dfs(child, node, false);
        }
    }

    if (Big[node])
        dfs(Big[node], node, true);

    update(node, 1);

    for (auto &child : adj[node])
    {
        if (child != parent && child != Big[node])
        {
            collect(child, node, 1);
        }
    }

    // Answer your Queries
    ans[node] = sum[mx];

    if (!keep)
        collect(node, parent, -1), mx = 0;
}

int main()
{

    return 0;
}