typedef long long ll;
class Seg
{
    public:
    vector<vector<ll>> tree;
    vector<ll> nums;
    Seg(vector<ll>& num)
    {
        nums=num;
        tree.resize(num.size()*4);
        build(0,0,num.size()-1);
    }
    vector<ll> merge(vector<ll>& a, vector<ll>& b)
    {
        vector<ll> ans;
        ll l=0, r=0;
        while(l<a.size() && r< b.size())
        {
            if(a[l]<b[r])
            {
                ans.push_back(a[l]);
                l++;
            }
            else
            {ans.push_back(b[r]);
            r++;
            }
        }
        while(l<a.size())
        {
            ans.push_back(a[l]);
            l++;
        }
        while(r<b.size())
        {
            ans.push_back(b[r]);
            r++;
        }
        return ans;
    }
    void build(ll curr ,ll l, ll r)
    {
        if(l==r)
        {
            tree[curr]={nums[l]};
            return;
        }
        ll m=l+(r-l)/2;
        build(curr*2+1,l,m);
        build(curr*2+2,m+1,r);
        tree[curr]=merge(tree[curr*2+1],tree[curr*2+2]);
    }
    ll query(ll curr, ll l, ll r, ll x,ll y,ll val)
    {
        if(r<x || l> y) return 0;
        if(x<=l && r<=y)
        {
            return upper_bound(tree[curr].begin(), tree[curr].end(),val)-tree[curr].begin();
        }
        ll m=l+(r-l)/2;
        return query(curr*2+1,l,m,x,y,val)+query(curr*2+2,m+1,r,x,y,val);
    }
};
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        ll ans=0;
        reverse(nums.begin(),nums.end());
        for(ll i=0; i< nums.size(); i++)
        {
            nums[i]*=2;
        }
        Seg seg(nums);
        for(ll i=1; i< nums.size(); i++)
        {
            ans+=seg.query(0,0,nums.size()-1,0,i-1,nums[i]/2);
        }
        return ans;


    }
};
