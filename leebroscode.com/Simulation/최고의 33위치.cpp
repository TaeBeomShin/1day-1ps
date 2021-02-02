#include<bits/stdc++.h>
using namespace std;

int dx[8]={1,2,0,1,2,0,1,2},dy[8]={0,0,1,1,1,2,2,2};
int main(){
	int n;cin>>n;
	int arr[n][n];
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	
	int ans=0;
	for(int i=0;i<n-2;i++){
		for(int j=0;j<n-2;j++){
			int cx=i,cy=j;
			int count=0;
			if(arr[cx][cy]==1) count++;
			for(int dir=0;dir<9;dir++){
				int nx=cx+dx[dir],ny=cy+dy[dir];
				if(nx<0||nx>=n||ny<0||ny>=n) continue;
				if(arr[nx][ny]==1) count++;
			}
			ans=max(count,ans);
		}
	}
	cout<<ans; 
	
}
