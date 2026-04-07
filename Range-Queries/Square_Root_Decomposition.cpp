// بسم الله الرحمن الرحيم
// وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ
// Free Palestine
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)x.size()
#define nl '\n'

struct sqrt_decomposition
{
    int n, SQ, blocksNum;
    vector<int> arr, block;
    sqrt_decomposition(int si)
    {
        n = si;
        SQ = sqrt(si) + 1;
        blocksNum = (n + SQ - 1) / SQ;

        arr.assign(n, 0);
        block.resize(blocksNum);
    }
    sqrt_decomposition(vector<int> &a)
    {
        n = a.size();
        SQ = sqrt(n) + 1;
        blocksNum = (n + SQ - 1) / SQ;

        arr = a;
        block.resize(blocksNum);
        for (int i = 0; i < n; i++)
            block[i / SQ] += arr[i];
    }

    void update(int idx, int val)
    {
        block[idx / SQ] -= arr[idx];
        arr[idx] = val;
        block[idx / SQ] += arr[idx];
    }

    int query(int r)
    {
        if (r < 0)
            return 0;

        int ans = 0;
        for (int i = 0; i < (r / SQ); i++)
            ans += block[i];

        for (int i = (r / SQ) * SQ; i <= r && i < n; i++)
            ans += arr[i];

        return ans;
    }

    int query(const int l, const int r) { return query(r) - query(l - 1); }
};

int main()
{

    return 0;
}