#include <iostream>
using namespace std;

int main() {
    int n, want, ans = 0;
    bool chair[105] = {false, };

    cin >> n;
    while (n--) {
        cin >> want;
        if (chair[want])
            ans++;
        else
            chair[want] = true;
    }
    cout << ans << "\n";
    return 0;
}
