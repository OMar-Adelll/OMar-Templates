// بسم الله الرحمن الرحيم
// وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ
// Free Palestine
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)x.size()
#define nl '\n'

const int N = 200000 + 5;
const int SQ = 450;


struct Query
{
    int l, r, q_idx, blk_idx;
    Query() {}
    Query(int L, int R, int Idx) { l = L, r = R, q_idx = Idx, blk_idx = L / SQ; }
    bool operator<(const Query &other) const
    {
        if (blk_idx != other.blk_idx)
            return blk_idx < other.blk_idx;

        return r < other.r;
    }
};

ll n, q, arr[N], ans[N];
Query query[N];

// Change these depending on problem
ll res = 0;
ll vis[1000006];

void add(int idx)
{
    if (!vis[arr[idx]])
        res++;

    vis[arr[idx]]++;
}

void remove(int idx)
{
    vis[arr[idx]]--;
    if (!vis[arr[idx]])
        res--;
}

void MO()
{
    sort(query, query + q);
    int L = 1, R = 0;
    for (int i = 0; i < q; i++)
    {
        int l = query[i].l;
        int r = query[i].r;

        while (L < l)
            remove(L++);
        while (L > l)
            add(--L);
        while (R < r)
            add(++R);
        while (R > r)
            remove(R--);

        ans[query[i].q_idx] = res;
    }
}

int main()
{

    return 0;
}
