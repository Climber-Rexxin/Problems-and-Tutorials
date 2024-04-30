#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

const int MAXN = 2e5 + 5;
int a[MAXN];

bool sg(const ll removed, int cur, const int total) {
    if (cur > total)
        return false;
    if (a[cur] == removed)
        return sg(removed, cur + 1, total);
    if (a[cur] > removed + 1)
        return true;
    else
        return !sg(removed + 1, cur + 1, total);
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    cout << (sg(0, 1, n) ? "Alice" : "Bob") << endl;
}

int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        solve();
    }
}
