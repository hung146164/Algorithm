#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

const int MAX_K = 26;
int K; // Số lượng bài hát trong stash
ll N;  // Độ dài playlist
int Q; // Số truy vấn

// Mảng cộng dồn đếm ký tự trong chu kỳ k*k
// pre[char_idx][position]
int pre[MAX_K][700]; // k <= 26 -> k*k <= 676

// Hàm tính ký tự tại vị trí pos (1-based) trong master track
int get_char_at(ll pos) {
    pos--; // về 0-based để tính toán
    return (pos % K + pos / K) % K;
}

// Chuẩn bị dữ liệu cho master track
void build_precompute() {
    int period = K * K;
    for (int i = 1; i <= period; ++i) {
        int char_code = get_char_at(i);
        for (int c = 0; c < K; ++c) {
            pre[c][i] = pre[c][i-1] + (c == char_code ? 1 : 0);
        }
    }
}

// Hàm đếm số lượng ký tự c trong đoạn master track [start, start + len - 1]
ll count_char_in_master(int c, ll start, ll len) {
    if (len <= 0) return 0;
    ll end = start + len - 1;
    int period = K * K;

    // Số chu kỳ đầy đủ
    ll num_periods = len / period;
    ll res = num_periods * K; // Trong 1 chu kỳ k*k, mỗi ký tự xuất hiện đúng k lần

    ll rem = len % period;
    if (rem == 0) return res;

    // Xử lý phần dư
    ll s_mod = (start - 1) % period + 1;
    ll e_mod = (end - 1) % period + 1;

    if (e_mod >= s_mod) {
        res += pre[c][e_mod] - pre[c][s_mod - 1];
    } else {
        // Trường hợp bị wrap around qua chu kỳ
        res += (pre[c][period] - pre[c][s_mod - 1]) + pre[c][e_mod];
    }

    return res;
}

// --- SEGMENT TREE & Nén Tọa Độ ---

struct Query {
    char type;
    ll i, a, b;
};

vector<ll> coords;
struct Node {
    ll cnt[MAX_K];
    ll lazy_start; // 0 nghĩa là chưa gán (blank), >0 là vị trí bắt đầu trong master track
    bool is_blank; // Đánh dấu node này toàn là blank

    Node() {
        for(int i=0; i<MAX_K; i++) cnt[i] = 0;
        lazy_start = 0;
        is_blank = true;
    }
} tree[800005]; // 4 * 2 * Q

// Lấy độ dài thực tế mà node quản lý
ll get_len(int node, int l, int r) {
    return coords[r+1] - coords[l];
}

// Cập nhật giá trị node dựa trên lazy_start
// Thay thế hàm calc cũ bằng hàm này
void calc(int node, int l, int r, ll source_start) {
    tree[node].lazy_start = source_start;
    tree[node].is_blank = false;
    ll len = get_len(node, l, r);

    // --- TỐI ƯU: Tính toán hình học đoạn MỘT LẦN ---
    if (len <= 0) {
        for (int c = 0; c < K; ++c) tree[node].cnt[c] = 0;
        return;
    }

    int period = K * K;
    ll num_periods = len / period;
    ll rem = len % period;

    // Tính toán các chỉ số biên cho phần dư (nếu có)
    ll s_mod = 0, e_mod = 0;
    bool has_rem = (rem > 0);
    bool is_wrap = false;

    if (has_rem) {
        ll end = source_start + len - 1;
        s_mod = (source_start - 1) % period + 1;
        e_mod = (end - 1) % period + 1;
        if (e_mod < s_mod) is_wrap = true;
    }
    // -----------------------------------------------

    // Bây giờ mới lặp qua K ký tự, chỉ thực hiện phép cộng trừ đơn giản
    for (int c = 0; c < K; ++c) {
        ll res = num_periods * K; // Mỗi chu kỳ k*k luôn có k ký tự c

        if (has_rem) {
            if (!is_wrap) {
                res += pre[c][e_mod] - pre[c][s_mod - 1];
            } else {
                res += (pre[c][period] - pre[c][s_mod - 1]) + pre[c][e_mod];
            }
        }
        tree[node].cnt[c] = res;
    }
}

