#include <bits/stdc++.h>
using namespace std;

const int N = 6e5 + 1;

int C[N];
struct Tree {
    int max_val, val, lazy, pos;
} T[4 * N];

void Update_val(int id, int l, int r, int x, int u) {
    T[id].val = x + C[l] - C[u] + 1;
    T[id].max_val = max(T[id].max_val, x + C[r] - C[u] + 1);
    T[id].lazy = x;
    T[id].pos = u;
}

void Lazy(int id, int l, int r) {
    if (!T[id].pos) return;
    int mid = (l + r) / 2;
    Update_val(id * 2, l, mid, T[id].lazy, T[id].pos);
    Update_val(id * 2 + 1, mid + 1, r, T[id].lazy, T[id].pos);
    T[id].lazy = T[id].pos = 0;
}

void Update(int id, int l, int r, int u, int v, int x) {
    if (r < u || l > v) return;
    if (u <= l && r <= v) {
        Update_val(id, l, r, x, u);
        return;
    }
    int mid = (l + r) / 2;
    Lazy(id, l, r);
    Update(id * 2, l, mid, u, v, x);
    Update(id * 2 + 1, mid + 1, r, u, v, x);
    T[id].max_val = max(T[id].max_val, max(T[id * 2].max_val, T[id * 2 + 1].max_val));
    T[id].val = max(T[id].val, T[id * 2].val);
}

int Get(int id, int l, int r, int u) {
    if (l > u) return 0;
    if (r <= u) return T[id].max_val;
    int mid = (l + r) / 2;
    Lazy(id, l, r);
    return max(Get(id * 2, l, mid, u), Get(id * 2 + 1, mid + 1, r, u));
}

void solve() {
    int q;
    cin >> q;
    vector<int> num;
    vector<pair<int,int>> tv(q+1);

    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        tv[i] = {l, r};
        num.push_back(l);
        num.push_back(r);
        num.push_back(l - 1);
    }

    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());

    for (int i = 1; i <= q; i++) {
        int l = lower_bound(num.begin(), num.end(), tv[i].first) - num.begin() + 1;
        int r = lower_bound(num.begin(), num.end(), tv[i].second) - num.begin() + 1;
        C[l] = tv[i].first;
        C[l - 1] = tv[i].first - 1;
        C[r] = tv[i].second;
    }

    for (int i = 1; i <= q; i++) {
        int l = lower_bound(num.begin(), num.end(), tv[i].first) - num.begin() + 1;
        int r = lower_bound(num.begin(), num.end(), tv[i].second) - num.begin() + 1;
        int val = Get(1, 1, num.size(), l - 1);
        Update(1, 1, num.size(), l, r, val);
    }

    int ans = 0;
    for (int i = 1; i <= (int)num.size(); i++) {
        ans = max(ans, Get(1, 1, num.size(), i));
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
