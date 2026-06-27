#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int N=1e5+1;
int num[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("final_product_chapter_1_input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t; cin>>t;
    for(int k=1; k<=t;k++)
    {
        int n; cin>>n;
        int a; cin>>a;
        int b; cin>>b;

        vector<int> ans(2*n);
        for(int j=0; j<n; j++)
        {
            ans[j]=1;
        }
        for(int j=0; j<2*n-1; j++)
        {
            ans[j]=1;
        }
        ans[2*n-1]=b;

        cout << "Case #" << k << ": ";
        for(int i=0;i<ans.size(); i++)
        {
            cout<<ans[i]<<' ';
        }
        cout<<'\n';
    }


}



