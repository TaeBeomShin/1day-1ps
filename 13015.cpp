#include <bits/stdc++.h>
using namespace std;
 
int main(void) {
    int n;
    cin >> n;
 
    int a = 0, b = n - 1;
    int c = 3 * n - 3, d = 4 * n - 4;
 
    for (int i = 1; i < 2 * n; ++i) {
        // ù��° Ȥ�� ������ ���� ���
        if (i == 1 || i == (2 * n) - 1) {
            for (int j = a; j <= b; j++) printf("*");
            for (int j = b + 1; j < c; j++) printf(" ");
            for (int j = c; j <= d; j++) printf("*");
        }
        else {
            for (int j = 0; j < a; j++) printf(" ");
            printf("*"); // a
            for (int j = a + 1; j < b; j++) printf(" ");
            printf("*"); // b
            for (int j = b + 1; j < c; j++) printf(" ");
            // b�� c�� ��ġ�� ������ ��� �ߺ� ��� x
            if(b != c) printf("*"); // c
            for (int j = c + 1; j < d; j++) printf(" ");
            printf("*"); // d
        }
        printf("\n");
 
 
        if (i < n) {
            a++; b++; c--; d--;
        }
        else {
            a--; b--; c++; d++;
        }
    }
    return 0;
}

