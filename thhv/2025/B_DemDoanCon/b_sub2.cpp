#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int N=1e5+1;

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

    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> nums;
    for(int i=0; i< n; i ++)
    {
        int x;
        cin>>x;
        nums.push_back(x);
    }
    vector<int> cc(k+1);
    int ans=0;

    int len = k * (k + 1) / 2;
    if (len > n) { // không có đoạn đủ dài
        cout << 0 << '\n';
        return 0;
    }

    for(int i=0; i< nums.size(); i++)
    {
        cc[nums[i]]++;
        if(i-len>=0)
        {
            cc[nums[i-len]]--;
        }
        if(i>=len-1)
        {
            vector<bool> check(100001,false);
            for(int j=1; j<=k;j++)
            {
                check[cc[j]]=true;
            }

            bool ok=true;
            for(int j=1; j<=k ;j++)
            {
                if(!check[j])
                {
                    ok=false;break;
                }
            }
            if(ok) ans++;
        }

    }
    cout<<ans<<'\n';
}


