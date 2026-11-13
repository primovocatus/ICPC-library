/**
 * Author: 
 * Description: In place: dp[mask] := sum of dp[sub] over all submasks. Supersets: if (!(mask >> i \& 1)),
 * dp[mask] += dp[mask | 1 << i]. Inverse: -= instead of +=.
 * Time: O(K 2^K)
 */
#pragma once

const int K = 20;
ll dp[1 << K];

void sos() {
	for (int i = 0; i < K; ++i)
		for (int mask = 0; mask < (1 << K); ++mask)
			if (mask >> i & 1) dp[mask] += dp[mask ^ (1 << i)];
}
