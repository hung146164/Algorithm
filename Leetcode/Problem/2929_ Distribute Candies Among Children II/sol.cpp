typedef long long ll;
class Solution {
public:
    long long distributeCandies(int n, int limit) {
        if(limit*3<n) return 0;
        ll vachngan=n+2;
        ll total=vachngan*(vachngan-1)/2;
        if(n<=limit)
        {
            return total;
        }
        ll a=n-limit-1+2;
        ll sum=a*(a-1)/2*3;
        if(n-2*limit-2>=0)
        {
            ll c=n-2*limit;
            sum-=(c*(c-1)/2)*3;
        }
        if(n-3*limit-3>=0)
        {
            ll c=n-3*limit-1;
            sum-=(c*(c-1)/2);
        }
        return total-sum;
    }
};