#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;

class Seg
{
public:
    vector<int> nums;
    vector<int>tree;
    Seg(vector<int> num)
    {
        nums=num;
        tree.resize(num.size()*4,0);
        build(0,0,num.size()-1);
//        cout<<"#tree[0]"<<" ="<<tree[0]<<endl;
    }
    void build(int curr,int l, int r)
    {
        if(l==r)
        {
            tree[curr]=nums[l];
            return;
        }
        int m=l+(r-l)/2;
        build(curr*2+1,l,m);
        build(curr*2+2,m+1,r);
        tree[curr]=max(tree[curr*2+2],tree[curr*2+1]);
    }
    int query(int curr, int l, int r,int val)
    {
        if(tree[curr]<val) return -1;
        if(l==r)
        {
            nums[l]-=val;
            tree[curr]-=val;
            return l;
        }
        int m=l+(r-l)/2;
        int c=query(curr*2+1,l,m,val);
        c=c==-1?query(curr*2+2,m+1,r,val):c;
        tree[curr]=max(tree[curr*2+1],tree[curr*2+2]);
        return c;
    }

};

int main(void)
{
    int n,k;cin>>n>>k;
    vector<int> nums(n);
    for(int i=0; i< n; i++)
    {
        cin>>nums[i];
    }
    Seg seg(nums);
    while(k--)
    {
        int x;cin>>x;
        cout<<seg.query(0,0,nums.size()-1,x)+1<<" ";
    }
//        8 1
//    3 2 4 1 5 5 2 6
//    7
}
