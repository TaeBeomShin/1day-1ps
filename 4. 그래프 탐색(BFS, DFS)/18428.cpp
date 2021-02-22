#include<bits/stdc++.h>
using namespace std;

char new_board[6][6]={"",};
char board[6][6]={"",};
bool check(int n){
	bool ans=true;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(board[i][j]=='S'&&new_board[i][j]!='S'){
				ans=false;
				break;
			}
		}
	}
	return ans;
}
int main(){
	int n;cin>>n;
	
	
	vector<pair<int,int>> empty;
	vector<pair<int,int>> teachers;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>board[i][j];
			if(board[i][j]=='X'){
				empty.push_back({i,j});
			}
			else if(board[i][j]=='T'){
				teachers.push_back({i,j});
			}
		}
	}
	
	vector<int> v;
	for(int i=0;i<empty.size();i++){
		if(i<3) v.push_back(1);
		else v.push_back(0);
	}
	sort(v.begin(),v.end());
	
	bool ans=false;
	do{
		//1. ��ֹ� 3���� ��ġ�Ѵ�. 
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				new_board[i][j]=board[i][j];
		for(int i=0;i<empty.size();i++){
			if(v[i]==1){
				new_board[empty[i].first][empty[i].second]='O'; 
			}
		}
		//2. �������� ��� �л����� ������ �� �ִ��� Ȯ���Ѵ�.
		//-> �������� �þ߿� �ִ� ���� ��� üũ, üũ�ȵ� �л��� ������ �����Ѱ�.
		for(auto teacher : teachers){
			int cx=teacher.first,cy=teacher.second;
			//��
			int nx=cx,ny=cy;
			while(true){
				ny--;
				if(new_board[nx][ny]=='O'||ny<0) break;
				if(new_board[nx][ny]!='T') new_board[nx][ny]='X';
			}
			//��
			nx=cx,ny=cy;
			while(true){
				nx++;
				if(new_board[nx][ny]=='O'||nx>=n) break;
				if(new_board[nx][ny]!='T') new_board[nx][ny]='X';
			}
			//��
			nx=cx,ny=cy;
			while(true){
				ny++;
				if(new_board[nx][ny]=='O'||ny>=n) break;
				if(new_board[nx][ny]!='T') new_board[nx][ny]='X';
			}
			//��
			nx=cx,ny=cy;
			while(true){
				nx--;
				if(new_board[nx][ny]=='O'||nx<0) break;
				if(new_board[nx][ny]!='T') new_board[nx][ny]='X';
			} 
		}
		ans=check(n);
		if(ans) break;
	}while(next_permutation(v.begin(),v.end()));
	
	ans?cout<<"YES":cout<<"NO";
}
