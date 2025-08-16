class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int mod, int k) {
        long long ans=0;
        vector<int> dp;
        for(int i=0; i< nums.size(); i++)
        {
            dp.push_back((nums[i]%mod==k)?1:0);
        }
        unordered_map<int,int> m;
        m[0]=1;
        int sum=0;
        for(int i=0; i< dp.size(); i++)
        {
            sum+=dp[i];
            sum%=mod;
            int to=sum-k;
            if(to<0)
            {
                to=((to%mod)+mod)%mod;
            }
            ans+=m[to];
            m[sum]++;
        }
        return ans;
    }
};