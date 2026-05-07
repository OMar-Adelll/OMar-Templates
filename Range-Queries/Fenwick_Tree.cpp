// بسم الله الرحمن الرحيم
// وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ
// Free Palestine
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)x.size()
#define nl '\n'

/*
    [1] Point update and Range Query
        - Normal Fenwick tree
    [2] Range update and point Query
        - if you will store array don't forget this add(l, val) , add(r + 1 , -val)
    [3] Range update and Range Query
        - into update range : add(l, x,  x * (l - 1)) , add(r + 1, -x , -x * r)
        - into query : ans += BIT1[i] * idx + BIT2[i]

*/

// based-1
template <typename T>
class Fenwick_Tree
{
private:
    vector<T> BIT;
    int n;

public:
    Fenwick_Tree() = default;

    Fenwick_Tree(int n)
    {
        this->n = n;
        BIT.assign(n + 5, 0);
    }

    Fenwick_Tree(vector<T> &arr) : Fenwick_Tree(sz(arr))
    {
        for (int i = 1; i <= n; i++)
            add(i, arr[i - 1]);
    }

    void assign(int idx, T val)
    {
        T prv = query(idx, idx);
        add(idx, val - prv);
    }

    void add(int idx, int v) // update point
    {
        for (; idx <= n; idx += (idx & -idx))
            BIT[idx] += v;
    }

    T query(int idx) // prefix sum
    {
        T ans = 0;
        for (int i = idx; i; i -= (i & -i))
            ans += BIT[i];

        return ans;
    }

    T query(const int l, const int r) { return query(r) - query(l - 1); }
    void update_range(const int l, const int r, const int val)
    {
        add(l, val, val);
        add(r + 1, -val);
    }

    int lower_bound(int x)
    {
        int mask = 1, idx = 0;
        while (mask < n)
            mask <<= 1;
        for (mask >>= 1; mask; mask >>= 1)
        {
            int nxt = idx + mask;
            if (nxt <= n && BIT[nxt] < x)
            {
                x -= BIT[nxt];
                idx = nxt;
            }
        }

        return idx + 1;
    }

    int upper_bound(int x)

    {
        int mask = 1, idx = 0;
        while (mask < n)
            mask <<= 1;
        for (mask >>= 1; mask; mask >>= 1)
        {
            int nxt = idx + mask;
            if (nxt <= n && BIT[nxt] <= x)
            {
                x -= BIT[nxt];
                idx = nxt;
            }
        }

        return idx + 1;
    }
};

int main()
{
    Fenwick_Tree<int> tree({});

    return 0;
}