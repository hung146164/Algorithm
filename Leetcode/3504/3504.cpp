class Solution {
public
    mapint, int dp1, dp2;

    int sol(int l, int r, string s, mapint, int& dp) {
        while (l = 0 && r  s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
         couthh r-l-1endl;
        dp[l + 1] = max(dp[l + 1], r-l-1);
        return r - l - 1;
    }
    int longestPalindrome(string s, string t) {
        if(s==t) return 2s.size();
         ios_basesync_with_stdio(false);
        cin.tie(NULL);
        int ans = 1;
        for (int i = 0; i  s.size(); i++) {
            ans = max(ans, sol(i, i + 1, s, dp1));
            ans = max(ans, sol(i - 1, i + 1, s, dp1));
        }
        reverse(t.begin(), t.end());
        for (int i = 0; i  t.size(); i++) {
            ans = max(ans, sol(i, i + 1, t, dp2));
            ans = max(ans, sol(i - 1, i + 1, t, dp2));
        }
         cout  s     t  endl;
         for (auto i  dp1)
             cout  i.first     i.second  endl;
         cout  ----  endl;
         for (auto i  dp2)
             cout  i.first     i.second  endl;
         cout  ----  endl;
        for (int i = 0; i  t.size(); i++) {
            for (int j = 0; j  s.size(); j++) {
                int count = 0;
                int ci = i;
                int cj = j;
                 coutbeforeci cj ci cj t[ci]
                 s[cj]endl;
                while (ci  t.size() && cj  s.size() && t[ci] == s[cj]) {
                    ci++;
                    cj++;
                    count++;
                }
                 coutci cjendl;
                ans = max(ans, count  2 + max(dp1[cj], dp2[ci]));
            }
        }
        return ans;
    }
};