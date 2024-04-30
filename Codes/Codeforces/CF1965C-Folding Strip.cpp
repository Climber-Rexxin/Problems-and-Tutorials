#include <iostream>
using namespace std;

const int MAXN = 2e5 + 5;
char s[MAXN];

void solve() {
    int n;
    cin >> n >> s + 1;
    int max_val = 0, min_val = 0;
    int sum = 0, tag = 1;
    for (int i = 1; i <= n; i++) {
        if (s[i] == s[i - 1])
            tag = - tag;
        sum += tag;
        max_val = max(max_val, sum);
        min_val = min(min_val, sum);
    }
    cout << max_val - min_val << endl;
}

int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        solve();
    }
}
