#include<bits/stdc++.h>
#define MAX 51
using namespace std;
int x, y;
char arr[MAX][MAX];
bool Col[MAX];
bool Row[MAX];

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> x >> y;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'X') {
				Col[i] = true; Row[j] = true;
			}
		}
	}
	int True_x = 0, True_y = 0;
	for (int i = 0; i < x; i++)
		if (Col[i]) True_x++;
	for (int i = 0; i < y; i++)
		if (Row[i]) True_y++;
	cout << max(x - True_x, y - True_y);
}
