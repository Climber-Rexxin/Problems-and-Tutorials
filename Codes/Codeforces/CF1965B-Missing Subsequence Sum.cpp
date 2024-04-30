#include <iostream>
using namespace std;

const int MAXN = 25;
int a[MAXN];

inline int low_bit(int x) {
    return x & (-x);
}

int high_bit(int x) {
    return x == low_bit(x) ? x : high_bit(x ^ low_bit(x));
}

void solve() {
    int n, k;
    cin >> n >> k;
    int bit = high_bit(k);
    cout << 22 << endl;
    for (int i = 0; i < 20; i++) {
        int temp = 1 << i;
        cout << (bit == temp ? bit * 3 : temp) << " ";
    }
    cout << k - bit << " " << k + 1 << endl;
}

int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        solve();
    }
}
