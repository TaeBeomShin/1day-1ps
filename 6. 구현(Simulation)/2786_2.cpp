#include <stdio.h>
#include <algorithm>
#define fst first
#define snd second
using namespace std;
typedef pair<int, int> pii;

int n, k, mn[500001];
long long sum;
pii p[500001];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d %d", &p[i].fst, &p[i].snd);

	sort(p, p + n, [](const pii &i, const pii &j) { return i.snd < j.snd; });

	mn[n] = 2e9;
	for (int i = n - 1; i >= 0; i--) mn[i] = min(p[i].fst, mn[i + 1]);
	for (int i = 0; i < n; i++) {
		if (p[k].snd - p[k].fst < p[i].snd - p[i].fst) k = i;
		sum += (long long)p[i].snd;
		printf("%lld\n", min(sum - p[k].snd + p[k].fst, sum - p[i].snd + mn[i]));
	}

	return 0;
}
