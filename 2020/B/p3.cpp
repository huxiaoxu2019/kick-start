// solved
#include <bits/stdc++.h>
using namespace std;
long long R = 1e9, C = 1e9;
long long r = 1, c = 1;
unordered_map<char, int> d{{'N',0},{'S',1},{'E',2},{'W',3}};
vector<long long> helper(string& line, int start) {
    vector<long long> delta{0, 0, 0, 0, 0}; // N, S, E, W, len
    int i = start;
    int len = 0;
    while (i < line.size()) {
        char c = line[i];
        if (c - '0' >= 2 && '9' - c >= 0) {
            auto next = helper(line, i + 2);
            long long mul = c - '0';
            delta[0] += mul * next[0];
            delta[1] += mul * next[1];
            delta[2] += mul * next[2];
            delta[3] += mul * next[3];
            delta[0] %= R;
            delta[1] %= R;
            delta[2] %= R;
            delta[3] %= R;
            i += 2 + next[4];
        } else if (c == ')') {
            len = i - start + 1;
            break;
        } else {
            // d
            delta[d[c]]++;
            delta[d[c]] %= R;

            if (i == line.size() - 1) {
                len = i - start + 1;
            }

            ++i;
        }
    }
    delta[4] = len;
    return delta;
}
void solve(int t) {
    string line;
    cin >> line;
    auto delta = helper(line, 0);
    r = 1 - delta[0] + delta[1];
    c = 1 +  delta[2] - delta[3];
    if (r < 1) {
        r += R;
    }
    if (c < 1) {
        c += C;
    }
    cout << "Case #" << t << ": " << c << " " << r << endl;
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
