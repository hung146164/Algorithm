class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        vector<int> pos;
        vector<int> val;
        vector<int> prefix(1);
        for (int i = 0; i < fruits.size(); i++) {
            pos.push_back(fruits[i][0]);
            val.push_back(fruits[i][1]);
            prefix.push_back(prefix[i] + fruits[i][1]);
        }

        int r = 0;
        int ans = 0;
        while (r<pos.size() && pos[r] <= startPos) {
            int kc = startPos - pos[r];
            int thua = k - kc;
            if (thua >= 0) {
                int it = prev(upper_bound(pos.begin(), pos.end(),
                                          max(startPos, pos[r] + thua))) -
                         pos.begin();
                ans = max(ans, prefix[it + 1] - prefix[r]);
            }
            r++;
        }
        int l = pos.size() - 1;
        while (l>=0 && pos[l] >= startPos) {
            int kc = pos[l] - startPos;
            int thua = k - kc;
            if (thua >= 0) {
                int it = lower_bound(pos.begin(), pos.end(),
                                        min(startPos, pos[l] - thua)) -
                            pos.begin();
                ans = max(ans, prefix[l + 1] - prefix[it]);
            }
            l--;
        }
        return ans;
    }
};