class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& b) {
        vector<set<int>> row(n + 1);
        vector<set<int>> col(n + 1);
        int ans = 0;
        for (int i = 0; i < b.size(); i++) {
            row[b[i][0]].insert(b[i][1]);
            col[b[i][1]].insert(b[i][0]);
        }
        for (int i = 0; i < b.size(); i++) {
            int x = b[i][0];
            int y = b[i][1];

            set<int>& co=row[x];
            set<int>& ro=col[y];

            auto it1=co.lower_bound(y);
            auto it2=ro.lower_bound(x);
            if(it1!=co.end() && it1!=co.begin() && next(it1)!=co.end() &&
               it2!=ro.end() && it2!=ro.begin() && next(it2)!=ro.end())
            {
                ans++;
            }

        }
        return ans;
    }
};©leetcode
