class Solution {
public:
    vector<int> concatenatedDivisibility(vector<int>& nums, int k) {
        int n = nums.size();
        // Chuyển sang string, lưu độ dài và giá trị nguyên
        vector<string> s(n);
        vector<int> len(n), val(n);
        for (int i = 0; i < n; ++i) {
            s[i]   = to_string(nums[i]);
            len[i] = s[i].size();
            val[i] = nums[i];
        }

        // Precompute 10^d % k cho d tối đa = 5 * 13 = 65
        vector<int> pow10(66, 1);
        for (int d = 1; d <= 65; ++d) {
            pow10[d] = int((pow10[d-1] * 10LL) % k);
        }

        int fullMask = (1 << n) - 1;
        // dpPerm[mask][mod] = lexicographically smallest permutation (vector<int>)
        // để đạt state (mask, mod). Nếu rỗng thì state chưa đạt được.
        vector<vector<vector<int>>> dpPerm(1<<n, vector<vector<int>>(k));

        // Base case: chưa chọn gì, mod = 0
        dpPerm[0][0] = {};

        // DP transition
        for (int mask = 0; mask <= fullMask; ++mask) {
            for (int mod = 0; mod < k; ++mod) {
                // Lấy permutation hiện tại
                auto &curPerm = dpPerm[mask][mod];
                // Nếu chưa có state này (ngoại trừ mask=0,mod=0), bỏ qua
                if (curPerm.empty() && !(mask == 0 && mod == 0))
                    continue;

                // Thử thêm mỗi nums[i] chưa dùng
                for (int i = 0; i < n; ++i) {
                    if ( (mask & (1<<i)) == 0 ) {
                        int nextMask = mask | (1<<i);
                        int nextMod  = int(( (mod * 1LL * pow10[len[i]]) + val[i] ) % k);

                        // Tạo hoán vị mới
                        vector<int> cand = curPerm;
                        cand.push_back(nums[i]);

                        // Cập nhật nếu chưa có hoặc cand < best
                        auto &best = dpPerm[nextMask][nextMod];
                        if (best.empty() || cand < best) {
                            best = move(cand);
                        }
                    }
                }
            }
        }

        // Kết quả nằm ở dpPerm[fullMask][0]
        return dpPerm[fullMask][0];
    }
};
©leetcode
