
using ll = long long;

class Solution {
public:
    string smallestPalindrome(string s, ll k) {
        map<char,int> cnt;
        for(char c: s) cnt[c]++;
        int oddCount = 0;
        char oddChar = 0;
        for (auto &p: cnt) {
            if (p.second % 2) {
                oddCount++;
                oddChar = p.first;
            }
        }
        if (oddCount > 1)
            return "";

        map<char,int> halfFreq;
        vector<char> chars;
        for (auto &p: cnt) {
            chars.push_back(p.first);
            halfFreq[p.first] = p.second / 2;
        }
        int n = 0;
        for (auto &p: halfFreq) n += p.second;
        auto countPerm = [&](auto &self, const map<char,int> &f, ll cap) -> ll {
            int total = 0;
            for (auto &pr: f) total += pr.second;
            ll res = 1;
            int rem = total;
            for (auto &pr: f) {
                int fi = pr.second;
                if (fi == 0) continue;
                __int128 comb = 1;
                for (int j = 1; j <= fi; j++) {
                    comb = comb * (rem - fi + j) / j;
                    if (comb > cap) { comb = cap + 1; break; }
                }
                res = res * (ll)comb;
                if (res > cap) return cap + 1;
                rem -= fi;
            }
            return res;
        };

        string halfAns;
        halfAns.reserve(n);
        for (int pos = 0; pos < n; pos++) {
            bool placed = false;
            for (char c: chars) {
                if (halfFreq[c] == 0) continue;
                halfFreq[c]--;
                ll perms = countPerm(countPerm, halfFreq, k);
                if (k <= perms) {
                    halfAns.push_back(c);
                    placed = true;
                    break;
                }
                k -= perms;
                halfFreq[c]++;
            }
            if (!placed)
                return "";
        }

        // 6) Ghép palindrome
        string rev = halfAns;
        reverse(rev.begin(), rev.end());
        string mid = (oddCount == 1 ? string(1, oddChar) : "");
        return halfAns + mid + rev;
    }
};
