#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>

void solve() {
    long long n;
    int m;
    std::cin >> n >> m;

    if (n == 1) {
        std::cout << 0 << std::endl;
        return;
    }

    // Vector để lưu dãy kết quả
    std::vector<long long> a(n);
    // Vector để lưu các giá trị riêng biệt đã sử dụng
    std::vector<long long> distinct_values;

    // Bước 1: Tạo m-1 phần tử đầu tiên
    a[0] = 0;
    distinct_values.push_back(0);
    for (int i = 1; i < m - 1; ++i) {
        a[i] = a[i - 1] + i;
        distinct_values.push_back(a[i]);
    }

    long long last_jump = m - 2;

    // Bước 2: Tạo các phần tử còn lại một cách tham lam
    for (int i = m - 1; i < n; ++i) {
        long long prev_val = a[i - 1];
        long long best_next_val = -1;
        long long min_jump = -1;

        // Tìm trong các giá trị đã có
        for (long long val : distinct_values) {
            long long current_jump = std::abs(val - prev_val);
            if (current_jump > last_jump) {
                if (min_jump == -1 || current_jump < min_jump) {
                    min_jump = current_jump;
                    best_next_val = val;
                }
            }
        }

        // Nếu có thể, thử sử dụng giá trị riêng biệt thứ m
        if (distinct_values.size() < m) {
            // Thử nhảy tiến và nhảy lùi để tìm bước nhảy tốt nhất
            long long jump_candidate_fwd = last_jump + 1;
            long long val_candidate_fwd = prev_val + jump_candidate_fwd;

            long long jump_candidate_back = last_jump + 1;
            long long val_candidate_back = prev_val - jump_candidate_back;

            if (min_jump == -1 || jump_candidate_fwd < min_jump) {
                 min_jump = jump_candidate_fwd;
                 best_next_val = val_candidate_fwd;
            }
            // So sánh với bước nhảy lùi (chỉ để chắc chắn)
            if (min_jump == -1 || jump_candidate_back < min_jump) {
                 min_jump = jump_candidate_back;
                 best_next_val = val_candidate_back;
            }
        }

        a[i] = best_next_val;
        last_jump = min_jump;

        // Thêm giá trị mới vào tập nếu nó chưa tồn tại
        bool found = false;
        for(long long val : distinct_values) {
            if (val == best_next_val) {
                found = true;
                break;
            }
        }
        if (!found) {
            distinct_values.push_back(best_next_val);
        }
    }

    // In kết quả
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << (i == n - 1 ? "" : " ");
    }
    std::cout << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    // Vì chỉ có 2 test case, ta không cần vòng lặp test case
    solve();
    return 0;
}
