#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, d;
    if (!(cin >> n >> d)) return;

    vector<int> a(n), b(n);
    vector<int> posA(n + 1), posB(n + 1);

    // Đọc a và lưu vị trí posA
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        posA[a[i]] = i;
    }

    // Đọc b và lưu vị trí posB
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        posB[b[i]] = i;
    }

    // Khởi tạo mảng C: C[i] là vị trí của bài hát b[i] trong playlist a
    vector<int> C(n);
    long long K = 0;
    for (int i = 0; i < n; ++i) {
        C[i] = posA[b[i]];
    }

    // Đếm số điểm gãy K ban đầu
    for (int i = 0; i < n - 1; ++i) {
        if (C[i] > C[i + 1]) K++;
    }

    // Hàm lambda để tính đáp án cực gọn
    auto get_ans = [&]() {
        return 1LL * C[n - 1] + 1LL * n * K - n + 1;
    };

    // In ra kết quả của ngày đầu tiên (trước khi có bất kỳ update nào)
    cout << get_ans() << "\n";

    // Xử lý các ngày tiếp theo
    for (int day = 1; day < d; ++day) {
        int type, x, y;
        cin >> type >> x >> y;
        x--; y--; // Chuyển sang 0-indexed

        vector<int> affected;
        int p1 = -1, p2 = -1;

        if (type == 1) {
            // Đổi chỗ a[x] và a[y].
            // Bài hát a[x] và a[y] thay đổi vị trí, tức là vị trí của chúng trong mảng C thay đổi.
            int s1 = a[x], s2 = a[y];
            p1 = posB[s1];
            p2 = posB[s2];
        } else {
            // Đổi chỗ b[x] và b[y].
            // Rất đơn giản, 2 vị trí x và y trong mảng C sẽ thay đổi.
            p1 = x;
            p2 = y;
        }

        // Tìm các cặp (i, i+1) bị ảnh hưởng để cập nhật K
        for (int p : {p1, p2}) {
            if (p > 0) affected.push_back(p - 1);
            if (p < n - 1) affected.push_back(p);
        }

        // Sắp xếp và loại bỏ trùng lặp (tránh trừ/cộng K nhiều lần ở cặp giao nhau)
        sort(affected.begin(), affected.end());
        affected.erase(unique(affected.begin(), affected.end()), affected.end());

        // BƯỚC 1: Xóa đóng góp K của các vị trí cũ
        for (int i : affected) {
            if (C[i] > C[i + 1]) K--;
        }

        // BƯỚC 2: Cập nhật dữ liệu
        if (type == 1) {
            int s1 = a[x], s2 = a[y];
            swap(a[x], a[y]);
            posA[s1] = y;
            posA[s2] = x;
            C[p1] = posA[s1];
            C[p2] = posA[s2];
        } else {
            int s1 = b[x], s2 = b[y];
            swap(b[x], b[y]);
            posB[s1] = y;
            posB[s2] = x;
            C[p1] = posA[b[p1]];
            C[p2] = posA[b[p2]];
        }

        // BƯỚC 3: Thêm đóng góp K của các vị trí mới
        for (int i : affected) {
            if (C[i] > C[i + 1]) K++;
        }

        // In ra kết quả ngày mới
        cout << get_ans() << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
