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
    int n, len, blocksNum;
    vector<int> arr, block;
    sqrt_decomposition(int si)
    {
        n = si;
        len = sqrt(si) + 1;
        blocksNum = n / len;
        arr.assign(n, 0);
        block.resize(len);
    }
    sqrt_decomposition(vector<int> &a)
    {
        n = a.size();
        len = sqrt(n) + 1;
        blocksNum = n / len;
        arr = a;
        block.resize(len);
        for (int i = 0; i < n; i++)
            block[i / len] += arr[i];
    }

    void update(int idx, int val)
    {
        block[idx / len] -= arr[idx];
        arr[idx] = val;
        block[idx / len] += arr[idx];
    }

    int query(int r)
    {
        if (r < 0)
            return 0;

        int ans = 0;
        for (int i = 0; i < (r / len); i++)
            ans += block[i];

        for (int i = (r / len) * len; i <= r && i < n; i++)
            ans += arr[i];

        return ans;
    }

    int query(const int l, const int r) { return query(r) - query(l - 1); }
};

int main()
{

    return 0;
}