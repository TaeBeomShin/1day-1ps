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
		if(i==0){//ù��° �� �� �� 
			x=nx,y=ny;
			continue;
		}else{//�ι�° �� ����. 
			//nx<=y, x�� �״�� y=max(y,ny)
			if(nx<=y){
				y=max(y,ny);
			}else{
			//nx>y, ���� x,y�� ���ÿ� ���� & x=nx,y=ny
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
