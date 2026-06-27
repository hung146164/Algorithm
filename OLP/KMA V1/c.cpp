#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int N=1e9+1;
//bool check[N];
int candidate[3]{3,5,7};
ll sol(int n)
{
    vector<bool> check(n);
    queue<ll> pq;
    pq.push(1);
    ll ans=1;
    check[1]=true;
    while(!pq.empty())
    {
        ll curr=pq.front();
        pq.pop();
        for(int i=0;i< 3; i++)
        {
            ll x=1LL*candidate[i]*curr+1;
            if(x>=n || check[x]) continue;
            check[x]=true;
            ans+=x;
            pq.push(x);
        }
    }
    return ans;
}
int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin>>n;
    cout<<sol(n)<<'\n';
}
