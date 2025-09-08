#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
protected:
    struct Node
    {
        vector<int> Ls, Rs, sufMinR;
    };

    int n, SZ;
    vector<Node> seg;
    const int INF = 1e9;

    virtual void buildUp(int v)
    {
        const auto &L1 = seg[v << 1].Ls, &R1 = seg[v << 1].Rs;
        const auto &L2 = seg[v << 1 | 1].Ls, &R2 = seg[v << 1 | 1].Rs;
        auto &Lout = seg[v].Ls;
        auto &Rout = seg[v].Rs;
        auto &S = seg[v].sufMinR;

        Lout.resize(L1.size() + L2.size());
        Rout.resize(R1.size() + R2.size());

        size_t i = 0, j = 0, k = 0;
        while (i < L1.size() || j < L2.size())
        {
            if (j == L2.size() || (i < L1.size() && L1[i] <= L2[j]))
            {
                Lout[k] = L1[i];
                Rout[k] = R1[i];
                ++i;
                ++k;
            }
            else
            {
                Lout[k] = L2[j];
                Rout[k] = R2[j];
                ++j;
                ++k;
            }
        }

        S.resize(Rout.size());
        if (!Rout.empty())
        {
            S.back() = Rout.back();
            for (int t = (int)Rout.size() - 2; t >= 0; --t)
            {
                S[t] = min(Rout[t], S[t + 1]);
            }
        }
    }

public:
    SegmentTree(int n_) : n(n_)
    {
        SZ = 1;
        while (SZ < n) SZ <<= 1;
        seg.resize(2 * SZ);
    }

    int getMinR(int v, int tl, int tr, int l, int r, int Lthresh)
    {
        if (l > tr || r < tl) return INF;
        if (l <= tl && tr <= r)
        {
            const auto &Ls = seg[v].Ls;
            if (Ls.empty()) return INF;
            auto it = lower_bound(Ls.begin(), Ls.end(), Lthresh);
            if (it == Ls.end()) return INF;
            int idx = int(it - Ls.begin());
            return seg[v].sufMinR[idx];
        }
        int tm = (tl + tr) >> 1;
        int left = getMinR(v << 1, tl, tm, l, r, Lthresh);
        int right = getMinR(v << 1 | 1, tm + 1, tr, l, r, Lthresh);
        return min(left, right);
    }
};

class Solution : public SegmentTree
{
    vector<int> a, L, R;

public:
    Solution(const vector<int> &arr) : SegmentTree(arr.size() - 1), a(arr), L(n + 1), R(n + 1)
    {
        buildLR();
        buildSegTree();
    }

    void buildLR()
    {
        vector<int> st;
        for (int i = 1; i <= n; ++i)
        {
            while (!st.empty() && a[st.back()] <= a[i]) st.pop_back();
            L[i] = st.empty() ? 0 : st.back();
            st.push_back(i);
        }

        st.clear();
        for (int i = n; i >= 1; --i)
        {
            while (!st.empty() && a[st.back()] >= a[i]) st.pop_back();
            R[i] = st.empty() ? n + 1 : st.back();
            st.push_back(i);
        }
    }

    void buildSegTree()
    {
        for (int i = 1; i <= n; ++i)
        {
            int v = SZ + i - 1;
            seg[v].Ls = { L[i] };
            seg[v].Rs = { R[i] };
            seg[v].sufMinR = { R[i] };
        }

        for (int i = n + 1; i <= SZ; ++i)
        {
            int v = SZ + i - 1;
            seg[v].Ls.clear();
            seg[v].Rs.clear();
            seg[v].sufMinR.clear();
        }

        for (int v = SZ - 1; v >= 1; --v) buildUp(v);
    }

    bool query(int l, int r)
    {
        if (r - l + 1 < 3) return true;
        int mnR = getMinR(1, 1, SZ, l, r, l);
        return mnR > r;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            cin >> arr[i];
        }

        Solution sol(arr);

        while (q--)
        {
            int l, r;
            cin >> l >> r;
            cout << (sol.query(l, r) ? "YES\n" : "NO\n");
        }
    }
    return 0;
}
