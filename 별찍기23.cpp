#include <iostream>
using namespace std;
int main() {
    int idx;
    cin >> idx;
    int i = 1;
    int diff = 0;
    for(int sum = 0; sum+i < idx; i++)
    {
        sum += i;
        diff = idx - sum;
    }
    if(i%2 == 1)
        cout << i-diff+1 << "/" << diff;
    else
        cout << diff << "/" << i-diff+1;
    return 0;
}
