#include <bits/stdc++.h>
using namespace std;

int knap(vector<pair<int,int>>& nums, int hand, int w)
{
    int total = 0;
    for (int i = 0; i < nums.size(); i++)
        if (i != hand) total += nums[i].second;

    vector<int> dp(total + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (i == hand) continue;
        int weight = nums[i].first;
        int value = nums[i].second;

        for (int j = total; j >= value; j--)
        {
            if (dp[j - value] != INT_MAX && dp[j - value] + weight <= w)
            {
                dp[j] = min(dp[j], dp[j - value] + weight);
            }
        }
    }

    for (int i = total; i >= 0; i--)
    {
        if (dp[i] != INT_MAX)
            return i;
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, w, h;
    cin >> n >> w >> h;

    vector<pair<int, int>> nums(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        nums[i] = {x, y};
    }

    int ans = 0;

    for (int i = -1; i < n; i++)
    {
        int extra = 0;
        if (i != -1)
        {
            if (nums[i].first <= h)
                extra = nums[i].second;
            else
                continue;
        }

        ans = max(ans, knap(nums, i, w) + extra);
    }

    cout << ans << '\n';
    return 0;
}
