// بسم الله الرحمن الرحيم
// وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ
// Free Palestine
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)x.size()
#define nl '\n'
#define memo(arr) memset(arr, -1, sizeof(arr))

/*
   ## EULER TOUR & EULER CIRCUIT ##
   ## IMPORTANT NOTE : These methods is for graphs only

    [1] UNDIRECTED GRAPH
        Euler Tour (path):
            - Exactly 2 vertices with ODD degree
            - Start at one odd-degree vertex, end at the other

        Euler Circuit:
            - ALL vertices have EVEN degree  (0 odd-degree vertices)
            - Start and end at the same vertex

        Connectivity (both cases):
            - All vertices with non-zero degree must be CONNECTED


    [2] DIRECTED GRAPH
        Euler Tour (path):
            - Exactly 1 vertex where  (out_degree - in_degree = +1)  --> start node
            - Exactly 1 vertex where  (out_degree - in_degree = -1)  --> end node
            - All other vertices:      in_degree == out_degree
            - Graph must be WEAKLY CONNECTED

        Euler Circuit:
            - EVERY vertex:  in_degree == out_degree
            - Graph must be STRONGLY CONNECTED
            - Start and end at the same vertex

*/

// Forward Star datastructure
const int N = 2e5 + 5, M = 4e5 + 5;
int head[N], to[M], nxt[M], wt[M], ne = 0;

void init()
{
    memo(head);
    ne = 0;
}

void addEdge(int u, int v, int w = 0)
{
    to[ne] = v;
    wt[ne] = w;
    nxt[ne] = head[u];
    head[u] = ne++;
}

void addBiEdge(int u, int v, int w = 0)
{
    addEdge(u, v, w), addEdge(v, u, w);
}

// data-structures
int deg[N], vis[2 * M], ans[2 * M], si, vid = 1;

void Euler(int u)
{
    for (int e = head[u]; e != -1; e = nxt[e])
    {
        int v = to[e];
        if (vis[e] == vid)
            continue;
        vis[e] = vis[e ^ 1] = vid; // mark both directions
        Euler(v);
        ans[si++] = e;
    }
}

// This returns true if Euler tour(path)/circuit exists.
// sets st = valid start node
int n; // this from input
bool Euler_Undirected(int &st, int m)
{
    int odd = 0;
    st = -1;
    for (int i = 0; i < n; i++)
    {
        if (deg[i] > 0 && st == -1)
        {
            st = i;
        }

        if (deg[i] & 1)
        {
            odd++, st = i;
        }
    }

    if (!(odd == 0 || odd == 2))
    {
        return false;
    }

    if (st == -1)
    {
        si = 0;
        return true;
    }

    si = 0, vid++;
    Euler(st);

    if (si != m)
    {
        return false;
    }

    reverse(ans, ans + si);
    return true;
}

int main()
{
    cin >> n;

    return 0;
}