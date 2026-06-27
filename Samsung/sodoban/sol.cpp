/*
    Author: HungForree
    Link: https://spoj.com/problems/PROB35/
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int nums[10][10];
int dx[]{-1,0,1,0};
int dy[]{0,1,0,-1};
void solve(int& test)
{
    int x,y;
    for(int i=0; i< 10 ;i++)
    {
        for(int j=0; j<10; j++)
        {
            cin>>nums[i][j];
            if(nums[i][j]==4)
            {
                x=i;
                y=j;
            }
        }
    }
    vector<int> cm;
    int k;
    while(cin>>k)
    {
        if(k==-1) break;
        cm.push_back(k);
    }
    for(auto& c:cm)
    {
        int tox=x+dx[c];
        int toy=y+dy[c];

        if(tox<0 || toy<0 ||tox>=10|| toy>=10)
        {
            continue;
        }
        if(nums[tox][toy]==0)
        {
            nums[x][y]=0;
            x=tox;
            y=toy;
            nums[x][y]=4;
        }
        else if(nums[tox][toy]==1)
        {
            continue;
        }
        else if(nums[tox][toy]==2)
    }
    cout<<"Case #"<<test<<": "<<ans<<'\n';
}
int main()
{
    int t; cin>>t;
    while(t--)
    {
        solve();
    }
}









