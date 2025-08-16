class Solution {
public:
    int countLargestGroup(int n) {
        map<int,int> dp;
        int ans=0;
        int c=0;
        for(int i=1; i<= n; i++)
        {
            int clone= i;
            int sum=0;
            while(clone)
            {
                sum+=clone%10;
                clone/=10;
            }
            dp[sum]++;

            c=max(c,dp[sum]);
        }
        for(auto i: dp)
        {
            if(i.second==c) ans++;
        }
        return ans;

        return ans;

    }
};
