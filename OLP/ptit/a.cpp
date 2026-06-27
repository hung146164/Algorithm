#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; cin>>n>>m;
    vector<int> to(n);
    //vector<int> nums;
    for(int i=0; i< n; i++)
    {
        int x; cin>>x;
        //nums.push_back(x);
        to[i]=x;
    }
    while(m--)
    {
        int a,b; cin>>a>>b;
        swap(to[a],to[b]);
        int ans=0;
        vector<bool> check(n);
        for(int i=0; i< n;i++)
        {
            if(!check[i])
            {
                ans++;
                int curr=i;
                while(!check[curr])
                {
                    check[curr]=true;
                    curr=to[curr];
                }
            }
        }
        cout<<ans<<'\n';
        swap(to[a],to[b]);
//        to[a]=nums[b];
//        to[b]=nums[a];
//        for(int i=0; i< to.size(); i++) cout<<to[i]<<' ';
//        cout<<'\n';
    }

}


