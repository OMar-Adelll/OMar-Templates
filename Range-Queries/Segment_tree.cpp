// بسم الله الرحمن الرحيم
// وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) x.size()

struct Node
{
    int val;

    Node() { val = 0; }

    Node(int x) : val(x) {}

    void update(int x) { val += x; }
};

class Segment_Tree
{
private:
    int size;
    vector<Node> tree;
    void init(const vector<int> &nums, int id, int lx, int rx)
    {
        if (lx == rx)
        {
            if (lx <= sz(nums))
                tree[id] = Node(nums[lx - 1]);
            return;
        }

        int mid = (lx + rx) / 2;
        init(nums, 2 * id, lx, mid);
        init(nums, 2 * id + 1, mid + 1, rx);

        tree[id] = merge(tree[2 * id], tree[2 * id + 1]);
    }

    Node merge(Node &l, Node &r)
    {
        return Node(l.val + r.val);
    }

    void set(const int idx, const int v, int id, int lx, int rx)
    {
        if (lx == rx)
        {
            tree[id].val = v;
            return;
        }

        int mid = (lx + rx) / 2;
        if (idx <= mid)
            set(idx, v, 2 * id, lx, mid);
        else
            set(idx, v, 2 * id + 1, mid + 1, rx);

        tree[id] = merge(tree[2 * id], tree[2 * id + 1]);
    }

    Node get(const int l, const int r, int id, int lx, int rx)
    {
        if (l > rx || r < lx)
            return Node();

        if (l <= lx && r >= rx)
            return tree[id];

        int mid = (lx + rx) / 2;

        Node ln = get(l, r, 2 * id, lx, mid);
        Node rn = get(l, r, 2 * id + 1, mid + 1, rx);

        return merge(ln, rn);
    }

public:
    Segment_Tree(int n)
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

    void set(const int idx, const int v)
    {
        set(idx, v, 1, 1, size);
    }

    int get(const int l, const int r)
    {
        return get(l, r, 1, 1, size).val;
    }
};

int main()
{
    return 0;
}