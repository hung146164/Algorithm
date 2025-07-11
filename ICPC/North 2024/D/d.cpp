#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    // Tăng tốc độ I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    // Lưu trữ các giá trị ràng buộc a_i.
    // a[i] sẽ là ràng buộc cho công việc i (1-indexed).
    // a[0] không sử dụng.
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    // Sử dụng std::set để lưu các công việc chưa hoàn thành.
    // Set tự động sắp xếp và cho phép tìm kiếm/xóa hiệu quả.
    std::set<int> unfinished_tasks;
    for (int i = 1; i <= n; ++i) {
        unfinished_tasks.insert(i);
    }

    std::vector<std::vector<int>> daily_schedules;
    int day_count = 0;

    while (!unfinished_tasks.empty()) {
        day_count++;
        std::vector<int> tasks_this_day;

        // Quy tắc 1: Công việc đầu tiên trong ngày có thể chọn bất kỳ.
        // Chiến thuật tham lam: Chọn công việc có số thứ tự nhỏ nhất còn lại.
        int current_task = *unfinished_tasks.begin();
        tasks_this_day.push_back(current_task);
        unfinished_tasks.erase(current_task); // Xóa khỏi danh sách chưa hoàn thành

        // Ràng buộc đặt ra bởi công việc vừa hoàn thành
        int limit_from_previous_task = a[current_task];

        // Quy tắc 2 & 3: Chọn các công việc tiếp theo trong ngày
        while (true) {
            // Tìm công việc j nhỏ nhất trong unfinished_tasks sao cho j > limit_from_previous_task
            // std::set::upper_bound(k) trả về iterator đến phần tử đầu tiên > k
            auto it = unfinished_tasks.upper_bound(limit_from_previous_task);

            if (it == unfinished_tasks.end()) {
                // Không tìm thấy công việc nào hợp lệ
                break;
            }

            current_task = *it; // Lấy công việc tìm được
            tasks_this_day.push_back(current_task);
            unfinished_tasks.erase(current_task);
            limit_from_previous_task = a[current_task]; // Cập nhật ràng buộc cho công việc tiếp theo
        }
        daily_schedules.push_back(tasks_this_day);
    }

    // In kết quả
    std::cout << day_count << std::endl;
    for (const auto& day_tasks : daily_schedules) {
        std::cout << day_tasks.size();
        for (int task : day_tasks) {
            std::cout << " " << task;
        }
        std::cout << std::endl;
    }

    return 0;
}
