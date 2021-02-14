#include<bits/stdc++.h>
using namespace std;
/*
	BOJ14503 -  �κ�û�ұ�
	
	������ �ٷ� ®�µ� ��ǥ ó���� �̻��ϰ� �ؼ� ������ �ȸ°Գ���..
	
	��ǥó�� �����ؾ��ҵ�. 
*/
int board[51][51]={0,};
bool visited[51][51]={0,};

//0:���� 1:���� 2:���� 3:���� ���������� ���ʹ���. 
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int main(){
	int n,m;cin>>n>>m;
	
	//r: �������� ���� ������ ĭ�� ����, c: �������� ���� ������ ĭ�� ����. 
	int x,y,d;cin>>x>>y>>d;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>board[i][j];
		}
	}
	
	while(true){
		bool flag=false;
		visited[x][y]=true;
		
		//2. ���� ��ġ���� ���� ������ �������� ���ʹ������ ���ʴ�� Ž���� �����Ѵ�.
		int count=0;
		
		for(int i=0;i<4;i++){
			d =(d==0)?d=3:d-1;
			int nx=x+dx[d],ny=y+dy[d];
			count++;
			//2-1. ���� ���⿡ ���� û������ ���� ������ �����Ѵٸ�, �� �������� ȸ���� ���� �� ĭ�� �����ϰ� 1������ �����Ѵ�.
			if(!visited[nx][ny]&&board[nx][ny]==0){// û������ ���� ������ �����ϸ�.0
				x=nx;y=ny;//��ĭ ���� 
				break; 
			}
		}
		if(count==4&&visited[x][y]==true){//�׹��� ��� �� ���Ƿ� ��ǥ�� �״����. 	
			//�ٶ󺸴� ������ ������ ä�� �� ĭ ������ �ϰ� 2������ ���ư���.
			x=x-dx[d];y=y-dy[d];
			if(board[x][y]){
			//���� ������ ���̶� ������ �� �� ���� ��쿡�� �۵��� �����.
				flag=true;
			}
		}
		if(flag) break;
	}
	
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(visited[i][j]) ans++;
		}
	}
	cout<<ans;
}
