#include<bits/stdc++.h>
using namespace std;

int n,ans,dur[8],w[8];

void solve(int count){
	if(count >=n){ 
		int sum=0;
		for(int i=0;i<n;i++)
			if(dur[i]<=0) sum++;
		if(ans<sum) ans=sum;
		return;
	}
	if(dur[count]<=0) solve(count+1); 
	else{ 
		bool check=false; 
		for(int i=0;i<n;i++){
			if(count==i||dur[i]<=0) continue; 
			dur[count]-=w[i];
			dur[i]-=w[count];
			check=true;//방문했다. 
			solve(count+1);//다음 계란으로 넘어간다. 
			dur[count]+=w[i];//전체탐색을 위해 원래대로 내구도를 돌린다. 
			dur[i]+=w[count];
		}
		if(!check) solve(n);
	}
}
int main(){
	cin>>n;//n은 8보다 작음.

	for(int i=0;i<n;i++) cin>>dur[i]>>w[i];
	
	solve(0);//젤왼쪽 계란부터 시작. 
	cout<<ans;
}
