#include <iostream>
#include <vector>
#include <cstring>
#define MOD 1000267129
using namespace std;
using ll = long long;

ll n;
vector<int> digits;
ll dp[20][2][1024]; // pos, tight, mask

// Extract digits of n into vector
void getDigits(ll x) {
    digits.clear();
    while (x) {
        digits.push_back(x % 10);
        x /= 10;
    }
    reverse(digits.begin(), digits.end());
}

// Digit DP: count how many numbers < n use digits forming 'mask'
ll countDP(int pos, bool tight, int mask) {
    if (pos == digits.size()) return mask == 0 ? 0 : 1;
    if (dp[pos][tight][mask] != -1) return dp[pos][tight][mask];

    int limit = tight ? digits[pos] : 9;
    ll res = 0;

    for (int d = 0; d <= limit; ++d) {
        int new_mask = mask;
        if (!(mask == 0 && d == 0))  // skip leading zeros
            new_mask |= (1 << d);

        res += countDP(pos + 1, tight && (d == limit), new_mask);
    }

    return dp[pos][tight][mask] = res;
}

// Precompute count[mask] = number of numbers < n with digits forming 'mask'
void computeMaskCounts(vector<ll>& count) {
    memset(dp, -1, sizeof(dp));
    count.assign(1024, 0);

    for (int mask = 1; mask < 1024; ++mask) {
        memset(dp, -1, sizeof(dp));

        function<ll(int, bool, int)> dfs = [&](int pos, bool tight, int current_mask) -> ll {
            if (pos == digits.size()) return (current_mask == mask) ? 1 : 0;
            if (dp[pos][tight][current_mask] != -1) return dp[pos][tight][current_mask];

            int limit = tight ? digits[pos] : 9;
            ll res = 0;

            for (int d = 0; d <= limit; ++d) {
                int next_mask = current_mask;
                if (!(current_mask == 0 && d == 0))  // skip leading zeros
                    next_mask |= (1 << d);
                res += dfs(pos + 1, tight && (d == limit), next_mask);
            }

            return dp[pos][tight][current_mask] = res;
        };

        memset(dp, -1, sizeof(dp));
        count[mask] = dfs(0, true, 0);
    }
}

// Modular inverse of 2 mod MOD
ll modinv2() {
    return (MOD + 1) / 2;
}

int main() {
    n = 1e18;
    getDigits(n);

    // Step 1: count how many numbers < n exist for each digit mask
    vector<ll> count;
    computeMaskCounts(count);

    // Step 2: compute total pairs
    ll total = ((n - 1) % MOD) * ((n - 2) % MOD) % MOD;
    total = total * modinv2() % MOD;

    // Step 3: subtract non-friend pairs (disjoint masks)
    ll nonFriendPairs = 0;
    for (int m1 = 1; m1 < 1024; ++m1) {
        for (int m2 = m1 + 1; m2 < 1024; ++m2) {
            if ((m1 & m2) == 0) {
                ll pairs = count[m1] * count[m2] % MOD;
                nonFriendPairs = (nonFriendPairs + pairs) % MOD;
            }
        }
    }

    // Final answer
    ll result = (total - nonFriendPairs + MOD) % MOD;
    cout << result << endl;
    return 0;
}
