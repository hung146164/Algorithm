class Solution {
public:
    int minDeletion(string s, int k) {
        vector<int> dp(26);
        int m=0;
        for(int i=0; i< s.size(); i++)
        {
            dp[s[i]-'a']++;
        }
        for(auto i: dp) if(i>0) m++;
        int c=m-k;
        if(c<=0) return 0;
        sort(dp.begin(),dp.end());
        int ans=0;
        for(int i=0; i< dp.size(); i++)
        {
            if(dp[i]>0)
            {
                ans+=dp[i];
                c--;
            }
            if(c==0) break;
        }
        return ans;
    }
};
