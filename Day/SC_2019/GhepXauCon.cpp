#include "orallib.h"
#include <vector>

void run() {
    int n = get_N();
    int p = 0;
    std::vector<bool> f(n + 1, false);

    for (int i = 0; i < n; ++i) {

        std::vector<int> V;
        for (int x = p; x <= n; ++x) {
            if (!f[x]) {
                V.push_back(x);
            }
        }


        int k = 0;
        if (V.size() >= 2) {
            k = V[V.size() - 2];
        } else if (V.size() == 1) {
            k = V[0];
        }

        int res = guess(k);
        if (res == 1) {
            p++;
        } else {
            f[k] = true;
        }
    }
}
