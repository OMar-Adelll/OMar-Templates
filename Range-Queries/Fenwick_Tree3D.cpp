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
class Fenwick_Tree3D
{
private:
    vector<vector<vector<T>>> BIT;
    int n, m, p;

public:
    Fenwick_Tree3D() = default;

    Fenwick_Tree3D(int n, int m, int p)
    {
        this->n = n;
        this->m = m;
        this->p = p;
        BIT.assign(n + 5, vector<vector<T>>(m + 5, vector<T>(p + 5, 0)));
    }

    Fenwick_Tree3D(vector<vector<vector<T>>> &arr) : Fenwick_Tree3D(sz(arr), sz(arr[0]), sz(arr[0][0]))
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                for (int k = 1; k <= p; k++)
                    update(i, j, k, arr[i - 1][j - 1][k - 1]);
    }

    // Update value at (x, y) by delta
    void update(int x, int y, int z, T d)
    {
        for (int i = x; i <= n; i += (i & -i))
            for (int j = y; j <= m; j += (j & -j))
                for (int k = z; k <= p; k += (k & -k))
                    BIT[i][j][k] += d;
    }

    // Query sum from (1,1) to (x,y)
    T query(int x, int y, int z)
    {
        T ans = 0;
        for (int i = x; i > 0; i -= (i & -i))
            for (int j = y; j > 0; j -= (j & -j))
                for (int k = z; k > 0; k -= (k & -k))
                    ans += BIT[i][j][k];

        return ans;
    }

    T query(int x1, int y1, int z1, int x2, int y2, int z2) { return query(x2, y2, z2) - query(x1 - 1, y2, z2) - query(x2, y1 - 1, z2) - query(x2, y2, z1 - 1) + query(x1 - 1, y1 - 1, z2) + query(x1 - 1, y2, z1 - 1) + query(x2, y1 - 1, z1 - 1) - query(x1 - 1, y1 - 1, z1 - 1); }
};

int main()
{
    
    return 0;
}