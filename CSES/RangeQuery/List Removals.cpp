#include <bits/stdc++.h>
using namespace std;

class BIT {
public:
    vector<int> bit;
    int n;
    BIT(int size) {
        n = size;
        bit.assign(n + 1, 0);
    }
    void update(int i, int delta) {
        for (++i; i <= n; i += i & -i)
            bit[i] += delta;
    }
    int query(int i) {
        int res = 0;
        for (++i; i > 0; i -= i & -i)
            res += bit[i];
        return res;
    }
    // lower_bound: tìm chỉ số đầu tiên sao cho có >= k phần tử còn sống
    int findKth(int k) {
        int idx = 0, mask = 1 << 20;
        while (mask) {
            int t = idx + mask;
            if (t <= n && bit[t] < k) {
                k -= bit[t];
                idx = t;
            }
            mask >>= 1;
        }
        return idx; // đã -1 rồi nên không cần -1 nữa
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    BIT bit(n);
    for (int i = 0; i < n; i++)
        bit.update(i, 1); // tất cả phần tử còn sống ban đầu

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        int idx = bit.findKth(k);
        cout << a[idx] << " ";
        bit.update(idx, -1); // xóa phần tử ở vị trí idx
    }

    return 0;
}
