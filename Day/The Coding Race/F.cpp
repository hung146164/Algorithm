#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

long long C[60][60];
int rank_counts[13], counts_of_counts[8], suit_masks[4];
bool only_four, only_sf, all_three;
long long winning_ways = 0;
vector<int> avail;

void precompute() {
    for(int i = 0; i <= 55; ++i) {
        C[i][0] = 1;
        for(int j = 1; j <= i; ++j) C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
}

int get_r(char c) {
    if (c >= '2' && c <= '9') return c - '2';
    if (c == 'T') return 8; if (c == 'J') return 9;
    if (c == 'Q') return 10; if (c == 'K') return 11; return 12;
}

int get_s(char c) {
    if (c == 'c') return 0; if (c == 'd') return 1;
    if (c == 'h') return 2; return 3;
}

void add_card(int c) {
    int r = c % 13, s = c / 13;
    counts_of_counts[rank_counts[r]]--;
    rank_counts[r]++;
    counts_of_counts[rank_counts[r]]++;
    suit_masks[s] |= (1 << r);
}

void remove_card(int c) {
    int r = c % 13, s = c / 13;
    counts_of_counts[rank_counts[r]]--;
    rank_counts[r]--;
    counts_of_counts[rank_counts[r]]++;
    suit_masks[s] &= ~(1 << r);
}

bool check_win() {
    if (only_four || all_three) {
        if (counts_of_counts[4] > 0) return true;
    }
    if (all_three) {
        if (counts_of_counts[3] >= 2 || (counts_of_counts[3] >= 1 && counts_of_counts[2] >= 1)) return true;
    }
    if (only_sf || all_three) {
        for (int s = 0; s < 4; ++s) {
            int mask = suit_masks[s];
            if (mask & (mask >> 1) & (mask >> 2) & (mask >> 3) & (mask >> 4)) return true;
            if ((mask & 0x100F) == 0x100F) return true; // A-2-3-4-5
        }
    }
    return false;
}

bool can_win_with_all(int avail_idx) {
    int t_r[13], t_c[8], t_s[4];
    for(int i=0; i<13; ++i) t_r[i] = rank_counts[i];
    for(int i=0; i<8; ++i) t_c[i] = counts_of_counts[i];
    for(int i=0; i<4; ++i) t_s[i] = suit_masks[i];

    for (int i = avail_idx; i < avail.size(); ++i) {
        int r = avail[i] % 13, s = avail[i] / 13;
        t_c[t_r[r]]--; t_r[r]++; t_c[t_r[r]]++;
        t_s[s] |= (1 << r);
    }
    bool win = false;
    if ((only_four || all_three) && t_c[4] > 0) win = true;
    if (!win && all_three && (t_c[3] >= 2 || (t_c[3] >= 1 && t_c[2] >= 1))) win = true;
    if (!win && (only_sf || all_three)) {
        for (int s = 0; s < 4; ++s) {
            if (t_s[s] & (t_s[s] >> 1) & (t_s[s] >> 2) & (t_s[s] >> 3) & (t_s[s] >> 4)) win = true;
            if ((t_s[s] & 0x100F) == 0x100F) win = true;
        }
    }
    return win;
}

void dfs(int avail_idx, int k_left) {
    if (check_win()) {
        winning_ways += C[avail.size() - avail_idx][k_left];
        return;
    }
    if (k_left == 0 || avail.size() - avail_idx < k_left) return;
    if (!can_win_with_all(avail_idx)) return; // Cắt tỉa siêu tốc

    add_card(avail[avail_idx]);
    dfs(avail_idx + 1, k_left - 1);
    remove_card(avail[avail_idx]);

    dfs(avail_idx + 1, k_left);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    precompute();
    counts_of_counts[0] = 13;

    int subtask;
    if (!(cin >> subtask)) return 0;

    only_four = (subtask == 1 || subtask == 3 || subtask == 5);
    only_sf = (subtask == 4 || subtask == 6 || subtask == 7 || subtask == 8);
    all_three = (subtask == 2 || subtask == 9 || subtask == 10 || subtask == 11 || subtask == 12);

    string h1, h2; cin >> h1 >> h2;
    int n; cin >> n;

    bool is_known[52] = {false};
    auto process_known = [&](string s) {
        int r = get_r(s[0]), st = get_s(s[1]);
        int c = st * 13 + r;
        is_known[c] = true;
        add_card(c);
    };

    process_known(h1); process_known(h2);
    int unknown_count = 0;
    for (int i = 0; i < n; i++) {
        string b; cin >> b;
        if (b == "?") unknown_count++;
        else process_known(b);
    }

    for (int i = 0; i < 52; i++) {
        if (!is_known[i]) avail.push_back(i);
    }

    dfs(0, unknown_count);

    long long total_ways = C[avail.size()][unknown_count];
    double prob = (double)winning_ways / total_ways;
    cout << fixed << setprecision(15) << prob << "\n";

    return 0;
}
