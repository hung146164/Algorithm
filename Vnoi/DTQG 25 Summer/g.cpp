#include<bits/stdc++.h>
using namespace std;

vector<int> sangnt(int r, unordered_map<int,int>& primeindex)
{
    vector<bool> nt(r+1,true);
    vector<int> ans;
    int idx = 0;
    for(int i=2;i<=r; i++)
    {
        if(nt[i])
        {
            ans.push_back(i);
            primeindex[i] = idx++;
            for(long long j = 1LL * i * i; j <= r; j += i)
            {
                nt[j]=false;
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l, r; cin >> l >> r;
    unordered_map<int,int> prime_idx;
    vector<int> nt = sangnt(r, prime_idx);

    unordered_map<long long, int> dp;
    for (int i = max(2, l); i <= r; ++i) {
        int num = i;
        long long tich = 1;
        for (int p : nt) {
            if (1LL * p * p > num) break;
            if (num % p == 0) {
                tich *= p;
                while (num % p == 0) num /= p;
            }
        }
        if (num > 1) {
            tich *= num;
        }
        dp[tich]++;
    }

    long long ans = 0;
    for (auto& i : dp) {
        //cout<<i.first<<" "<<i.second<<endl;
        int val=i.second;
        ans += 1LL * val * (val - 1) / 2;
    }
    cout << ans << '\n';
}
