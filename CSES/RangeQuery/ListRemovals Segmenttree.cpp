#include<bits/stdc++.h>
using namespace std;
class Seg
{
public:
    vector<int> nums;
    vector<int> tree;
    Seg(vector<int> num)
    {
        nums=num;
        tree.resize(num.size()*4);
        build(0,0,nums.size()-1);
    }
    void build(int curr,int l,int r)
    {
        if(l==r)
        {
            tree[curr]=1;
            return;
        }
        int m=l+(r-l)/2;
        build(curr*2+1,l,m);
        build(curr*2+2,m+1,r);
        tree[curr]=tree[curr*2+1]+tree[curr*2+2];
    }
    int query(int curr,int l,int r,int x)
    {
        if(l==r)
        {
            return l;
        }
        int left=tree[curr*2+1];
        int m=l+(r-l)/2;
        if(left>x)
        {
            return query(curr*2+1,l,m,x);
        }
        else{
            return query(curr*2+2,m+1,r,x-left);
        }
    }
    void remove(int node, int l, int r, int i) {
        if (l == r) {
            tree[node] = 0;
            return;
        }
        int m = (l + r) / 2;
        if (i <= m)
            remove(2 * node + 1, l, m, i);
        else
            remove(2 * node + 2, m + 1, r, i);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
};
int main(void)
{
    int n;cin>>n;vector<int> num(n);
    for(int i=0; i< n; i++)
    {
        cin>>num[i];
    }
    Seg seg(num);
    for(int i=0; i< n; i++)
    {
        int x;cin>>x;
        int index=seg.query(0,0,num.size()-1,x-1);
        cout<<num[index]<<" ";
        seg.remove(0,0,num.size()-1,index);
    }
}
