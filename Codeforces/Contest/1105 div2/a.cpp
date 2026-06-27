#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5+5;
const int mod=1e9+7;

int val[20];
void solve()
{
    int n,k; cin>>n>>k;

    priority_queue<int,vector<int>,greater<int>> pq;
    int ans=0;
    for(int i=0; i<k;i++)
    {
        if(n>0)
        {
            pq.push(1);
            ans++;
            n--;
        }
    }
    int val=pq.top();
    int nval=(val<<1)|1;
    while(n>=nval-val)
    {
        n-=nval-val;
        pq.pop();
        pq.push(nval);

        val=pq.top();
        nval=(val<<1)|1;
        ans++;
    }


    cout<<ans<<'\n';

}

signed main()
{
    val[0]=0;
    int c=1;
    for(int i=1;i<20; i++)
    {
        c*=2;
        val[i]=c-1;
    }
    int t; cin>>t;
    while(t--)
    {

        solve();

    }
}









