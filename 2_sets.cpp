#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    long long total = 1LL * n * (n + 1) / 2;

    if (total % 2 != 0) {
        cout << "NO\n";
        return 0;
    }

    vector<int> a, b;
    long long target = total / 2;

    for (int i = n; i >= 1; --i) {
        if (i <= target) {
            a.push_back(i);
            target -= i;
        } else {
            b.push_back(i);
        }
    }

    cout << "YES\n";
    cout << a.size() << "\n";
    for (int x : a) cout << x << " ";
    cout << "\n" << b.size() << "\n";
    for (int x : b) cout << x << " ";
    cout << "\n";

    return 0;
}
