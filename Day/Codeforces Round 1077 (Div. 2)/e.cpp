#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Fenwick Tree để đếm nhanh
struct FenwickTree {
    int size;
    vector<int> tree;

    FenwickTree(int n) : size(n), tree(n + 1, 0) {}

    void add(int index, int value) {
        for (; index <= size; index += index & -index)
            tree[index] += value;
    }

    int query(int index) {
        int sum = 0;
        for (; index > 0; index -= index & -index)
            sum += tree[index];
        return sum;
    }

    // Xóa dữ liệu để dùng lại (tối ưu hơn tạo mới)
    void clear_history(const vector<int>& indices) {
        for (int idx : indices) {
            // Trừ đi chính giá trị đã thêm để về 0
            // Lưu ý: đây là cách reset cục bộ
            // Để đơn giản trong code mẫu, ta có thể dùng add(idx, -1) nếu biết chắc chỉ add +1
            for (int i = idx; i <= size; i += i & -i)
                tree[i] = 0;
        }
    }

    // Hàm reset đơn giản hơn cho bài này vì số lượng update ít
    void point_reset(int index) {
         for (; index <= size; index += index & -index)
            tree[index] = 0;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    // Thêm cạnh mặc định i -> i+1
    for (int i = 1; i < n; ++i) {
        adj[i].push_back(i + 1);
    }

    // Đọc cạnh thêm
    vector<vector<int>> incoming_jumps(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        incoming_jumps[v].push_back(u);
    }

    // Sắp xếp adj để tìm max và sec_max
    vector<int> sec_max(n + 1);
    for (int i = 1; i <= n; ++i) {
        sort(adj[i].begin(), adj[i].end());
        if (adj[i].size() >= 2) {
            // Phần tử lớn thứ 2 (phần tử cuối là lớn nhất)
            sec_max[i] = adj[i][adj[i].size() - 2];
        } else {
            // Nếu chỉ có 1 cạnh (i->i+1), coi như sec_max nhỏ vô cùng hoặc bằng chính nó
            // Để thỏa mãn điều kiện sec_max <= y (khi x < y), ta đặt sec_max = i
            sec_max[i] = i;
        }
    }

    long long ans = 0;

    // --- Trường hợp 1: x > y ---
    // Tom bắt Jerry nếu Tom có thể nhảy qua khoảng chứa Jerry
    for (int y = 1; y < n; ++y) {
        int v_max = adj[y].back();
        if (v_max > y + 1) {
            // Jerry ở các đỉnh từ y+1 đến v_max-1 đều bị "bao phủ"
            // Số lượng x thỏa mãn y < x < v_max
            ans += (long long)(v_max - 1 - y);
        }
    }

    // --- Trường hợp 2: x < y ---
    // Jerry nhảy đến v, Tom chặn tại v
    // Sử dụng BIT. Giá trị sec_max nằm trong khoảng [1, n].
    FenwickTree bit(n);

    for (int v = 3; v <= n; ++v) {
        if (incoming_jumps[v].empty()) continue;

        // Danh sách các u có thể nhảy tới v, đã sắp xếp tăng dần vì u < v và đọc/xử lý theo thứ tự?
        // Đề bài không đảm bảo thứ tự input, nên cần sort lại incoming_jumps[v]
        sort(incoming_jumps[v].begin(), incoming_jumps[v].end());

        vector<int> history; // Để reset BIT

        // Duyệt các u nhảy tới v
        for (int u : incoming_jumps[v]) {
            // 1. Coi u là y (Tom nhảy tới v để bắt)
            // Tìm số lượng x trước đó (trong cùng list nhảy tới v)
            // thỏa mãn x < u (đương nhiên vì u tăng dần) VÀ sec_max[x] <= u
            ans += bit.query(u);

            // 2. Coi u là x (Jerry nhảy tới v)
            // Cập nhật vào BIT để các y phía sau đếm
            bit.add(sec_max[u], 1);
            history.push_back(sec_max[u]);
        }

        // Reset BIT cho vòng lặp v tiếp theo
        for (int val : history) bit.point_reset(val);

        // 3. Xét trường hợp đặc biệt: y = v - 1 (Tom đi bộ từ y sang v)
        // y này không nằm trong incoming_jumps (vì đó là cạnh thường)
        // Tom ở y=v-1 chắc chắn bắt được bất kỳ x nào nhảy tới v
        // miễn là sec_max[x] <= y
        int y_walk = v - 1;
        // Duyệt lại các x trong danh sách nhảy (đây là các Jerry tiềm năng)
        // Dùng upper_bound để tìm các x < y_walk (thực ra tất cả u trong list đều < v, nên check u < v-1)
        for (int x : incoming_jumps[v]) {
            if (x < y_walk && sec_max[x] <= y_walk) {
                ans++;
            }
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
