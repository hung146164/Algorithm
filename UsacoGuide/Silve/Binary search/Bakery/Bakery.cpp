/* check(mid) denotes whether it is possible to satisfy all the friends with mid operations or less (exactly mid operations does not work, since it isn't necessarily monotonic, since we can't have zero or negative values for the time it takes to make a pastry). Then, we get ranges for x and y (x is the number of times we upgrade for cookies, and y is number of times we upgrade for muffins) using a little bit of math, and the fact that 0 <= x < tc, 0 <= y < tm. The binary search basically checks that each of these ranges contains at least one number, and that the minimum value of x + y is <= mid, and if all these conditions are satisfied, then we can just take the first x, y from the ranges we get, and we get our desired. */
// Problem: Problem 1. Bakery
// Contest: USACO - USACO 2023 February Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=1302
// Memory Limit: 256 MB
// Time Limit: 4000 ms
//
// Powered by CP Editor (https://cpeditor.org)

// I'm back in action

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define f first
#define s second
#define pb push_back

int32_t main() {
   int t;
   cin >> t;

   while (t--) {
   	int n, tc, tm;
   	cin >> n >> tc >> tm;

   	vector<int> a(n), b(n), c(n);

   	for (int i = 0; i < n; i++) {
   		cin >> a[i] >> b[i] >> c[i];
   	}

   	vector<int> need(n);
   	for (int i = 0; i < n; i++) {
   		need[i] = max(0ll, (a[i] * tc) + (b[i] * tm) - c[i]);
   	}
   	for(int i=0; i< need.size(); i++) cout<<need[i]<<" ";
   	cout<<endl;
   	function<bool(int)> check = [&](int mid) {
   		// x + y <= mid
   		// a[i] * x + b[i] * y >= need[i]
   		// x < tc
   		// y < tm

   		int mnx = 0, mny = 0;

   		for (int i = 0; i < n; i++) {
   			if (a[i] > b[i]) {
   				mnx = max(mnx, (((need[i] - (mid * b[i])) + (a[i] - b[i] - 1)) / (a[i] - b[i])));
   			} else if (a[i] < b[i]) {
   				mny = max(mny, (((need[i] - (mid * a[i])) + (b[i] - a[i] - 1)) / (b[i] - a[i])));
   			} else {
   				if (a[i] * mid < need[i]) {
   					return false;
   				}
   			}
   		}

   		if (mnx >= tc || mny >= tm) {
   			return false;
   		}

   		if (mnx + mny > mid) {
   			return false;
   		}

   		return true;
   	};

    int lo = 0, hi = 2e9 + 69, ind = -1;
    while (lo <= hi) {
    	int mid = (lo + hi) / 2;
    	if (check(mid)) {
    		ind = mid;
    		hi = mid - 1;
    	} else lo = mid + 1;
    }
    cout << ind << '\n';
   }
}
