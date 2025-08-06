#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    int n;
    vector<long long> tree;

public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    void build(const vector<int>& arr, int node, int l, int r) {
        if (l == r) {
            tree[node] = arr[l];
        } else {
            int mid = (l + r) / 2;
            build(arr, 2 * node, l, mid);
            build(arr, 2 * node + 1, mid + 1, r);
            tree[node] = tree[2 * node] + tree[2 * node + 1]; // min operation
        }
    }

    long long query(int ql, int qr) {
        return query(1, 0, n - 1, ql, qr);
    }

    long long query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0; // identity for min
        if (ql <= l && r <= qr) return tree[node];

        int mid = (l + r) / 2;
        return query(2 * node, l, mid, ql, qr)+
                   query(2 * node + 1, mid + 1, r, ql, qr);
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = val;
        } else {
            int mid = (l + r) / 2;
            if (idx <= mid)
                update(2 * node, l, mid, idx, val);
            else
                update(2 * node + 1, mid + 1, r, idx, val);

            tree[node] = tree[2 * node] + tree[2 * node + 1]; // min update
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int& x : arr) cin >> x;

    SegmentTree st(arr); 

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int k, u;
            cin >> k >> u;
            --k; // shift to 0-based index
            st.update(k, u); // point update
        } 
        else if (type == 2) {
            int a, b;
            cin >> a >> b;
            --a; --b; // shift both to 0-based range
            cout << st.query(a, b) << '\n'; // range minimum query
        }
    }

    return 0;
}

