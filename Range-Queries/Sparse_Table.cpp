// بسم الله الرحمن الرحيم
// وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) x.size()

class SparseTable
{
private:
    const int N = 500005;
    const int LOG = 23;
    vector<vector<int>> sparse;

    int merge(int x, int y)
    {
        return min(x, y);
    }

public:
    SparseTable()
    {
        sparse.assign(N, vector<int>(LOG, 0));
    }

    void build(vector<int> &nums)
    {
        int n = sz(nums);

        for (int i = 0; i < n; i++)
            sparse[i][0] = nums[i];

        for (int k = 1; k < LOG; k++)
        {
            for (int i = 0; i + (1 << k) <= n; i++)
            {
                sparse[i][k] = merge(sparse[i][k - 1], sparse[i + (1LL << (k - 1))][k - 1]);
            }
        }
    }

    int query(int l, int r)
    {
        int len = r - l + 1;
        int ans = LLONG_MAX;
        for (int i = LOG - 1; i >= 0; i--)
        {
            if (len & (1LL << i))
            {
                ans = merge(ans, sparse[l][i]);
                l += (1LL << i);
            }
        }
        return ans;
    }

    int One_query(int l, int r)
    {
        /*
              Works only for idempotent associative operations,
              where overlapping segments do not affect the result.
              - Works on ( Minimum, Maximum, Gcd, And, Or, .... ).
              - Doesn't work on ( Sum, XOR, Product ...... ).
        */
        int len = r - l + 1;
        int k = 63 - __builtin_clzll(len);
        int ans = merge(sparse[l][k], sparse[r - (1LL << k) + 1][k]);
        return ans;
    }
};

int main()
{
    return 0;
}