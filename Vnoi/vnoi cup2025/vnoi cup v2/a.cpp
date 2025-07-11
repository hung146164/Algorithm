#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int mod=1e9+7;

const int dx[] {0,0,-1,1};
const int dy[] {-1,1,0,0};

bool check(vector<vector<int>>& a, vector<vector<int>>& b)
{
    int n=a.size(),m =a[0].size();
    vector<vector<bool>> oc(n,vector<bool>(m,false));
    for(int i=0; i< n; i++)
    {
        for(int j=0; j< m ; j++)
        {

            int top=a[i-1<0?n-1:i-1][j];
            int left=a[i][j-1<0?m-1:j-1];
            int right=a[i][j+1==m?0:j+1];
            int down=a[i+1==n?0:i+1][j];
//            cout<<top<<' '<<left<<' '<<' '<<right<<' '<<down<<endl;
            //cout<<"candidate: "<<endl;
            bool have=false;
            for(int ii=0; ii<n; ii++)
            {
                for(int jj=0; jj< m; jj++)
                {
                    if(oc[ii][jj]) continue;
                    int top1=b[ii-1<0?n-1:ii-1][jj];
                    int left1=b[ii][jj-1<0?m-1:jj-1];
                    int right1=b[ii][jj+1==m?0:jj+1];
                    int down1=b[ii+1==n?0:ii+1][jj];
//                    cout<<top1<<' '<<left1<<' '<<' '<<right1<<' '<<down1<<endl;
                    if(top==top1 && left==left1 && right==right1 && down == down1 && a[i][j]==b[ii][jj])
                    {
                        oc[ii][jj]=true;
                        have=true;
                        break;
                    }
                }
                if(have) break;
            }
            if(!have)
            {
//                cout<<"case: "<<i<<' '<<j<<endl;
                return false;
            }
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m ;
        cin>>n>>m;
        vector<vector<int>> a(n,vector<int>(m));
        vector<vector<int>> b=a;

        for(int i=0; i< n; i++)
        {
            for(int j=0; j< m ; j++)
            {
                cin>>a[i][j];
            }
        }
        for(int i=0; i< n; i++)
        {
            for(int j=0; j< m ; j++)
            {
                cin>>b[i][j];
            }
        }
        cout<<(check(a,b)?"YES":"NO")<<'\n';
    }
}
