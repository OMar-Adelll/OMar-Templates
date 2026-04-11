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
    int n, SQ, BlocksNum;
    vector<int> arr, block, lazy;
    sqrt_decomposition(int N)
    {
        n = N;
        SQ = sqrt(N) + 1;
        BlocksNum = (n + SQ - 1) / SQ;

        arr.assign(N, 0);
        block.assign(BlocksNum, 0);
        lazy.assign(BlocksNum, 0);
    }

    sqrt_decomposition(vector<int> &nums)
    {
        n = nums.size();
        SQ = sqrt(n) + 1;
        BlocksNum = (n + SQ - 1) / SQ;

        arr = nums;
        block.assign(BlocksNum, 0);
        lazy.assign(BlocksNum, 0);

        for (int i = 0; i < n; i++)
            block[i / SQ] += arr[i];
    }

    void init(int idx)
    {
        block[idx] = 0;
        int l = idx * SQ;
        int r = min(n - 1, l + SQ - 1);
        for (int i = l; i <= r; i++)
            block[idx] += arr[i];
    }

    void propegate(int idx)
    {
        if (lazy[idx] == 0)
            return;

        int l = idx * SQ;
        int r = min(n - 1, l + SQ - 1);
        for (int i = l; i <= r; i++)
            arr[i] += lazy[idx];

        block[idx] += lazy[idx] * (r - l + 1);
        lazy[idx] = 0;
    }

    void update(int l, int r, int x)
    {
        int st = l / SQ;
        int en = r / SQ;

        if (st == en)
        {
            propegate(st);
            for (int i = l; i <= r && i < n; i++)
                arr[i] += x;
            init(st);
            return;
        }

        propegate(st);
        propegate(en);

        for (int i = l; i < (st + 1) * SQ; i++)
            arr[i] += x;
        init(st);

        for (int i = st + 1; i < en; i++)
            lazy[i] += x;

        for (int i = en * SQ; i <= r && i < n; i++)
            arr[i] += x;
        init(en);
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

    int query(int l, int r)
    {
        if (l > r)
            return 0;

        int st = l / SQ;
        int en = r / SQ;

        int ans = 0;
        if (st == en)
        {
            for (int i = l; i <= r; i++)
                ans += arr[i] + lazy[st];
            return ans;
        }

        for (int i = st + 1; i < en; i++)
        {
            int si = min(n - 1, (i + 1) * SQ) - i * SQ;
            ans += block[i] + lazy[i] * si;
        }

        for (int i = l; i < (st + 1) * SQ && i < n; i++)
            ans += arr[i] + lazy[st];

        for (int i = en * SQ; i <= r && i < n; i++)
            ans += arr[i] + lazy[en];

        return ans;
    }
};

int main()
{

    return 0;
}