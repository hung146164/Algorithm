#include <iostream>
#include <vector>
#include <algorithm>
#include <set> // Dùng multiset để lưu trữ ID xe bus và tìm min
#include <cstdio> // Để sử dụng freopen

// Dùng namespace std để không cần viết std:: trước các thành phần thư viện chuẩn
using namespace std;

// Khai báo các hằng số
const int MAXN = 100005; // Số đỉnh (địa điểm) tối đa
const int LOGN = 18;     // log2(MAXN) ~ 16.6, 18 là đủ cho Binary Lifting

// Khai báo biến toàn cục
int N, M; // N: số đỉnh, M: số xe bus

// Cấu trúc dữ liệu cho cây (mô tả mạng lưới đường đi)
vector<int> adj[MAXN]; // Danh sách kề

// Biến cho Heavy-Light Decomposition (HLD)
int depth[MAXN];          // Độ sâu của mỗi nút (khoảng cách từ gốc, gốc có depth 0)
int parent[MAXN];         // Cha trực tiếp của mỗi nút
int subtree_size[MAXN];   // Kích thước cây con (số nút trong cây con gốc là nút đó)
int heavy_child[MAXN];    // Con nặng của mỗi nút (-1 nếu không có con hoặc tất cả là con nhẹ)
int chain_head[MAXN];     // Nút đầu tiên (gốc) của chuỗi nặng (heavy path) chứa nút này
int pos_in_base[MAXN];    // Vị trí của nút này trong mảng phẳng hóa (flattened array)
int node_at_pos[MAXN];    // Nút gốc ban đầu tại một vị trí cụ thể trong mảng phẳng hóa
int cur_pos;              // Biến đếm vị trí hiện tại dùng khi phẳng hóa cây

// Cấu trúc dữ liệu cho Segment Tree
// Mỗi nút của Segment Tree lưu trữ một vector các ID xe bus mà đường đi của chúng
// bao phủ hoàn toàn đoạn mà nút Segment Tree đó quản lý.
vector<int> seg_tree[4 * MAXN]; // Kích thước 4*MAXN đủ cho Segment Tree
int final_ans[MAXN];            // Mảng lưu trữ kết quả cuối cùng: min ID xe bus đi qua mỗi đỉnh

// --- Hàm Tiền xử lý HLD (DFS1) ---
// Bước 1: Tính toán độ sâu, nút cha, kích thước cây con và xác định con nặng
// u: nút hiện tại, p: nút cha, d: độ sâu hiện tại
void dfs1(int u, int p, int d) {
    depth[u] = d;
    parent[u] = p;
    subtree_size[u] = 1;
    heavy_child[u] = -1; // Khởi tạo không có con nặng

    int max_s_size = 0; // Kích thước cây con lớn nhất của các con
    for (int v : adj[u]) {
        if (v == p) continue; // Bỏ qua cha
        dfs1(v, u, d + 1);    // Đệ quy xuống con
        subtree_size[u] += subtree_size[v]; // Cập nhật kích thước cây con của u
        if (subtree_size[v] > max_s_size) {
            max_s_size = subtree_size[v];
            heavy_child[u] = v; // Xác định con nặng
        }
    }
}

// --- Hàm Tiền xử lý HLD (DFS2) ---
// Bước 2: Gán vị trí trong mảng phẳng hóa và xác định đầu chuỗi nặng
// u: nút hiện tại, p: nút cha, head_node: nút đầu của chuỗi nặng chứa u
void dfs2(int u, int p, int head_node) {
    chain_head[u] = head_node; // Gán đầu chuỗi cho nút hiện tại
    pos_in_base[u] = ++cur_pos; // Gán vị trí trong mảng phẳng hóa và tăng biến đếm
    node_at_pos[cur_pos] = u;    // Lưu lại nút gốc ứng với vị trí này

    if (heavy_child[u] != -1) {
        // Ưu tiên duyệt con nặng trước để giữ các nút trên cùng heavy path liên tiếp
        dfs2(heavy_child[u], u, head_node);
    }

    // Duyệt qua các con nhẹ, mỗi con nhẹ sẽ bắt đầu một chuỗi nặng mới
    for (int v : adj[u]) {
        if (v == p || v == heavy_child[u]) continue; // Bỏ qua cha và con nặng
        dfs2(v, u, v); // Con nhẹ tự nó là đầu chuỗi mới
    }
}

// --- Hàm Cập nhật Segment Tree ---
// Thêm bus_id vào các nút Segment Tree mà đoạn của chúng được bao phủ hoàn toàn
// node_idx: chỉ số nút hiện tại của Segment Tree (trong mảng seg_tree)
// seg_start, seg_end: phạm vi (trong mảng phẳng hóa) mà nút Segment Tree hiện tại quản lý
// update_start, update_end: phạm vi (trong mảng phẳng hóa) cần cập nhật
// bus_id: ID của xe bus cần thêm
void update_seg_tree(int node_idx, int seg_start, int seg_end, int update_start, int update_end, int bus_id) {
    // Nếu phạm vi của nút Segment Tree không giao với phạm vi cần cập nhật
    if (update_start > seg_end || update_end < seg_start) {
        return;
    }
    // Nếu phạm vi của nút Segment Tree nằm hoàn toàn trong phạm vi cần cập nhật
    if (update_start <= seg_start && seg_end <= update_end) {
        seg_tree[node_idx].push_back(bus_id); // Thêm ID xe bus vào nút này
        return;
    }

    // Nếu chỉ giao một phần, đệ quy xuống các con
    int mid = (seg_start + seg_end) / 2;
    update_seg_tree(2 * node_idx, seg_start, mid, update_start, update_end, bus_id);
    update_seg_tree(2 * node_idx + 1, mid + 1, seg_end, update_start, update_end, bus_id);
}

