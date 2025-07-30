#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    map<char, int> freq;
    for (char c : s) freq[c]++;

    for (auto &[ch, f] : freq) {
        if (f > (n + 1) / 2) {
            cout << -1 << '\n';
            return 0;
        }
    }

    string result = "";
    char prev = 0;

    for (int i = 0; i < n; ++i) {
        bool found = false;
        for (auto &[ch, f] : freq) {
            if (f == 0 || ch == prev) continue;

            freq[ch]--;
            bool valid = true;
            for (auto &[x, cnt] : freq) {
                if (cnt > (n - i ) / 2) valid = false;
            }

            if (valid) {
                result += ch;
                prev = ch;
                found = true;
                break;
            }

            freq[ch]++; // backtrack
        }

        if (!found) {
            cout << -1 << '\n';
            return 0;
        }
    }

    cout << result << '\n';
    return 0;
}
