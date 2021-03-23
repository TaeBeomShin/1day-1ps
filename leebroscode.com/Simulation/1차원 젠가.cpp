#include <iostream>

#define MAX_N 100

using namespace std;

int n;
int numbers[MAX_N];

int end_of_array;

// 입력 배열에서 지우고자 하는 부분 수열을 삭제합니다.
void CutArray(int start_idx, int end_idx) {
    int cut_len = end_idx - start_idx + 1;
    for(int i = end_idx + 1; i < end_of_array; i++) {
        numbers[i - cut_len] = numbers[i];
    }
    
    end_of_array -= cut_len;
}

int main() {
	// 입력:
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> numbers[i];
    
    end_of_array = n;
	
    // 두 번에 걸쳐 지우는 과정을 반복합니다.
	for(int k = 0; k < 2; k++) {
		int s, e;
		cin >> s >> e; s--; e--;
        // [s, e] 구간을 삭제합니다.
        CutArray(s, e);
	}
	
    // 출력:
	cout << end_of_array << endl;
	for(int i = 0; i < end_of_array; i++)
		cout << numbers[i] << endl;
	
	return 0;
}
