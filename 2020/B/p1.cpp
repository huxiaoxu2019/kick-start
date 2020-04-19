// solved
#include <bits/stdc++.h>
using namespace std;
void solve(int t) {
    int N;
    cin >> N;
    
    vector<int> nums(N, 0);
    for (int i = 0; i < N; ++i) {
        int n;
        cin >> n;
        nums[i] = n;
    }

    int cnt = 0;
    for (int i = 1; i < N - 1; ++i) {
        if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
            ++cnt;
        }
    }

    cout << "Case #" << t << ": " << (cnt) << endl;
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
