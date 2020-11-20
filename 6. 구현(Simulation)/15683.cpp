#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

int arr[8][8],arr2[8][8],n,m;
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
vector<pair <int,int> > cctv;

int cnt_0,cnt_7;

void update(int x,int y,int d){
	d%=4;
	while(1){
		x+=dx[d];y+=dy[d];
		if(!(0<=x&&x<n&&0<=y&&y<m)||arr2[x][y]==6) return;
		if(arr2[x][y]==0){
			arr2[x][y]=7;cnt_7++;
		}
	}
}

int main(){
	fastio;
	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
			if(arr[i][j]!=0 && arr[i][j]!=6) cctv.push_back({i,j});
			else if(arr[i][j]==0) cnt_0++;
		}
	}
	
	int ans=int(2e9);
	
	for(int c=0;c<(1<<2*cctv.size());c++){
		cnt_7=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				arr2[i][j]=arr[i][j];
			}
		}
		
		int temp=c;
		
		for(int i=0;i<cctv.size();i++){
			int d=temp%4;temp/=4;
			int x=cctv[i].first,y=cctv[i].second,t=arr2[x][y];
			if(t==2&&d/2) continue;
			if(t==5&&d!=0) continue;
			if(t==1) update(x,y,d);
			else if(t==2){
				update(x,y,d);update(x,y,d+2);
			}else if(t==3){
				update(x,y,d);update(x,y,d+1);
			}else if(t==4){
				update(x,y,d);update(x,y,d+1);update(x,y,d+2);
			}else{
				update(x,y,d);update(x,y,d+1);update(x,y,d+2);update(x,y,d+3);
			}
		}
		ans=min(ans,cnt_0-cnt_7);
	}
	cout<<ans;
}
