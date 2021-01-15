#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int main(){
	fastio;
	stack<pair<int,int> >S;
	int n;cin>>n;
	int x,y;
	for(int i=0;i<n;i++){
		int nx,ny;cin>>nx>>ny;
		if(i==0){//첫번째 수 일 때 
			x=nx,y=ny;
			continue;
		}else{//두번째 수 부터. 
			//nx<=y, x는 그대로 y=max(y,ny)
			if(nx<=y){
				y=max(y,ny);
			}else{
			//nx>y, 기존 x,y는 스택에 넣음 & x=nx,y=ny
				S.push({x,y});
				x=nx;y=ny;
			}
		}
		if(i==n-1){
			S.push({x,y});
		}
	} 
	int sum=0;
	while(!S.empty()){
		sum+=(S.top().second-S.top().first);
		S.pop();
	}
	if(n==1) sum=y-x;
	cout<<sum;
}
