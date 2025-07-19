#include <bits/stdc++.h>
using namespace std;

struct Op {
    int t;    // 0 = paint row, 1 = paint col
    int idx;  // 0-based index row/col
    int c;    // color
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if(!(cin >> T)) return 0;
    while (T--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> A(n, vector<int>(m));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> A[i][j];

        // Dùng map thay cho unordered_map để tránh rehash động
        vector<map<int,int>> freqRow(n), freqCol(m);
        vector<char> removedRow(n,false), removedCol(m,false);
        queue<int> q;  // [0..n-1] là row, [n..n+m-1] là col

        // Khởi tạo đếm
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                freqRow[i][ A[i][j] ]++;
            }
            if (freqRow[i].size() == 1)
                q.push(i);
        }
        for(int j = 0; j < m; j++){
            for(int i = 0; i < n; i++){
                freqCol[j][ A[i][j] ]++;
            }
            if (freqCol[j].size() == 1)
                q.push(n + j);
        }

        vector<Op> ops;
        ops.reserve(n + m);

        // Bóc ngược từng thao tác
        while(!q.empty()){
            int x = q.front(); q.pop();
            if (x < n){
                // Remove row x
                if (removedRow[x]) continue;
                removedRow[x] = true;
                int color = freqRow[x].begin()->first;
                ops.push_back({0, x, color});
                // Cập nhật các cột chưa remove
                for(int j = 0; j < m; j++){
                    if (removedCol[j]) continue;
                    int v = A[x][j];
                    auto &mp = freqCol[j];
                    if (--mp[v] == 0) {
                        mp.erase(v);
                    }
                    if (mp.size() == 1) {
                        q.push(n + j);
                    }
                }
            } else {
                // Remove col y
                int y = x - n;
                if (removedCol[y]) continue;
                removedCol[y] = true;
                int color = freqCol[y].begin()->first;
                ops.push_back({1, y, color});
                // Cập nhật các hàng chưa remove
                for(int i = 0; i < n; i++){
                    if (removedRow[i]) continue;
                    int v = A[i][y];
                    auto &mp = freqRow[i];
                    if (--mp[v] == 0) {
                        mp.erase(v);
                    }
                    if (mp.size() == 1) {
                        q.push(i);
                    }
                }
            }
        }

        // Kiểm tra kết quả
        if ((int)ops.size() < n + m){
            cout << "NO\n";
        } else {
            cout << "YES\n";
            int k = ops.size();
            cout << k << "\n";
            // In ngược thứ tự remove để được thứ tự paint
            for(int i = k - 1; i >= 0; --i){
                // t=0: row, t=1: col; +1 vì đề đánh số từ 1
                cout << ops[i].t << " "
                     << ops[i].idx + 1 << " "
                     << ops[i].c << "\n";
            }
        }
    }
    return 0;
}
