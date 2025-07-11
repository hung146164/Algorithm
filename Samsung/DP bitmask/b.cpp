#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll minn(ll a,ll b)
{
    if(a<b) return a;
    return b;
}
ll maxx(ll a,ll b)
{
    if(a>b) return a;
    return b;
}
void getmax(vector<ll>& nums,vector<ll>& ans,vector<ll>& clone,ll m,vector<bool>& check,ll sum,ll& sans, ll curr)
{
    if(sans<sum && sum<=m)
    {
        sans=sum;
        ans=clone;
    }
    if(sum>m || curr>=nums.size()) return;

    //khong chon
    getmax(nums,ans,clone,m,check,sum,sans,curr+1);
    //chon
    if(!check[curr])
    {
        clone.push_back(curr);
        getmax(nums,ans,clone,m,check,sum+nums[curr],sans,curr+1);
        clone.pop_back();
    }


}
bool can(vector<ll>& nums, ll p,ll m)
{

    vector<bool> check(nums.size());
    for(ll i=0; i<p; i++)
    {
        vector<ll> ans;
        vector<ll> clone;
        ll sans=0;
        getmax(nums, ans,clone,m,check,0,sans, 0);
        for(ll j=0; j< ans.size(); j++)
        {
        //    cout<<ans[i]<<' ';
            check[ans[j]]=true;
        }
       // cout<<endl;
    }

    for(ll i=0; i< check.size(); i++)
    {
        if(!check[i])
        {
            //cout<<i<<endl;
            return false;
        }
    }
    return true;
}
ll sol(vector<ll>& nums,ll p)
{
    ll l=1,r=1e18;
    ll ans=r;
    while(l<=r)
    {
        ll m=l+(r-l)/2;
//        if(m==4)
//        {
//            cout<<"Yes"<<endl;
//            cout<<can(nums,p,m)<<endl;
//        }
        if(can(nums,p,m))
        {
            ans=minn(ans,m);
            r=m-1;
        }
        else{
            l=m+1;
        }
    }
    return ans;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t; cin>>t;
    ll c=1;
    while(t--)
    {
        ll n, p; cin>>n>>p;
        vector<ll> nums;
        for(ll i=0; i< n; i++)
        {
            ll x; cin>>x;
            nums.push_back(x);
        }
        sort(nums.begin(),nums.end());
        cout<<"#"<<c<<" "<<sol(nums,p)<<endl;
        c++;

    }
}
