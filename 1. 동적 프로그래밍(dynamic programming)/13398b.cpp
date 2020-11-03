#include <iostream>
#include <algorithm>
#include <climits>

#define MAX 100050

using namespace std;

int a[MAX + 1];
int dl[MAX + 1]; // dl[i] : a[1] ~ a[i]에서의 최대합
int dr[MAX + 1]; // dr[i] : a[i] ~ a[n]에서의 최대합

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	int maxSum = INT_MIN; // 최종 결과값

	for (int i = 1; i <= n; ++i) cin >> a[i];

	if (n == 1){
		cout << a[n] << "\n";
	}	
	else
	{
		for (int i = 1; i <= n; ++i) dl[i] = max(a[i], dl[i - 1] + a[i]);
		
		for (int i = n; i >= 1; --i) dr[i] = max(a[i], dr[i + 1] + a[i]);

		for (int i = 1; i <= n; ++i){
			if (maxSum < dl[i]) maxSum = dl[i];
		}
		
		for (int i = 1; i <= n; ++i) maxSum = max(maxSum, dl[i - 1] + dr[i + 1]);

		cout << maxSum << "\n";
	}
}

