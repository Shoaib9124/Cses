#include <bits/stdc++.h>
using namespace std;

/*
19th

123456789 101112131 4
 9           10     19

start=1;
digits=1;
count=9;

1011 1213141516....

k>disgits*count;
9
19-9=10
start=10;

start+k


90
900



19
1 2 3 4 5 6 7 8 9||  10 11 12 13| 14 15....

9->skipped
10 now
10 digit starting from 10
10+9/2

(14)
k=10 if(9%2)

*/




void test_case() {
    long long k;
    cin >> k;

    long long digits = 1;
    long long count = 9;
    long long start = 1;

    // Step 1: Find the length of numbers (1-digit, 2-digit, etc.) where the k-th digit lies
    while (k > digits * count) {
        k -= digits * count;
        digits++;
        count *= 10;
        start *= 10;
    }

    // Step 2: Find the exact number where k-th digit lies
    long long number = start + (k - 1) / digits;
    string s = to_string(number);

    // Step 3: Find the digit in that number
    cout << s[(k - 1) % digits] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;

    while (q--) {
        test_case();
    }

    return 0;
}
