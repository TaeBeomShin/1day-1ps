#include <bits/stdc++.h>
using namespace std;
//dp[i][j][k] 정의 (i,j)에 있을 때 더 이동하는 것이  가능한가? 
int dp[1001][1001][2];

bool flag;
int answer;
int go(vector<string> &drum, int x, int y, int flag) {
    if(x == drum.size()) {
        return 1;
    }
    
    int ret = dp[x][y][flag];
    if(ret != -1) {
        return dp[x][y][flag];
    }
    if(drum[x][y] == '#') {
       dp[x][y][flag] = go(drum, x + 1, y, flag);
    }
    else if(drum[x][y] == '>') {
       dp[x][y][flag] = go(drum, x, y + 1, flag);
    } 
    else if(drum[x][y] == '<') {
        dp[x][y][flag] = go(drum, x, y - 1, flag);
    }
    else if(drum[x][y] == '*') {
        if(flag) return 0 ;
        else dp[x][y][flag] = go(drum, x + 1, y, 1);
    }
    return dp[x][y][flag];
}
int solution(vector<string> drum) {
    for(int i = 0; i < drum.size(); i++) {
        flag = false;
        answer += go(drum, 0, i, 0);
    }
    return answer;
}
int main() {
    vector<string> drum;
    memset(dp, -1, sizeof(dp));
    drum.push_back("######");
    drum.push_back(">#*###");
    drum.push_back("####*#");
    drum.push_back("#<#>>#");
    drum.push_back(">#*#*<");
    drum.push_back("######");
    cout << solution(drum);
}

