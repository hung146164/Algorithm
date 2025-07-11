#include <bits/stdc++.h>
using namespace std;

string biendoi(string s, string a, string b)
{
    int x = a.size();
    stack<char> st;

    for (char ch : s) {
        st.push(ch);

        if (st.size() >= x) {
            // lấy top x ký tự để so sánh
            string tmp;
            stack<char> tempStack;
            for (int i = 0; i < x; ++i) {
                tmp += st.top();
                tempStack.push(st.top());
                st.pop();
            }
            reverse(tmp.begin(), tmp.end());

            if (tmp == a) {
                // thay thế bằng b
                for (char c : b) st.push(c);
            } else {
                // hoàn lại nguyên trạng
                stack<char> restore;
                while (!tempStack.empty()) {
                    st.push(tempStack.top());
                    tempStack.pop();
                }
            }
        }
    }

    // tạo chuỗi kết quả
    string ans;
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        string s;
        cin >> s;

        reverse(s.begin(), s.end());
        string news = biendoi(s, "pa", "ptp");
        reverse(news.begin(), news.end());

        string ans = biendoi(news, "ptp", "ap");

        cout << ans.size() << '\n';
    }
}
