#include<bits/stdc++.h>
#include <random> // đặt ở đầu file
using namespace std;
void layhet(int curr,int& dinh, int& canh,vector<vector<pair<int,int>>>& dp, vector<bool>& check)
{
    for(int i=0; i< dp[curr].size(); i++)
    {
        int to=dp[curr][i].first;
        if(!check[to])
        {
            check[to]=true;

            dinh++;
            layhet(to,dinh,canh,dp,check);
        }
        canh++;
    }
}
void bobot(int curr, vector<vector<pair<int,int>>>& dp,vector<bool>& duong, int& need,vector<bool>& check2)
{
    if(need==0) return;
    for(int i=0; i< dp[curr].size(); i++)
    {
        if(need==0) return;
        if(!check2[dp[curr][i].second])
        {
            check2[dp[curr][i].second]=true;
            duong[dp[curr][i].second]=false;
            need--;
            bobot(dp[curr][i].first,dp,duong,need,check2);
        }
    }
}
int main()
{
    int m,n;cin>>m>>n;
    vector<vector<pair<int,int>>> dp(n);
    for(int i=0; i< m ;i ++)
    {
        int x,y; cin>>x>>y;
        x--;
        y--;
        dp[x].push_back({y,i});
        dp[y].push_back({x,i});
    }
    vector<bool> check(n);
    vector<bool> duong(m,true);
    int ans=0;
    for(int i=0; i< n ;i++)
    {
        if(!check[i])
        {
            check[i]=true;
            int dinh=1;
            int canh=0;
            layhet(i,dinh,canh,dp,check);
            //cout<<dinh<<" "<<canh<<endl;
            canh/=2;
            if(canh>dinh)
            {
                int need= canh-dinh;
                vector<bool> check2(n);
                bobot(i,dp,duong,need,check2);
                ans+=canh-dinh;
            }
        }
    }
    cout<<ans<<endl;
    vector<int> valid;
    for(int i=0; i< duong.size() ;i++)
    {
        if(duong[i]) valid.push_back(i+1);
    }
    // random
random_device rd;
mt19937 g(rd());
shuffle(valid.begin(), valid.end(), g);

    for(int i=0; i< valid.size(); i++)
    {
        cout<<valid[i]<<endl;
    }
    for(int i=0; i< duong.size(); i++)
    {
        if(!duong[i]) cout<<i+1<<endl;
    }

}
