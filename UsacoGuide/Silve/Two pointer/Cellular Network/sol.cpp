#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> city,tower;
    for(int i=0; i< n; i++)
    {
        int x; cin>>x;
        city.push_back(x);
    }
    for(int j=0; j< m ; j ++ )
    {
        int x; cin>>x;
        tower.push_back(x);
    }
    sort(city.begin(), city.end());
    sort(tower.begin(), tower.end());
    int l=0;
    int r= max(abs(city[0]-tower[m-1]),abs(city[n-1]-tower[0]));
    int ans=r;
    while(l<=r)
    {
        int mid=l+(r-l)/2;

        int cc=0;
        for(int i=0; i< tower.size(); i++)
        {
            while(cc<city.size() && city[cc]>=tower[i]-mid && city[cc]<=tower[i]+mid)
            {
                cc++;
            }
        }
        if(cc==city.size())
        {
            ans=min(ans,mid);
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }

    }
    cout<<ans<<endl;
}
