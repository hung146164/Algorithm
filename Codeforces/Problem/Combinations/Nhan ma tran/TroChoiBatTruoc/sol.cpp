#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int N=1e5+1;

vector<vector<int>> dv({{1,0,0,0,0},{0,1,0,0,0},{0,0,1,0,0},{0,0,0,1,0},{0,0,0,0,1}});

vector<vector<int>> mul(vector<vector<int>>& a, vector<vector<int>>& b)
{
    int n=a.size(),m=b.size();
    vector<vector<int>> ans(n,vector<int>(m));
    for(int i=0; i< n; i++)
    {
        for(int j=0; j< m; j++)
        {
            for(int k=0; k< n; k++)
            {
                ans[i][j]=(ans[i][j]+a[i][k]*b[k][j]%mod)%mod;
            }
        }
    }
    return ans;
}
vector<vector<int>> power(vector<vector<int>>& a, int b)
{
    vector<vector<int>> ans=dv;
    while(b)
    {
        if(b&1)
        {
            ans=mul(ans,a);
        }
        b/=2;
        a=mul(a,a);
    }
    return ans;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    vector<vector<int>> base{{0,2,0,2,0},{1,3,1,3,0},{0,0,4,0,0},{0,0,0,4,0},{0,0,1,1,1}};

    vector<vector<int>> ans=power(base,n);
    for(int i=0; i< 5; i++)
    {
        for(int j=0; j<5; j++)
        {
            cout<<ans[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
    vector<vector<int>> clone{{1,1,1,7,2}};
    vector<vector<int>> hh= mul(clone,ans);
    for(int i=0; i< hh.size(); i++)
    {
        for(int j=0; j< hh[0].size(); j++)
        {
            cout<<hh[i][j]<<' ';
        }
        cout<<'\n';
    }

}


