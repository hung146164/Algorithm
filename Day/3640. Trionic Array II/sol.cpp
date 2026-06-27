const int inf=-LLONG_MAX/4;
class Solution {
public:
    typedef long long ll;
    ll sol(vector<int>& nums, ll curr=0,ll state=0)
    {
        if(curr==nums.size())
        {
            if(state==1 || state==2 || state==0) return inf;
            if(state==3) return 0;
        }
        ll ans=inf;
        if(state==0)
        {
            ans=max(ans,sol(nums,curr+1,0));
            ans=max(ans,nums[curr]+sol(nums,curr+1,1));
        }
        else if(state==1)
        {
            if(nums[curr]>nums[curr-1]) ans=max(ans,nums[curr]+sol(nums,curr+1,1));
            else if(nums[curr]==nums[curr-1]) return inf;
            else ans=max(ans,nums[curr]+sol(nums,curr+1,2));
        }
        else if(state==2)
        {
            if(nums[curr]<nums[curr-1]) ans=max(ans,nums[curr]+sol(nums,curr+1,2));
            else if(nums[curr]==nums[curr-1]) return inf;
            else ans=max(ans,nums[curr]+sol(nums,curr+1,3));
        }
        else
        {
            ans=0;
            if(nums[curr]<=nums[curr-1]) return 0;
            else ans=max(ans,nums[curr]+sol(nums,curr+1,3));
        }
        return ans;
    }
    long long maxSumTrionic(vector<int>& nums) {
        return sol(nums);
    }
};
