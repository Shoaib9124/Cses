#include <bits/stdc++.h>
using namespace std;

void test(const vector<long long>& prefix) {
    int a, b;
    cin >> a >> b;
    cout << prefix[b] - prefix[a - 1] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<long long> prefix(n + 1, 0); // prefix[0] = 0
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + nums[i];
    }

    while (q--) {
        test(prefix);
    }

    return 0;
}
