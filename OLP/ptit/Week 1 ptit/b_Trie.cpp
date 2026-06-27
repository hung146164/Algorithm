
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

struct TrieNode {
    int next[26];
    bool end;
    TrieNode() {
        memset(next, -1, sizeof(next));
        end = false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int K;
    cin >> s >> K;

    vector<TrieNode> trie(1); // root
    for (int i = 0; i < K; ++i) {
        string w; cin >> w;
        int cur = 0;
        for (char c : w) {
            int idx = c - 'a';
            if (trie[cur].next[idx] == -1) {
                trie[cur].next[idx] = trie.size();
                trie.emplace_back();
            }
            cur = trie[cur].next[idx];
        }
        trie[cur].end = true;
    }

    int N = s.size();
    vector<int> dp(N + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < N; ++i) {
        if (dp[i] == 0) continue;
        int cur = 0;
        for (int j = i; j < N; ++j) {
            int idx = s[j] - 'a';
            if (trie[cur].next[idx] == -1) break;
            cur = trie[cur].next[idx];
            if (trie[cur].end) {
                dp[j + 1] += dp[i];
                if (dp[j + 1] >= MOD) dp[j + 1] -= MOD;
            }
        }
    }

    cout << dp[N] % MOD << "\n";
    return 0;
}