void push(int node, int l, int r) {
    if (tree[node].is_blank) return; // Nếu là blank hoặc đã xử lý xong
    if (tree[node].lazy_start == 0) return; // Không có gì để push

    int mid = (l + r) / 2;
    ll left_len = get_len(node*2, l, mid);

    // Push xuống con trái: bắt đầu giống cha
    calc(node*2, l, mid, tree[node].lazy_start);

    // Push xuống con phải: bắt đầu = bắt đầu cha + độ dài con trái
    calc(node*2+1, mid+1, r, tree[node].lazy_start + left_len);

    // Reset lazy cha
    tree[node].lazy_start = 0;
    // Lưu ý: không reset is_blank vì node cha vẫn chứa dữ liệu hợp lệ tổng hợp từ con
}

void pull(int node) {
    tree[node].is_blank = tree[node*2].is_blank && tree[node*2+1].is_blank;
    for (int c = 0; c < K; ++c) {
        tree[node].cnt[c] = tree[node*2].cnt[c] + tree[node*2+1].cnt[c];
    }
}

void update(int node, int l, int r, int ql, int qr, ll source_pos) {
    if (l > qr || r < ql) return;
    if (l >= ql && r <= qr) {
        // Tính toán vị trí bắt đầu tương ứng cho đoạn con này
        // source_pos là điểm bắt đầu cho đoạn truy vấn [ql...],
        // cần dịch chuyển cho đúng với đoạn hiện tại [l...]
        ll offset = coords[l] - coords[ql];
        calc(node, l, r, source_pos + offset);
        return;
    }
    push(node, l, r);
    int mid = (l + r) / 2;
    update(node*2, l, mid, ql, qr, source_pos);
    update(node*2+1, mid+1, r, ql, qr, source_pos);
    pull(node);
}

void query_tree(int node, int l, int r, int ql, int qr, vector<ll>& res) {
    if (l > qr || r < ql) return;
    if (l >= ql && r <= qr) {
        for (int c = 0; c < K; ++c) res[c] += tree[node].cnt[c];
        return;
    }
    push(node, l, r);
    int mid = (l + r) / 2;
    query_tree(node*2, l, mid, ql, qr, res);
    query_tree(node*2+1, mid+1, r, ql, qr, res);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    if (!(cin >> K >> N >> Q)) return 0;

    vector<Query> queries(Q);
    coords.push_back(1);
    coords.push_back(N + 1);

    for (int k = 0; k < Q; ++k) {
        cin >> queries[k].type;
        if (queries[k].type == '+') {
            cin >> queries[k].i >> queries[k].a >> queries[k].b;
        } else {
            cin >> queries[k].a >> queries[k].b;
        }
        coords.push_back(queries[k].a);
        coords.push_back(queries[k].b + 1);
    }

    // Rời rạc hóa
    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());

    int M = coords.size() - 1; // Số lượng đoạn cơ sở

    build_precompute();

    for (int k = 0; k < Q; ++k) {
        // Tìm index sau khi nén
        int l_idx = lower_bound(coords.begin(), coords.end(), queries[k].a) - coords.begin();
        int r_idx = lower_bound(coords.begin(), coords.end(), queries[k].b + 1) - coords.begin() - 1;

        if (queries[k].type == '+') {
            update(1, 0, M - 1, l_idx, r_idx, queries[k].i);
        } else {
            vector<ll> res(K, 0);
            query_tree(1, 0, M - 1, l_idx, r_idx, res);
            for (int c = 0; c < K; ++c) {
                cout << res[c] << (c == K - 1 ? "" : " ");
            }
            cout << "\n";
        }
    }

    return 0;
}
