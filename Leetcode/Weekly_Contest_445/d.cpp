class Solution {
public:
    typedef long long ll;
    int mod = 1e9 + 7;
    int dp[10000][20][2];

    int sol(const string& r, int curr, int pre, bool rb, int& base) {
        if (curr == r.size()) return 1;

        if (pre != -1 && dp[curr][pre][rb] != -1)
            return dp[curr][pre][rb];

        ll ans = 0;
        int to = isdigit(r[curr]) ? r[curr] - '0' : r[curr] - 'A' + 10;

        if (rb) {
            for (int i = (pre == -1 ? 0 : pre); i <= to; i++) {
                ans = (ans + sol(r, curr + 1, i, i == to, base)) % mod;
            }
        } else {
            for (int i = (pre == -1 ? 0 : pre); i < base; i++) {
                ans = (ans + sol(r, curr + 1, i, false, base)) % mod;
            }
        }

        if (pre != -1) dp[curr][pre][rb] = ans;
        return ans;
    }

    string divide(string number, int base, ll& remainder) {
        string result = "";
        remainder = 0;

        for (char digit : number) {
            remainder = remainder * 10 + (digit - '0');
            result += (remainder / base) + '0';
            remainder %= base;
        }

        int i = 0;
        while (i < result.size() && result[i] == '0')
            i++;
        result = result.substr(i);
        return result.empty() ? "0" : result;
    }

    string chuyencoso(string number, ll base) {
        string result = "";
        ll rem;

        while (number != "0") {
            number = divide(number, base, rem);
            if (rem < 10)
                result = char(rem + '0') + result;
            else
                result = char(rem - 10 + 'A') + result;
        }

        return result;
    }

    string subtractOne(string number) {
        int n = number.size();
        int i = n - 1;
        while (i >= 0 && number[i] == '0') {
            number[i] = '9';
            i--;
        }
        if (i >= 0)
            number[i]--;
        if (number[0] == '0')
            number = number.substr(1);
        return number.empty() ? "0" : number;
    }

    int countNumbers(string l, string r, int b) {
        memset(dp, -1, sizeof(dp));
        string r_base = chuyencoso(r, b);
        int right = sol(r_base, 0, -1, true, b);

        memset(dp, -1, sizeof(dp));
        string l_minus = subtractOne(l);
        string l_base = chuyencoso(l_minus, b);
        int left = sol(l_base, 0, -1, true, b);

        return (right - left + mod) % mod;
    }
};
