#include<bits/stdc++.h>
using namespace std;

int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int main(){
	int n;cin>>n;
	int board[n][n];
	
	vector<pair<int,int>> position;
	vector<int> v(n*n);
	for(int i=0;i<n*n;i++) v[i]=1;
	v[0]=0,v[1]=0,v[2]=0;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>board[i][j];
			position.push_back({i,j});
		}
	}
	
	int ans=1e10;
	do{//���� ��ġ�� ����. 
		vector<pair<int,int>> flowers;
		for(int i=0;i<v.size();i++){
			if(v[i]==0) flowers.push_back({position[i].first,position[i].second});
			//������ ���� ���� ��ġ ����. 
		}
		bool visited[n][n]={0,};
		bool check=true;
		int sum=0;
		for(int i=0;i<3;i++){
		//�� ������ ���� ��ġ�� ������.
			int curx=flowers[i].first,cury=flowers[i].second;
			if(visited[curx][cury]){//�湮�� ���̶�� ����(���� �����ϱ�) 
				check=false;
				break;
			}
			sum+=board[curx][cury];//�湮�� ���� �ƴϸ� ������ġ�� ���� ����.
			visited[curx][cury]=true;
			
			for(int dir=0;dir<4;dir++){
				int nx=curx+dx[dir],ny=cury+dy[dir];
				if(nx<0||nx>=n||ny<0||ny>=n||visited[nx][ny]){//�湮�߰ų� ������ ����� 
					check=false;
					break;
				}
				sum+=board[nx][ny];//������ �����ϸ�,  ������ġ�� ���� ����.
				visited[nx][ny]=true;
			}
			if(!check) break;
		}
		if(!check) continue;
		ans=min(sum,ans);
	}while(next_permutation(v.begin(),v.end()));
	cout<<ans;
} 
