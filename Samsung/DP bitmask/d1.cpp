#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


const ll mod = 1e9 + 7;
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
ll getval(ll curr, vector<ll>& kq,vector<vector<ll>>& g,vector<ll>& nums,ll k)
{
    if(kq[curr]!=-1) return kq[curr];
    ll ans=0;
    vector<ll> ccc;
    ll ma=0;
    for(ll i=0; i<g[curr].size(); i++)
    {
        ll val=getval(g[curr][i],kq,g,nums,k);
        ma=maxx(ma,val);
        ccc.push_back(val);
    }
    if(ccc.size()<= k) ans=(ma+nums[curr]);
    else ans+=sol(ccc,k);

    kq[curr]=ans;
    //if(curr==4) cout<<ans<<endl;
    return kq[curr];
}
pair<vector<ll>,ll> handle(string s)
{
    vector<ll> in;
    ll i=0;
    while(s[i]!='>')
    {
        ll v=0;
        bool have=false;
        while(s[i]-'0'<10 && s[i]-'0'>=0)
        {
            have=true;
            v*=10;
            v+=s[i]-'0';
            i++;
        }
        if(have) in.push_back(v);
        i++;
    }
    ll b=0;
    i+=2;
    for(;i<s.size(); i++)
    {
        b*=10;
        b+=s[i]-'0';
    }

    return {in,b};
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,k; cin>>n>>k;

    vector<ll> nums;
    for(ll i=0; i< n; i++)
    {
        ll x; cin>>x;
        nums.push_back(x);
    }
    cin.ignore();
    vector<vector<ll>> g(n);
    for(ll i=0; i< n; i++)
    {
        string s;
        if(i==n-1) {cin>>s; continue;}
        getline(cin,s);
        cin.ignore();
        pair<vector<ll>,ll> in=handle(s);
        for(ll j=0; j<in.first.size(); j++)
        {
            g[in.second].push_back(in.first[j]);
        }
    }
//    for(ll i=0; i< g.size(); i++)
//    {
//        for(ll j=0; j< g[i].size(); j++)
//        {
//            cout<<g[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    vector<ll> kq(n,-1);
    ll ans=0;
    for(ll i=0; i< g.size(); i++)
    {
        if(kq[i]==-1)
        {
            kq[i]=getval(i,kq,g,nums,k);
        }
    }
    for(ll i=0; i< kq.size(); i++)
    {
        ans=maxx(ans,kq[i]);
//        cout<<kq[i]<<' ';
    }
//    cout<<endl;
    cout<<ans<<endl;
    return 0;
}

