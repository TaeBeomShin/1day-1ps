#include <bits/stdc++.h>
using namespace std;
 
int visited[50][50];
int ch, board[50][50];
int N, L, R;
bool chk = true;
int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
int ans = 0;
queue<pair<int, int>> q;      //bfs용
queue<pair<int, int>> pos; //연합의 좌표를 저장
    
int main(){
    ios_base::sync_with_stdio(false);
     
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    }
 
    while (chk){
        ch++;
        chk = false; ans += 1;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if (visited[i][j] == ch) continue;
                int sum = board[i][j];
                q.push({ j, i });
                pos.push({ j, i });
                visited[i][j] = ch;
 
                while (!q.empty()){
                    int x_tmp = q.front().first;
                    int y_tmp = q.front().second;
                    q.pop();
 
                    for (int k = 0; k < 4; k++){
                        int x = x_tmp + dx[k];
                        int y = y_tmp + dy[k];
                        if (x < 0 || y < 0 || x >= N || y >= N) continue;
						if(visited[y][x] == ch) continue;
						if(abs(board[y_tmp][x_tmp] - board[y][x]) < L || abs(board[y_tmp][x_tmp] - board[y][x])>R) continue;
                        chk = true;
                        q.push({ x, y });
                        pos.push({ x, y });
                        sum += board[y][x];
                        visited[y][x] = ch;
                    }
                }
 
                int avr = sum / pos.size();
 
                while (!pos.empty()){
                    board[pos.front().second][pos.front().first] = avr;
                    pos.pop();
                }
            }
        }
 
    }
    cout << ans - 1;
}

