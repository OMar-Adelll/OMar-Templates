// بسم الله الرحمن الرحيم
// وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ
// Free Palestine
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)x.size()
#define nl '\n'

// 1-based index
template <typename T>
class PST
{
private:
    // Node's data
    struct Node
    {
        T sum;
        T lazy;
        Node *left, *right;
        Node(T val = 0) : sum(val), lazy(0), left(nullptr), right(nullptr) {}
    };

    // PST
    Node *build(const vector<T> &a, int l, int r)
    {
        Node *node = new Node();
        if (l == r)
        {
            node->sum = a[l - 1];
        }
        else
        {
            int mid = (l + r) / 2;
            node->left = build(a, l, mid);
            node->right = build(a, mid + 1, r);
            node->sum = node->left->sum + node->right->sum;
        }
        return node;
    }

    // Propagate lazy tag to children (clones children nodes for persistence)
    void propagate(Node *node, int l, int r)
    {
        if (node->lazy != 0 && l != r)
        {
            int mid = (l + r) / 2;
            node->left = new Node(*node->left);
            node->right = new Node(*node->right);
            node->left->lazy += node->lazy;
            node->right->lazy += node->lazy;
            node->left->sum += node->lazy * (mid - l + 1);
            node->right->sum += node->lazy * (r - mid);
            node->lazy = 0;
        }
    }

    // Update returns a new version of the node after adding val to [lx, rx]
    Node *update(Node *prev, int l, int r, int lx, int rx, T val)
    {
        if (r < lx || l > rx)
            return prev;
        Node *cur = new Node(*prev);
        if (lx <= l && r <= rx)
        {
            cur->lazy += val;
            cur->sum += val * (r - l + 1);
            return cur;
        }
        propagate(cur, l, r);
        int mid = (l + r) / 2;
        cur->left = update(cur->left, l, mid, lx, rx, val);
        cur->right = update(cur->right, mid + 1, r, lx, rx, val);
        cur->sum = cur->left->sum + cur->right->sum;
        return cur;
    }

    // Query the sum on the interval [lx, rx] in the tree rooted at node
    T query(Node *node, int l, int r, int lx, int rx)
    {
        if (r < lx || l > rx)
            return 0;
        if (lx <= l && r <= rx)
            return node->sum;
        propagate(node, l, r);
        int mid = (l + r) / 2;
        return query(node->left, l, mid, lx, rx) + query(node->right, mid + 1, r, lx, rx);
    }

public:
    int n;
    Node *root;
    vector<Node *> versions = {new Node()};
    PST(const vector<T> &a) : n(a.size())
    {
        root = build(a, 1, n);
        versions[0] = root;
    }

    // Wrapper for update (returns new root)
    void range_update(int l, int r, T val)
    {
        Node *new_root = update(versions.back(), 1, n, l, r, val);
        versions.push_back(new_root);
    }

    // Wrapper for query on the root
    T range_query(int l, int r, int cur_version = -1)
    {
        if (cur_version == -1)
            cur_version = versions.size() - 1;
        return query(versions[cur_version], 1, n, l, r);
    }

    // rollback to version v
    void rollback(int v) { versions.resize(v + 1); }
};

int main()
{

    return 0;
}