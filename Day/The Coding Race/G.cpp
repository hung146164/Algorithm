#include <iostream>
#include <vector>
#include <string>

using namespace std;

void run_first_phase(int t) {
    for (int i = 0; i < t; i++) {
        vector<long long> values(26);
        int pos_1M = -1;
        for (int j = 0; j < 26; j++) {
            cin >> values[j];
            if (values[j] == 1000000) {
                pos_1M = j + 1; // 1-based index
            }
        }
        // Chia 26 vali thành 3 nhóm, báo cho Phase 2 biết vali 1.000.000 nằm ở đâu
        if (pos_1M <= 9) cout << 0 << "\n";
        else if (pos_1M <= 18) cout << 1 << "\n";
        else cout << 2 << "\n";
    }
}

void run_second_phase(int t) {
    for (int i = 0; i < t; i++) {
        int z;
        cin >> z;

        vector<int> safe_group;
        vector<int> open_queue;
        int pick_box = 1;

        // Setup chiến thuật dựa trên tín hiệu Phase 1
        if (z == 0) {
            pick_box = 1;
            for(int b = 1; b <= 9; b++) safe_group.push_back(b);
            for(int b = 26; b >= 10; b--) open_queue.push_back(b);
        } else if (z == 1) {
            pick_box = 10;
            for(int b = 10; b <= 18; b++) safe_group.push_back(b);
            for(int b = 26; b >= 19; b--) open_queue.push_back(b);
            for(int b = 9; b >= 1; b--) open_queue.push_back(b);
        } else {
            pick_box = 19;
            for(int b = 19; b <= 26; b++) safe_group.push_back(b);
            for(int b = 18; b >= 1; b--) open_queue.push_back(b);
        }

        // Thêm nốt các vali trong safe_group vào hàng đợi mở (trừ vali đã pick)
        for(int b : safe_group) {
            if(b != pick_box) open_queue.push_back(b);
        }

        cout << "PICK " << pick_box << "\n";
        cout.flush();

        string resp;
        cin >> resp; // "OK"

        int rounds[] = {6, 5, 4, 3, 2, 1, 1, 1, 1, 1};
        int q_idx = 0;

        for (int r = 0; r < 10; r++) {
            for (int k = 0; k < rounds[r]; k++) {
                cout << "OPEN " << open_queue[q_idx++] << "\n";
                cout.flush();

                string val_str;
                long long val;
                cin >> val_str >> val;
            }

            string offer_str;
            long long offer;
            cin >> offer_str >> offer;

            // Vì giữ được vali 1tr đến cuối, Offer sẽ rất cao. Chốt lời nếu > 350k
            if (offer > 350000 || r == 9) {
                cout << "DEAL\n";
                cout.flush();
                break;
            } else {
                cout << "NO DEAL\n";
                cout.flush();
            }
        }

        string res_str;
        long long res;
        cin >> res_str >> res;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string phase;
    if (!(cin >> phase)) return 0;

    if (phase == "first") {
        int num; cin >> num;
        int t; cin >> t;
        run_first_phase(t);
    } else if (phase == "second") {
        int t; cin >> t;
        run_second_phase(t);
    }

    return 0;
}
