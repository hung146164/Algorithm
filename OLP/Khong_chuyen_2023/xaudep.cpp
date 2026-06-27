#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int N=1e5+1;


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q; cin>>n>>q;
    vector<vector<int>> cnt(n,vector<int>(26));
    string s; cin>>s;
    for(int i=0; i< n; i++)
    {
        for(int j=0; j< 26; j++)
        {
            cnt[i][j]=(i-1>=0?cnt[i-1][j]:0)+( j==(s[i]-'a')?1:0);
            //cout<<cnt[i][j]<<' ';
        }
//        cout<<'\n';
    }
    while(q)
    {
        int a,b; cin>>a>>b;
        int le=0;
        for(int j=0; j< 26; j++)
        {
            if( (cnt[b][j]-(a-1>=0?cnt[a-1][j]:0)) %2==1)
            {
                le++;
            }
            if(q==1)
            {
                //cout<<cnt[b][j]-cnt[a-1][j]<<'\n';
            }
        }

        cout<<le/2<<'\n';
        q--;
    }
}


