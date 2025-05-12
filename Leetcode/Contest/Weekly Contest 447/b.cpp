
class Seg{
    public:
    vector<int> nums;
    vector<int> tree;
    Seg(vector<int>&num)
    {
        nums=num;
        tree.resize(num.size()*4);
        build(0,0,num.size()-1);
    }
    void build(int curr, int l, int r)
    {
        if(l==r)
        {
            tree[curr]=nums[l];
            return;
        }
        int m=l+(r-l)/2;
        build(curr*2+1, l, m);
        build(curr*2+2,m+1,r);
        tree[curr]=max(tree[curr*2+1],tree[curr*2+2]);
    }
    int query(int l,int r)
    {
        return query(0,0,nums.size()-1,l,r);
    }
    int query(int curr, int l, int r, int x, int y)
    {
        if(r<x || l>y) return 0;
        if(l>=x && r<=y) return tree[curr];
        int m=l+(r-l)/2;
        return max(query(curr*2+1,l,m,x,y),query(curr*2+2,m+1,r,x,y));
    }
};
class Solution {
public:

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> ans;
        if(n==1)
        {
            for(int i=0; i< queries.size(); i++)
                {
                    ans.push_back(true);
                }
            return ans;
        }
        vector<int> diff;
        for(int i=1; i< nums.size(); i++)
            {
                diff.push_back(abs(nums[i]-nums[i-1]));
            }
        Seg seg(diff);
        for(auto i: queries)
        {
            if(i[0]==i[1])
            {ans.push_back(true);
             continue;}
            if(i[0]>i[1]) swap(i[0],i[1]);
            if(seg.query(i[0],i[1]-1)<=maxDiff)
            {
                ans.push_back(true);
            }
            else ans.push_back(false);
        }
        return ans;
    }
};©leetcode
