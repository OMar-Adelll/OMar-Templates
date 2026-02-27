// بسم الله الرحمن الرحيم
// وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ
// Free Palestine
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)x.size()
#define nl '\n'

const int N = 2e5 + 5;
vector<vector<int>> adj;
int In[N], Out[N], timer = 0;
void Euler_Tour(int node, int par)
{
    In[node] = ++timer;
    for (auto &child : adj[node])
    {
        if (child != par)
        {
            Euler_Tour(child, node);
        }
    }

    Out[node] = timer;
}

int main()
{

    return 0;
}