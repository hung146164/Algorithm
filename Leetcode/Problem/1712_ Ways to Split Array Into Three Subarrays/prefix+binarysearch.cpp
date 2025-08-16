class Solution {
public:
    static const int mod=1e9+7;
    int waysToSplit(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n);
        for(int i=0; i<n; i++)
        {
            prefix[i]=nums[i]+(i-1>=0?prefix[i-1]:0);
        }   
        if(prefix[n-1]==0)
        {
            return (1LL*(n-1)*(n-2)/2)%mod;
        }
        long long ans=0;
        for(int l=0; l< n; l++)
        {
            int fi=lower_bound(prefix.begin(),prefix.end(),prefix[l]*2)-prefix.begin();
            fi=max(fi,l+1);
            int en=prev(upper_bound(prefix.begin(),prefix.end(),prefix[l]+(prefix[n-1]-prefix[l])/2))-prefix.begin();
            //cout<<fi<<' '<<en<<'\n';
            if(en>=fi)
            {
                ans+=en-fi+1;
                ans%=mod;
            }
        }
        return ans;
    }
};