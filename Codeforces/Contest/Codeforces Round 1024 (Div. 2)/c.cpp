

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> ans(n, vector<int>(n, 0));

        int top = 0, down = n - 1;
        int left = 0, right = n - 1;
        int c = 0;

        //  Ma tran xoan oc (spiral matrix)
        while (top <= down && left <= right) {
            for (int i = left; i <= right; ++i)
                ans[top][i] = c++;
            top++;

            for (int i = top; i <= down; ++i)
                ans[i][right] = c++;
            right--;

            if (top <= down) {
                for (int i = right; i >= left; --i)
                    ans[down][i] = c++;
                down--;
            }

            if (left <= right) {
                for (int i = down; i >= top; --i)
                    ans[i][left] = c++;
                left++;
            }
        }
        //dao chieu
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                ans[i][j] = n * n - 1 - ans[i][j];

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                cout << ans[i][j] << " ";
            cout << endl;
        }
    }
}
