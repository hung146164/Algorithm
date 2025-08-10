class Solution {
public:
    vector<pair<int,int>> m{{100,0},{75,25},{50,50},{25,75}};
    map<pair<int,int>, double> dp; 

    double sol(int a, int b) {
        if(a <= 0 && b <= 0) return 0.5;
        if(a <= 0) return 1.0;
        if(b <= 0) return 0.0;
        auto key = make_pair(a, b);
        if(dp.count(key)) return dp[key];

        double ans = 0;
        for(auto &p : m) {
            ans += sol(a - p.first, b - p.second);
        }
        return dp[key] = ans / 4.0;
    }

    double soupServings(int n) {
        if(n > 4800) return 1.0; // tối ưu
        return sol(n, n);
    }
};
