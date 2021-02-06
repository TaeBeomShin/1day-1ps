#include <iostream>
using namespace std;

int main() {
    int n, m;
    int answer[100][100] = {0};
    cin >> n >> m;
    
    // Step 1:
    int count = 0;
    for(int col = 0; col < m; col++) {
        if (col % 2 == 0){
            // Case 1:
            for(int row = 0; row < n; row++){
                answer[row][col] = count;
                count++;
            }
        }
        else {
            // Case 2:
            for(int row = n - 1; row >= 0; row--){
                answer[row][col] = count;
                count++;
            }
        }
    }
    
    for(int row = 0; row < n; row++) {
        for(int col = 0; col < m; col++) 
            cout << answer[row][col] << " ";
        cout << endl;
    }
    return 0;
}
