/*
    Author: HungForree
    Link:
*/

#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>

typedef long long ll;
const ll N=5005;
const ll mod=1e9+7;
const ll modr=1e9+9;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
using i128 = __int128;
constexpr i64 inf = 1E18;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
int lcp[N][N];
int dp[N][N];
int suf[N][N];
void solve()
{
    string s; cin>>s;
    int n=s.size();
    for(int i=n-1;i>=0; i--)
    {
        for(int j=i; j>=0; j--)
        {
            if(s[i]==s[j])
            {
                lcp[j][i]=lcp[j+1][i+1]+1;
            }
        }
    }
//    for(int i=0; i<n; i++)
//    {
//        for(int j=0; j< n; j++)
//        {
//            cout<<lcp[i][j]<<' ';
//        }
//        cout<<el;
//    }
    for(int i=n-1;i>=0; i--)
    {
        for(int len=1;len<=n; len++)
        {
            if(i+len>n) continue;
            if(i+len==n)
            {
                dp[i][len]=1;
                continue;
            }
            int cm=lcp[i][i+len];
            if(cm+i>=len+i)
            {
                dp[i][len]=1+suf[i+len][len+1];
            }
            else
            {
                if(s[i+cm]<s[i+len+cm])
                {
                    dp[i][len]=1+suf[i+len][cm+1];
                }
            }

        }
        for(int len=n-1;len>=1;len--)
        {
            suf[i][len]=max(suf[i][len+1],dp[i][len]);
        }
    }
//    for(int i=0; i<n; i++)
//    {
//        for(int len=0; len<=n; len++)
//        {
//            cout<<dp[i][len]<<' ';
//        }
//        cout<<el;
//    }
//    int ans=dp[i][]
    int ans=0;
    int start=1;
    for(int len=1;len<=n;len++)
    {
        if(dp[0][len]==1 && len!=n) continue;
        if(ans<dp[0][len])
        {
            ans=dp[0][len];
            start=len;
        }
    }
    cout<<ans<<el;
    if(ans==0) return;
    int val=ans-1;
    int curr=0;
    int prev_idx=-1;
    int pre_len=-1;
    //cout<<start<<el;
    while(val>=0)
    {
        cout<<s.substr(curr,start)<<el;

         prev_idx=curr;
         pre_len=start;
        curr+=start;

        for(int len=1;len<=n;len++)
        {
            if(val==dp[curr][len])
            {
                if(val == 1 && (curr + len != n)) continue;
                int cm = lcp[prev_idx][curr];
                if(cm>=pre_len)
                {
                    if(len>pre_len)
                    {
                        start=len;
                        break;
                    }
                }
                else
                {
                    if (s[prev_idx + cm] < s[curr + cm]) {
                        if(len>cm)
                        {
                            start=len;
                            break;
                        }

                    }
                }
            }
        }
        val--;
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int t; t=1;
    while(t--)
    {
        solve();
    }
}