// --- Hàm Cập nhật Đường đi trên cây (sử dụng HLD) ---
// Cập nhật tất cả các nút trên đường đi từ u đến v với bus_id
void update_path(int u, int v, int bus_id) {
    // Di chuyển u và v lên cho đến khi chúng nằm trên cùng một chuỗi nặng
    while (chain_head[u] != chain_head[v]) {
        // Đảm bảo u ở chuỗi nặng sâu hơn để có thể nhảy lên (lên phía gốc)
        if (depth[chain_head[u]] < depth[chain_head[v]]) swap(u, v);

        // Cập nhật đoạn từ đầu chuỗi của u đến u trong Segment Tree
        // pos_in_base[chain_head[u]] là vị trí đầu của chuỗi
        // pos_in_base[u] là vị trí của nút u
        update_seg_tree(1, 1, N, pos_in_base[chain_head[u]], pos_in_base[u], bus_id);

        // Nhảy u lên nút cha của đầu chuỗi hiện tại của nó
        u = parent[chain_head[u]];
    }
    // Khi u và v đã ở cùng một chuỗi nặng
    // Đảm bảo u là nút nông hơn (có độ sâu nhỏ hơn)
    if (depth[u] > depth[v]) swap(u, v);

    // Cập nhật đoạn từ u đến v trong Segment Tree (vì chúng đã cùng chuỗi nặng)
    update_seg_tree(1, 1, N, pos_in_base[u], pos_in_base[v], bus_id);
}

// --- Hàm DFS cuối cùng trên Segment Tree để tính toán kết quả ---
// Duyệt Segment Tree, đẩy các ID xe bus từ nút cha xuống nút con và tính min ID cho từng nút gốc
// node_idx: chỉ số nút Segment Tree hiện tại
// seg_start, seg_end: phạm vi (trong mảng phẳng hóa) mà nút Segment Tree hiện tại quản lý
// inherited_buses: multiset chứa các ID xe bus được "thừa kế" từ các nút cha của Segment Tree
void final_dfs_seg_tree(int node_idx, int seg_start, int seg_end, multiset<int>& inherited_buses) {
    // Thêm các ID xe bus được lưu trữ trực tiếp tại nút Segment Tree hiện tại vào inherited_buses
    for (int id : seg_tree[node_idx]) {
        inherited_buses.insert(id);
    }

    if (seg_start == seg_end) { // Nếu đã đến nút lá của Segment Tree (tương ứng với một nút gốc)
        if (!inherited_buses.empty()) {
            final_ans[node_at_pos[seg_start]] = *inherited_buses.begin(); // Lấy ID nhỏ nhất
        } else {
            final_ans[node_at_pos[seg_start]] = -1; // Không có xe bus nào đi qua nút này
        }
        // Không cần xóa ID ở đây, việc xóa sẽ được thực hiện khi quay lại từ hàm đệ quy của cha
        return;
    }

    // Đệ quy xuống các nút con của Segment Tree
    int mid = (seg_start + seg_end) / 2;
    final_dfs_seg_tree(2 * node_idx, seg_start, mid, inherited_buses);       // Con trái
    final_dfs_seg_tree(2 * node_idx + 1, mid + 1, seg_end, inherited_buses); // Con phải

    // Khi quay trở lại từ các hàm đệ quy của con, loại bỏ các ID xe bus
    // chỉ thuộc về nút Segment Tree hiện tại (để không ảnh hưởng đến các nhánh khác)
    for (int id : seg_tree[node_idx]) {
        inherited_buses.erase(inherited_buses.find(id)); // Xóa một ID cụ thể
    }
}


int main() {
    // Thiết lập đọc từ file MINBUS.INP và ghi ra file MINBUS.OUT
//    freopen("MINBUS.INP", "r", stdin);
//    freopen("MINBUS.OUT", "w", stdout);

    // Tối ưu hóa I/O (nên bật nếu không gây lỗi trên môi trường cụ thể)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Đọc số đỉnh N và số xe bus M
    cin >> N >> M;

    // Đọc N-1 cạnh và xây dựng danh sách kề cho cây
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Bước 1: Tiền xử lý HLD (DFS1 và DFS2)
    // Bắt đầu DFS1 từ nút 1 (coi là gốc), cha là 0, độ sâu 0
    dfs1(1, 0, 0);
    // Đặt lại biến đếm vị trí cho mảng phẳng hóa
    cur_pos = 0;
    // Bắt đầu DFS2 từ nút 1, cha là 0, đầu chuỗi của 1 là chính nó
    dfs2(1, 0, 1);

    // Bước 2: Xử lý M lộ trình xe bus
    for (int i = 1; i <= M; ++i) {
        int u, v;
        cin >> u >> v;
        update_path(u, v, i); // Cập nhật đường đi từ u đến v với ID xe bus i
    }

    // Bước 3: Thực hiện DFS cuối cùng trên Segment Tree để tính toán kết quả
    multiset<int> initial_buses; // multiset rỗng để bắt đầu truyền thông tin xuống
    final_dfs_seg_tree(1, 1, N, initial_buses); // Duyệt Segment Tree từ gốc (node 1)

    // In kết quả cho từng đỉnh (từ 1 đến N)
    for (int i = 1; i <= N; ++i) {
        cout << final_ans[i] << (i == N ? "" : "\n"); // In kết quả và dấu xuống dòng (trừ đỉnh cuối cùng)
    }
    // Đề bài không nói rõ có cần dấu xuống dòng cuối cùng hay không,
    // nhưng thường thì output của vòng lặp cuối cùng sẽ có dấu xuống dòng.
    // Nếu gặp lỗi "Presentation Error", có thể cân nhắc bỏ dòng này.
    // cout << "\n";

    return 0;
}
