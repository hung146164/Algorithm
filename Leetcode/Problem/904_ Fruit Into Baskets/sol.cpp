class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> dp;
        int ans=0;
        for(int l=0, i=0; i<fruits.size(); i++)
        {
            dp[fruits[i]]++;
            while(dp.size()>2)
            {
                dp[fruits[l]]--;
                if(dp[fruits[l]]==0) dp.erase(fruits[l]);
                l++;
            }
            ans=max(i-l+1, ans);

        }
        return ans;
    }

};