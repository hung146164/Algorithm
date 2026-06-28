#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5+5;
const int mod=1e9+7;

void solve()
{
//    cout<<"Nhap q: ";
    int q; cin>>q;
    vector<map<string,int>> dp(505);
    unordered_map<string,int> mp;
    while(q--)
    {
//        cout<<"Nhap a: ";
        int a,b;
        cin>>a;
//        cout<<"Nhap b: ";
        cin>>b;
        if(a==1)
        {

            for(int i=0;i<b; i++)
            {
                string s; cin>>s;
                if(mp.find(s)==mp.end())
                {
                    dp[1][s]=1;
                }
                else{
                    dp[mp[s]+1][s]++;
                    if(dp[mp[s]][s]==1)
                    {
                        dp[mp[s]].erase(s);
                    }
                    else dp[mp[s]][s]--;
                }

                mp[s]++;
            }
        }
        else{
            vector<string> ans;
            for(int i=dp.size()-1 ;i>=0;i--)
            {
                for(auto& x:dp[i])
                {
                    int add=min(b,x.second);
                    for(int i=0;i<add ;i++)
                    {
                        ans.push_back(x.first);
                    }
                    b-=add;
                    if(b==0) break;
                }
            }
            for(int i=0; i< ans.size(); i++)
            {
                cout<<ans[i]<<(i==ans.size()-1?"":", ");
            }
            cout<<endl;
        }
    }
}

signed main()
{
    solve();
}









