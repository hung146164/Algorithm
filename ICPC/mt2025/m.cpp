#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int N=1e5+1;
int a1,a2,b1,b2;

int sol(int x,int y, int x1,int y1,vector<bool>& check, vector<pair<int,int>>& pos,int c=0,int c1=0)
{
    int ans=INT_MAX;
    bool have=false;
    for(int i=0; i< pos.size(); i++)
    {
        if(!check[i])
        {
            have=true;
            check[i]=true;
            //Cho A di
            ans=min(ans,c*(abs(pos[i].first-x)+abs(pos[i].second-y)) + sol(pos[i].first,pos[i].second,x1,y1,check,pos,c+1,c1));
            //Cho B di
            ans=min(ans,c1*(abs(pos[i].first-x1)+abs(pos[i].second-y1)) + sol(x,y,pos[i].first,pos[i].second,check,pos,c,c1+1));
            check[i]=false;
        }
    }
    if(!have)
    {
        ans=min(ans,c*(abs(a1-x)+abs(a2-y)) + c1 *(abs(b1-x1)+abs(b2-y1)));
    }
    return ans;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<pair<int,int>>pos;
    for(int i=0; i< n; i++)
    {
        int a, b;
        cin>>a>>b;
        pos.push_back({a,b});
    }

    cin>>a1>>a2;
    vector<bool> check(n);
    int ans=0;
    cin>>b1>>b2;
    ans+=sol(a1,a2,b1,b2,check,pos);
    cout<<ans<<'\n';


}


