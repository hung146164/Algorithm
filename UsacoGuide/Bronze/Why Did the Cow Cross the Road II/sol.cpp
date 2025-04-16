#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("circlecross.in","r",stdin);
    freopen("circlecross.out","w",stdout);
    string s;cin>>s;
    unordered_map<char,vector<int>> dp;

    for(int i=0; i< s.size(); i++)
    {
        dp[s[i]].push_back(i);
    }
    int ans=0;
    for(auto i: dp)
    {
        int start=i.second[0];
        int kt=i.second[1];
//        cout<<start<<" "<<kt<<endl;
        unordered_map<char,int> clone;
        for(int j=start+1; j<kt ;j ++)
        {
            if(clone.find(s[j])==clone.end())
            {
                clone[s[j]]++;
            }
            else
            {
                clone[s[j]]--;
                clone.erase(s[j]);
            }
        }
//        cout<<clone.size()<<endl;
        ans+=clone.size();
    }
    cout<<ans/2<<endl;
}

