
class Solution {
public:
    vector<int> tree;
    void build(int curr,int l, int r,vector<int>& baskets)
    {
        if(l==r)
        {
            tree[curr]=baskets[l];
            return;
        }
        int m=l+(r-l)/2;
        build(curr*2+1,l,m,baskets);
        build(curr*2+2,m+1,r,baskets);
        tree[curr]=max(tree[curr*2+1],tree[curr*2+2]);
    }
    void find(int curr,int l,int r,int val)
    {
        if(l==r)
        {
            tree[curr]=0;
            return;
        }
        int m=l+(r-l)/2;
        if(tree[curr*2+1]>=val)
        {
            find(curr*2+1,l,m,val);
        }
        else
        {
            find(curr*2+2,m+1,r,val);
        }
        tree[curr]=max(tree[curr*2+1],tree[curr*2+2]);
    }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        tree.resize(baskets.size()*4);
        int ans=0;
        build(0,0,baskets.size()-1,baskets);
        for(int i=0; i< fruits.size(); i++)
        {
            if(tree[0]<fruits[i]) continue;
            find(0,0,fruits.size()-1,fruits[i]);

            ans++;
        }
        return fruits.size()-ans;
    }
};