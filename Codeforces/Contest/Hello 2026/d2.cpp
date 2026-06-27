class Solution {
public:
    ll sol(vector<ll>& nums1, vector<ll>& nums2,ll c1,ll c2,bool select=false)
    {
        if( (c1==nums1.size() || c2==nums2.size()))
        {
            if(select) return 0;
            return -100000000;
        }
        ll ans=INT_MIN;
        // select
        ans=max(ans,nums1[c1]*nums2[c2]+sol(nums1,nums2,c1+1,c2+1,true));
        //continue1
        ans=max(ans,sol(nums1,nums2,c1+1,c2,select));
        //continue2
        ans=max(ans,sol(nums1,nums2,c1,c2+1,select));

        return ans;
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        return sol(nums1,nums2,0,0);
    }
};
