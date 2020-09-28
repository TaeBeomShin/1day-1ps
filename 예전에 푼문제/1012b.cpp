#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
#define X first
#define Y second

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0 ,0 ,1 ,-1 };
    
int main(void) {
	fastio;
    int t,m,n,k;
    cin>>t;
    
    while (t--) {
        cin>>m>>n>>k;
        int board[50][50] = { 0, }; // 0 : 배추 없음 1 : 배추 있음, 아직 방문 안함 2 : 배추 있음, 방문함
        while(k--){
            int x, y;cin>>x>>y;
            board[x][y] = 1;
        }
        
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
				if (board[i][j] == 1) { // 아직 방문하지 않았고 배추가 있는 곳을 찾았다면
                    count++; // 벌레를 한 마리 둠
                    board[i][j] = 2;
                    queue<pair<int,int> > Q;
                    Q.push({i,j});
                    while (!Q.empty()) {
                        auto cur = Q.front(); Q.pop();
                        for (int dir = 0; dir < 4; dir++) {
                        	int nx=cur.X+dx[dir];
                        	int ny=cur.Y+dy[dir];
                        	
                            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                            if (board[nx][ny] == 1) {
                                Q.push({nx,ny});
                                board[nx][ny] = 2;
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n", count);
    }
}
