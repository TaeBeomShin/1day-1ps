#include<bits/stdc++.h>
using namespace std;

int n,m,k;
int dx[8]={-1,-1,0,1,1,1,0,-1},dy[8]={0,1,1,1,0,-1,-1,-1};

char board[10][10];
typedef struct{
	int x;
	int y;
	char curc;
	string curs;
}info;

int main(){
	cin>>n>>m>>k;
	
	for(int i=0;i<n;i++) cin>>board[i];
	
	for(int i=0;i<k;i++){
		string ans;cin>>ans;
		
		int anssize=ans.length();
		int cnt=0;
		queue<info> Q;
		//첫문자 삽입.
		info temp;
		temp.x=0;temp.y=0;temp.curc=board[0][0];temp.curs=board[0][0];
		Q.push(temp);
		
		while(!Q.empty()){
			auto cur=Q.front();Q.pop();
			int cx=cur.x,cy=cur.y;
			char curalpha=cur.curc;
			string curstr=cur.curs;
			
			if(curstr.length()==anssize){
				if(curstr==ans) cnt++;
				continue;
			}
			
			for(int dir=0;dir<8;dir++){
				int nx=cx+dx[dir],ny=cy+dy[dir];
				
				if(nx<0) nx=n-1;
				if(nx>=n) nx=0;
				if(ny<0) ny=n-1;
				if(ny>=m) ny=0;
				
				info temp2;
				string cstr=curstr+board[nx][ny];
				temp2.x=nx;temp2.y=ny;temp2.curc=board[nx][ny];
				temp2.curs=cstr;
				Q.push(temp2);
			}
		}
		cout<<cnt<<"\n";
	}
}
