// not solved
// monte carlo
#include <bits/stdc++.h>
using namespace std;
int W, H, L, U, R, D;
int CNT = 1000000;
vector<int> d{1, 0, 1};
long long seed = 1;
int base = INT_MAX / 2;
vector<int> getNext(int h, int w) {
    if (h == H && W == w) return {H, W};
    int r = (rand() >= base) ? 1 : 0;
    int nh = h + d[r];
    int nw = w + d[r + 1];
    if (nh > H) {
        nh = H;
        nw++;
    } else if (nw > W) {
        nw = W;
        nh++;
    }
    return {nh, nw};
}
bool rsolve() {
    srand(seed++);
    int h = 1, w = 1;
    int i = 0, limit = W + H - 2;
    while (i < limit) {
        auto next = getNext(h, w);
        if (next[0] >= U && next[0] <= D && next[1] >= L && next[1] <= R) {
            return false;
        }
        if (next[0] > D && next[1] > R) return true;
        h = next[0];
        w = next[1];
        ++i;
    }
    return true;
}
void solve(int t) {
    double p = 0.0;
    double suc = 0, fail = 0;
    cin >> W;
    cin >> H;
    cin >> L;
    cin >> U;
    cin >> R;
    cin >> D;
    for (int i = 0; i < CNT; ++i) {
        bool can = rsolve();
        if (can) ++suc;
        else ++fail;
    }
    p = suc / (suc + fail);
    printf("Case #%d: %.5f\n", t, p);
}
int main() {
    int T;
    cin >> T;
    int i = 1;
    while (i <= T) {
        solve(i);
        ++i;
    }
    return 0;
}
