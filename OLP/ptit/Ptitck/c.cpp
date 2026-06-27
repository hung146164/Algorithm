#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> dx(1e6+1);

bool ok(string s)
{
    for(int i=0; i< s.size()/2; i++)
    {
        if(s[i]!=s[s.size()-i-1]) return false;
    }
    return true;
}
vector<ll> sang()
{
    vector<ll> ans;
    for(int i=1; i<=1e6; i++)
    {
        dx[i]=1LL*i*i*i;
    }
    for(int i=0;i<=1e6;i++)
    {
        if(ok(to_string(dx[i])))
        {
            ans.push_back(dx[i]);
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin>>n;
    vector<ll> ans=sang();
    cout<<*(prev(upper_bound(ans.begin(),ans.end(),n)));

}


