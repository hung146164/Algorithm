#include<bits/stdc++.h>
using namespace std;

vector<bool> nums;
vector<bool> tree;

void build(int curr=0,int l=0,int r=nums.size()-1)
{
    if(l==r)
    {
        tree[curr]=nums[l];
        return;
    }
    int m=l+(r-l)/2;
    build(curr*2+1,l,m);
    build(curr*2+2,m+1,r);
    tree[curr]=tree[curr*2+1]|| tree[curr*2+2];
}
void update(int index,int curr=0,int l=0,int r=nums.size()-1)
{
    if(l==r)
    {
        tree[curr]=0;
        return;
    }
    int m=l+(r-l)/2;
    if(m>=index) update(index,curr*2+1,l,m);
    else update(index,curr*2+2,m+1,r);
    tree[curr]=tree[curr*2+1]|| tree[curr*2+2];
}
int query(int index,int curr=0,int l=0,int r=nums.size()-1)
{
    if(r<index || tree[curr]==0) return -1;

    if(l==r)
    {
        return l;
    }

    int m=l+(r-l)/2;

    int left=query(index,curr*2+1,l,m);
    if(left==-1) return query(index,curr*2+2,m+1,r);
    return left;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q;cin>>n>>q;
    nums.resize(n+1,1);
    tree.resize((n+1)*4,false);
    build();

    while(q--)
    {
        char a;int b; cin>>a>>b;
        if(a=='?')
        {
            cout<<query(b)<<'\n';
        }
        else{
            update(b);
        }
    }
}
