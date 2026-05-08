// بسم الله الرحمن الرحيم
// وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ
// Free Palestine
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)x.size()
#define nl '\n'
#define all(x) x.begin(), x.end()

// 1-based (query / update --> log^2(n))
struct Node
{
    vector<int> vec;

    Node(const vector<int> &v = vector<int>()) : vec(v) {}

    Node operator=(const int rhs)
    {
        vec = vector<int>(1, rhs);
        return *this;
    }
};

class Segment_Tree
{
private:
    vector<Node> tree;
    int size;

    void init(const vector<int> &nums, int id, int lx, int rx)
    {
        if (lx == rx)
        {
            if (lx <= sz(nums))
                tree[id] = nums[lx - 1];
            return;
        }

        int mid = (lx + rx) / 2;
        init(nums, 2 * id, lx, mid);
        init(nums, 2 * id + 1, mid + 1, rx);

        tree[id] = merge(tree[2 * id], tree[2 * id + 1]);
    }

    Node merge(Node &l, Node &r)
    {
        int i = 0, j = 0;
        Node res;
        while (i < sz(l.vec) && j < sz(r.vec))
        {
            if (l.vec[i] < r.vec[j])
                res.vec.push_back(l.vec[i++]);
            else
                res.vec.push_back(r.vec[j++]);
        }

        while (i < sz(l.vec))
            res.vec.push_back(l.vec[i++]);
        while (j < sz(r.vec))
            res.vec.push_back(r.vec[j++]);

        return res;
    }

    void set(const int idx, const int v, int id, int lx, int rx)
    {
        if (lx == rx)
        {
            tree[id] = v;
            return;
        }

        int mid = (lx + rx) / 2;
        if (idx <= mid)
            set(idx, v, 2 * id, lx, mid);
        else
            set(idx, v, 2 * id + 1, mid + 1, rx);

        tree[id] = merge(tree[2 * id], tree[2 * id + 1]);
    }

    int query(const int l, const int r, const int k, int id, int lx, int rx)
    {
        if (r < lx || l > rx)
            return 0;
        if (lx >= l && rx <= r)
        {
            auto it = tree[id].vec.end() - upper_bound(all(tree[id].vec), k);
            return it;
        }

        int mid = (lx + rx) / 2;

        int ln = query(l, r, k, 2 * id, lx, mid);
        int rn = query(l, r, k, 2 * id + 1, mid + 1, rx);

        return ln + rn;
    }

public:
    Segment_Tree(int n = 0)
    {
        size = 1;
        while (size < n)
            size <<= 1;
        tree = vector<Node>(2 * size, Node());
    }

    void init(const vector<int> &nums)
    {
        init(nums, 1, 1, size);
    }

    void update(const int idx, int val)
    {
        set(idx, val, 1, 1, size);
    }

    int query(const int l, const int r, const int k)
    {
        return query(l, r, k, 1, 1, size);
    }
};

int main()
{

    return 0;
}