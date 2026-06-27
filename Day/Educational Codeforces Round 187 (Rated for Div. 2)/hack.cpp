#include <iostream>
#include <set>
#include <queue>

using namespace std;

// Hàm mô phỏng lại cách code kia cắt mảng để đếm số lượng "Group" sinh ra
int get_distinct_group_size(int n) {
    set<int> s;
    queue<int> q;
    q.push(n);
    s.insert(n);

    while(!q.empty()){
        int x = q.front(); q.pop();
        if(x <= 1) continue;

        int left_size = (x - 1) / 2;
        int right_size = x / 2;

        if(left_size > 0 && s.find(left_size) == s.end()) {
            s.insert(left_size);
            q.push(left_size);
        }
        if(right_size > 0 && s.find(right_size) == s.end()) {
            s.insert(right_size);
            q.push(right_size);
        }
    }
    return s.size();
}

int main() {
    // CHÚ Ý: Đổi MAX_N thành giới hạn tối đa của bài toán trên Codeforces
    // (Thường là 1000000, 500000 hoặc 300000)
    int MAX_N = 1000000;

    int best_n = MAX_N;
    int max_groups = 0;

    // Quét 20,000 số sát vạch đích để tìm con số "phân mảnh" tồi tệ nhất
    for(int n = MAX_N - 20000; n <= MAX_N; n++) {
        int groups = get_distinct_group_size(n);
        if(groups > max_groups) {
            max_groups = groups;
            best_n = n;
        }
    }

    // In ra số n tử thần
    cout << best_n << "\n";

    return 0;
}
