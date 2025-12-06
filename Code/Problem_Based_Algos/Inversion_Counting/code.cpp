// Author: coolavy
// Language: C++
// Date: 12/6/2025

#include "bits/stdc++.h"
using namespace std;

// Mergesort solution
long long merge(vector<int> &a, int l, int mid, int r) {
    vector<int> la(a.begin() + l, a.begin() + mid + 1);
    vector<int> ra(a.begin() + mid + 1, a.begin() + r + 1);

    int i = 0, j = 0, k = l;
    long long ans = 0;

    while (i < (int)la.size() && j < (int)ra.size()) {
        if (la[i] <= ra[j]) {
            a[k++] = la[i++];
        } else {
            a[k++] = ra[j++];
            ans += (la.size() - i);
        }
    }

    while (i < (int)la.size()) a[k++] = la[i++];
    while (j < (int)ra.size()) a[k++] = ra[j++];

    return ans;
}

long long inv_merge(vector<int> &a, int l, int r) {
    if (l >= r) return 0;

    int mid = l + (r - l) / 2;
    long long ans = 0;

    ans += inv_merge(a, l, mid);
    ans += inv_merge(a, mid + 1, r);
    ans += merge(a, l, mid, r);

    return ans;
}

// Segment Tree solution
class SegTree {
public:
    int n;
    vector<int> st;

    SegTree(int sz) {
        n = sz;
        st.assign(4 * sz, 0);
    }

    int comb(int a, int b) {
        return a + b;
    }

    void op(int x, int a) {
        st[x] += a;
    }

    void build(vector<int> &a, int x, int lx, int rx) {
        if (lx == rx) {
            st[x] = a[lx];
            return;
        }
        int mid = (lx + rx) >> 1;
        build(a, 2 * x, lx, mid);
        build(a, 2 * x + 1, mid + 1, rx);
        st[x] = comb(st[2 * x], st[2 * x + 1]);
    }

    void build(vector<int> &a) {
        build(a, 1, 0, n - 1);
    }

    void update(int l, int r, int v, int x, int lx, int rx) {
        if (r < lx || l > rx) return;

        if (lx == rx) {
            op(x, v);
            return;
        }

        int mid = (lx + rx) >> 1;
        update(l, r, v, 2 * x, lx, mid);
        update(l, r, v, 2 * x + 1, mid + 1, rx);

        st[x] = comb(st[2 * x], st[2 * x + 1]);
    }

    void update(int l, int r, int v) {
        update(l, r, v, 1, 0, n - 1);
    }

    int query(int l, int r, int x, int lx, int rx) {
        if (r < lx || l > rx) return 0;

        if (l <= lx && rx <= r) {
            return st[x];
        }

        int mid = (lx + rx) >> 1;
        return comb(
            query(l, r, 2 * x, lx, mid),
            query(l, r, 2 * x + 1, mid + 1, rx)
        );
    }

    int query(int l, int r) {
        return query(l, r, 1, 0, n - 1);
    }
};

// Driver code for SegTree solution, problem link is in README.md
// Driver code using Mergesort is just using inv_merge
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int T; 
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        // Coordinate compression
        vector<int> b = a;
        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end());

        vector<int> comp(n);
        for (int i = 0; i < n; i++) {
            comp[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        }

        int m = b.size();
        SegTree st(m);

        long long inv = 0;

        for (int i = 0; i < n; i++) {
            int x = comp[i];

            if (x + 1 <= m - 1)
                inv += st.query(x + 1, m - 1);

            st.update(x, x, 1);
        }

        cout << inv << "\n";
    }

    return 0;
}