class Solution {
public:
    int dfs1(int r, int c, vector<vector<int>> &fruits,
             vector<vector<int>>& dp) {
        if (r < 0 || c < 0 || c >= fruits.size() || r >= fruits.size())
            return INT_MIN/2;
        if (r == fruits.size() - 1 && c == fruits.size() - 1)
            return fruits[r][c];
        if (dp[r][c] != -1)
            return dp[r][c];
        int ans = fruits[r][c] + max({dfs1(r +1, c - 1, fruits, dp),
                                     dfs1(r +1, c, fruits, dp),
                                     dfs1(r +1, c + 1, fruits, dp)});
        return dp[r][c] = ans;
    }
    int dfs2(int r, int c, vector<vector<int>>& fruits,
             vector<vector<int>>& dp) {
        if (r < 0 || c < 0 || c >= fruits.size() || r >= fruits.size())
            return INT_MIN/2;
        if (r == fruits.size() - 1 && c == fruits.size() - 1)
            return fruits[r][c];
        if (dp[r][c] != -1)
            return dp[r][c];
        int ans = fruits[r][c] + max({dfs2(r-1, c+1, fruits, dp),
                                     dfs2(r, c+1, fruits, dp),
                                     dfs2(r +1, c + 1, fruits, dp)});
        return dp[r][c] = ans;
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n=fruits.size();
        int ans = 0;
        for (int i = 0; i < fruits.size(); i++) {
            ans += fruits[i][i];
            fruits[i][i] = 0;
        }
        vector<vector<int>> dp1(n, vector<int>(n, -1));
        vector<vector<int>> dp2(n, vector<int>(n, -1));

        int ans1 = dfs1(0, fruits.size() - 1, fruits,dp1);
        int ans2 = dfs2(fruits.size() - 1, 0, fruits,dp2);

        return ans + ans1 + ans2;
    }
};