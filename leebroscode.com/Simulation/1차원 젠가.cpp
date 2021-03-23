#include <iostream>

#define MAX_N 100

using namespace std;

int n;
int numbers[MAX_N];

int end_of_array;

// �Է� �迭���� ������� �ϴ� �κ� ������ �����մϴ�.
void CutArray(int start_idx, int end_idx) {
    int cut_len = end_idx - start_idx + 1;
    for(int i = end_idx + 1; i < end_of_array; i++) {
        numbers[i - cut_len] = numbers[i];
    }
    
    end_of_array -= cut_len;
}

int main() {
	// �Է�:
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> numbers[i];
    
    end_of_array = n;
	
    // �� ���� ���� ����� ������ �ݺ��մϴ�.
	for(int k = 0; k < 2; k++) {
		int s, e;
		cin >> s >> e; s--; e--;
        // [s, e] ������ �����մϴ�.
        CutArray(s, e);
	}
	
    // ���:
	cout << end_of_array << endl;
	for(int i = 0; i < end_of_array; i++)
		cout << numbers[i] << endl;
	
	return 0;
}
