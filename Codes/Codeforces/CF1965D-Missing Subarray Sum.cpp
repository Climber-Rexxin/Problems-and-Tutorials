#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define ll long long
using namespace std;

const int MAXN = 1e3 + 5;
int a[MAXN], b[MAXN];

void reconstruct(const vector<ll> &vec, int *dst, int n) {
    int vec_size = (int)vec.size();
    ll last = vec[0];
    dst[vec_size] = n % 2 == 1 ? vec[0] : vec[0] / 2;
    for (int i = 1; i < vec_size; i++) {
        dst[vec_size - i] = (vec[i] - last) / 2;
        last = vec[i];
    }
    for (int i = 1; i <= vec_size; i++)
        dst[n + 1 - i] = dst[i];
}

void solve() {
    int n, temp;
    cin >> n;
    map<int, int> count;
    for (int i = 1; i <= n * (n + 1) / 2 - 1; i++) {
        cin >> temp;
        count[temp * 2]++;
    }
    vector<ll> center;
    for (const auto &[key, val]: count)
        if (val % 2 == 1)
            center.push_back(key);
    int center_num = (int)center.size();
    int k = (n + 1) / 2;
    int total_num = center_num * 2 - (n % 2);
    reconstruct(center, b, total_num);
    for (int l = 1; l <= total_num; l++) {
        int sum = 0;
        for (int r = l; r <= total_num; r++) {
            sum += b[r];
            count[sum]--;
        }
    }
    while ((--count.end())->second == 0)
        count.erase(--count.end());    
    int max_val = (--count.end())->first;
    int total_val = center.back();
    ll diff = max_val * 2LL - total_val;
    if (center_num == k - 1) {
        center.push_back(diff);
        sort(center.begin(), center.end());
    } else if (center_num == k + 1) {
        center.erase(find(center.begin(), center.end(), diff));
    }
    reconstruct(center, a, n);
    for (int i = 1; i <= n; i++)
        cout << a[i] / 2 << " ";
    cout << endl;
}

int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        solve();
    }
}
