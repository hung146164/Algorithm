#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int inf=1e4;
vector<unordered_map<string,ll>> dp(1e4+1);
const int mod =1e9+7;
ll ss(string s,int curr, bool ti,ll sum)
{
    ll ans=0;
    if(curr==s.size())
    {
        return sum%3==0;
    }
    string chuoi=to_string(sum)+"|"+to_string(ti);
    if(dp[curr].find(chuoi)!=dp[curr].end()) return dp[curr][chuoi];
    if(ti)
    {
        int to= s[curr]-'0';
        for(int i=0; i<=to;i++)
        {
            ans=(ans+ss(s,curr+1,i==to,sum+i*i))%mod;
        }
    }
    else
    {
       for(int i=0; i<=9;i++)
        {
            ans=(ans+ss(s,curr+1,false,sum+i*i))%mod;
        }
    }
    dp[curr][chuoi]=ans;
    return ans%mod;

}
string subtractOne(string s) {
    int i = s.size() - 1;
    while (i >= 0) {
        if (s[i] > '0') {
            s[i]--;
            break;
        } else {
            s[i] = '9';
            i--;
        }
    }
    // Xóa số 0 đầu (nếu có)
    size_t pos = s.find_first_not_of('0');
    if (pos != string::npos)
        return s.substr(pos);
    return "0";
}

int main(void)
{
    string n;
    cin >> n;
    string m = subtractOne(n);

    ll ans = ss(m, 0, true, 0);
    cout << ans << '\n';
}
