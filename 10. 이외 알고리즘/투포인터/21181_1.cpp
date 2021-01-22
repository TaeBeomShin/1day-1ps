#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll sum = 0;
ll arr[100010], dp[100010];

int main()
{
	ll n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int r = 1, l = 0; r <= n; r++) {
		sum += arr[r];
		dp[r] = dp[r - 1];
		while (sum >= k) {
			dp[r] = max(dp[r], dp[l] + sum - k);
			sum -= arr[++l];
		}
	}
	cout << dp[n];
	return 0;
}
