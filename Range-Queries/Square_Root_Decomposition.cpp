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
    vector<int> arr, block;
    sqrt_decomposition(int N)
    {
        n = N;
        SQ = sqrt(N) + 1;
        BlocksNum = (n + SQ - 1) / SQ;

        arr.assign(N, 0);
        block.assign(BlocksNum, 0);
    }

    sqrt_decomposition(vector<int> &nums)
    {
        n = nums.size();
        SQ = sqrt(n) + 1;
        BlocksNum = (n + SQ - 1) / SQ;

        arr = nums;
        block.assign(BlocksNum, 0);
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
                ans += arr[i];
            return ans;
        }

        for (int i = st + 1; i < en; i++)
            ans += block[i];

        for (int i = l; i < (st + 1) * SQ && i < n; i++)
            ans += arr[i];

        for (int i = en * SQ; i <= r && i < n; i++)
            ans += arr[i];

        return ans;
    }
};

int main()
{

    return 0;
}