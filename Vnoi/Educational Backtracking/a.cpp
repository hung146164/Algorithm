#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>

typedef long long ll;
const int N=5e5+5;
const int mod=1e9+7;
const int modr=1e9+9;

int nex[N],pre[N];
int nums[N];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int n,q; cin>>n>>q;

    map<int,int> cnt;

    for(int i=0; i< n; i++)
    {
        cin>>nums[i];
    }
    int l=0;
    for(int r=0; r< n; r++)
    {
        cnt[nums[r]]++;
        while(cnt[nums[r]]>1)
        {
            cnt[nums[l]]--;
            nex[l]=r-1;
            l++;
        }
        pre[r]=l;
    }
    while(l<n) {nex[l]=n-1; l++;}
//    for(int i=0; i <n; i++)
//    {
//        cout<<nex[i]<<' ';
//    }
//    cout<<el;
//    for(int  i=0; i< n; i++)
//    {
//        cout<<pre[i]<<' ';
//    }
//    cout<<el;
    for(int i=0; i< q; i++)
    {
        int a, b; cin>>a>>b;
        a--;b--;
        int cleft= max(a,pre[b]-1);
        int cright= min(nex[a],b-1);
        if(cleft>cright)
        {
            cout<<0<<el;
            continue;
        }
        int ans=cright-cleft+1;
        //cout<<cleft<<' '<<cright<<' '<<ans<<el;
        cout<<ans<<el;
    }
}
