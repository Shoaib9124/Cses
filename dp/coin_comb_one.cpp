#include <iostream>
#include <vector>

int main() {
    // Use fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n; // Number of coin types
    int x; // Target sum
    std::cin >> n >> x;

    std::vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> coins[i];
    }

    // Modulo constant
    int MOD = 1e9 + 7;

    // dp[i] will store the number of ways to make sum i
    std::vector<int> dp(x + 1, 0);

    // Base case: There's one way to make sum 0 (using no coins)
    dp[0] = 1;

    // Iterate through all sums from 1 to x
    for (int i = 1; i <= x; i++) {
        // For each sum, iterate through all available coins
        for (int coin_value : coins) {
            // Check if we can use this coin
            if (i - coin_value >= 0) {
                // Add the number of ways to form the remaining sum (i - coin_value)
                // to the current sum's count.
                dp[i] = (dp[i] + dp[i - coin_value]) % MOD;
            }
        }
    }

    // The final answer is the number of ways to form the target sum x
    std::cout << dp[x] << std::endl;

    return 0;
}