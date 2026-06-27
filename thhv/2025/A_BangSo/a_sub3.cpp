#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int N=1e6+5;

ll maxll(ll a,ll b)
{
    if(a>b) return a;
    return b;
}
ll minll(ll a,ll b)
{
    if(a>b) return b;
    return a;
}
ll gdc(ll a, ll b)
{
    if(b==0) return a;
    return gdc(b,a%b);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin>>n>>m;
    vector<vector<int>> g(n,vector<int>(m));
    for(int i=0; i< n; i++)
    {
        for(int j=0; j< m; j++)
        {
            cin>>g[i][j];
        }
    }
    int ans=1;
    for(int top=0; top<n; top++)
    {
        for(int down=n-1; down>=top ; down--)
        {
            for(int left=0; left<m; left++)
            {
                vector<int> dem(1000005);
                int right=0;1
            }
            int left=0;
            int right=0;
            while(right<m)
            {
                for(int thang=top; thang<=down; thang++)
                {
                    dem[g[thang][right]]++;
                    while(dem[g[thang][right]]>1)
                    {
                        for(int i=top ;i<= down ;i++)
                        {
                            dem[g[i][left]]--;
                        }
                        left++;
                    }
                }

                right++;
                ans=max(ans,(right-left)*(down-top+1));
            }
        }
    }
    cout<<ans<<'\n';
}

