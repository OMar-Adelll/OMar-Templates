// بسم الله الرحمن الرحيم
// وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ
// Free Palestine
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)x.size()
#define nl '\n'

// NOTE :  to make update you will change log(n) nodes only
// 1-based indexing
template <typename T>
class PST
{
private:
    // Node's data
    struct Node
    {
        T val;
        Node *left, *right;

        Node(T val = 0)
        {
            this->val = val;
            left = right = nullptr;
        }

        Node(Node *node, Node *l = nullptr, Node *r = nullptr)
        {
            val = node ? node->val : 0;
            left = l ? l : (node ? node->left : nullptr);
            right = r ? r : (node ? node->right : nullptr);
        }
    };

    // PST
    vector<Node *> roots;
    int n;
    T Lx, Rx;

    Node *build(const vector<T> &nums, T lx, T rx)
    {
        if (lx == rx)
            return new Node(nums[lx - 1]);

        int mid = lx + (rx - lx) / 2;

        Node *L = build(nums, lx, mid);
        Node *R = build(nums, mid + 1, rx);

        return new Node(merge(L, R), L, R);
    }

    Node *merge(Node *l, Node *r)
    {
        Node *node = new Node();
        node->val = l->val + r->val;
        return node;
    }

    Node *update(Node *root, int idx, T val, T lx, T rx)
    {
        if (idx < lx || idx > rx)
            return root;

        if (lx == rx)
            return new Node(root->val + val);

        int mid = lx + (rx - lx) / 2;
        Node *L = update(root->left, idx, val, lx, mid);
        Node *R = update(root->right, idx, val, mid + 1, rx);

        return new Node(merge(L, R), L, R);
    }

    Node *query(Node *root, int l, int r, int lx, int rx)
    {
        if (!root || r < lx || l > rx)
            return new Node();

        if (lx >= l && rx <= r)
            return root;

        int mid = lx + (rx - lx) / 2;
        Node *L = query(root->left, l, r, lx, mid);
        Node *R = query(root->right, l, r, mid + 1, rx);

        return merge(L, R);
    }

    int count_greater(Node *l, Node *r, int k, int lx, int rx)
    {
        if (k < lx)
            return r->val - l->val;

        if (k >= rx)
            return 0;

        int mid = lx + (rx - lx) / 2;

        return count_greater(l->left, r->left, k, lx, mid) + count_greater(l->right, r->right, k, mid + 1, rx);
    }

    T kth(Node *l, Node *r, int k, T lx, T rx)
    {
        if (lx == rx)
            return lx;
        T m = lx + (rx - lx) / 2;
        int count = r->left->val - l->left->val; // Count of elements in the left subtree
        if (count >= k)
            return kth(l->left, r->left, k, lx, m);
        else
            return kth(l->right, r->right, k - count, m + 1, rx);
    }

public:
    PST(int n = 0, T lx = -1e9, T rx = 1e9) : n(n), Lx(lx), Rx(rx) {}

    // use build if the nums represents the frequency of the elements
    // and the elements are in the range [1, n]
    void build(const vector<T> &nums) { roots.push_back(build(nums, Lx, Rx)); }

    void update(int idx, T val) { roots.push_back(update(roots.back(), idx, val, Lx, Rx)); }

    // roots is 0-based (use k - 1 not k)
    void update_version(int idx, T val, int version) { roots[version] = update(roots[version], idx, val, Lx, Rx); }

    // roots is 0-based (use k - 1 not k)
    T query(const int l, const int r, const int version) { return query(roots[version], l, r, Lx, Rx)->val; }

    // clones a version and pushes it into PST
    void clone(const int version) { roots.push_back(roots[version]); }

    // count the number of elements greater than k in the range [l, r]
    int count_greater(int l, int r, int k) { return count_greater(roots[l - 1], roots[r], k, Lx, Rx); }

    // find index of the k-th smallest element in the range [l, r]
    T kth(int l, int r, int k) { return kth(roots[l - 1], roots[r], k, Lx, Rx); }
};


int main()
{

    int n;
    cin >> n;

    // How to init
    PST<int> pst(n, 1, n);

    return 0;
}