#include<bits/stdc++.h>
using namespace std;
vector<int> sol(int n)
{
    if(n==2) return {2};
    if(n==3) return {3};
    vector<int> ans;
    if(n%2==0)
    {
        while(n)
        {
            ans.push_back(2);
            n-=2;
        }
    }
    else
    {
        while(n!=3)
        {
            ans.push_back(2);
            n-=2;
        }
        ans.push_back(3);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n; cin>>n;
    vector<int> ans=sol(n);
    cout<<ans.size()<<'\n';
    for(auto i: ans) cout<<i<<' ';
}
