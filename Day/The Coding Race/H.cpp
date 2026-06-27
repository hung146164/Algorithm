#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int n = 120;
vector<vector<int>> board;
int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int get_degree(int r, int c) {
    int count = 0;
    for (int i = 0; i < 8; ++i) {
        int nr = r + dr[i], nc = c + dc[i];
        if (nr >= 0 && nr < n && nc >= 0 && nc < n && board[nr][nc] == 0) count++;
    }
    return count;
}

bool solve() {
    board.assign(n, vector<int>(n, 0));
    int r = 0, c = 0; // Bắt đầu ở góc trái trên để ăn điểm (r+c) tối đa khi kết thúc
    board[r][c] = 1;

    for (int step = 2; step <= n * n; ++step) {
        int min_deg = 10;
        vector<int> ties;
        for (int i = 0; i < 8; ++i) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && board[nr][nc] == 0) {
                int deg = get_degree(nr, nc);
                if (deg < min_deg) {
                    min_deg = deg;
                    ties = {i};
                } else if (deg == min_deg) {
                    ties.push_back(i);
                }
            }
        }

        // Ngõ cụt, cần chạy lại từ đầu
        if (ties.empty()) return false;

        // Phá vỡ sự ràng buộc bằng Random để không bị lặp vô hạn
        int dir = ties[rand() % ties.size()];
        r += dr[dir];
        c += dc[dir];
        board[r][c] = step;
    }
    return true; // Tìm thành công hành trình
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(NULL));

    int input_n;
    if (cin >> input_n) {
        n = input_n; // Luôn là 120

        // Thuật toán Warnsdorff random cực nhanh, thường tốn < 0.1s để pass
        while (!solve()) {}

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                cout << board[r][c] << (c == n - 1 ? "" : " ");
            }
            cout << "\n";
        }
    }
    return 0;
}
