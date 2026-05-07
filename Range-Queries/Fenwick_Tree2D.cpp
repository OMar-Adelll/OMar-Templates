// بسم الله الرحمن الرحيم
// وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ
// Free Palestine
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)x.size()
#define nl '\n'

// based-1
template <typename T>
class Fenwick_Tree2D
{
private:
    vector<vector<T>> BIT;
    int n, m;

public:
    Fenwick_Tree2D() = default;

    Fenwick_Tree2D(int n, int m)
    {
        this->n = n;
        this->m = m;
        BIT.assign(n + 5, vector<T>(m + 5, 0));
    }

    Fenwick_Tree2D(vector<vector<T>> &arr) : Fenwick_Tree2D(sz(arr), sz(arr[0]))
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                update(i, j, arr[i - 1][j - 1]);
    }

    // Update value at (x, y) by delta
    void update(int x, int y, T d)
    {
        for (int i = x; i <= n; i += (i & -i))
            for (int j = y; j <= m; j += (j & -j))
                BIT[i][j] += d;
    }

    // Query sum from (1,1) to (x,y)
    T query(int x, int y)
    {
        T ans = 0;
        for (int i = x; i > 0; i -= (i & -i))
            for (int j = y; j > 0; j -= (j & -j))
                ans += BIT[i][j];

        return ans;
    }

    T query(int x1, int y1, int x2, int y2) { return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1); }
};

int main()
{

    return 0;
}