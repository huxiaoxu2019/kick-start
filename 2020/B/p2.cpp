// solved
#include <bits/stdc++.h>
using namespace std;
void solve(int t) {
    long long N, D;
    cin >> N;
    cin >> D;
    
    vector<long long> nums(N, 0);
    vector<long long> ans(N, 0);
    for (int i = 0; i < N; ++i) {
        long long n;
        cin >> n;
        nums[i] = n;
    }

    for (int i = N - 1; i >= 0; --i) {
        ans[i] = D - (D % nums[i]);
        D = ans[i];
    }


    cout << "Case #" << t << ": " << ans[0] << endl;
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
