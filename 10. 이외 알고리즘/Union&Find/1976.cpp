#include<bits/stdc++.h>
using namespace std;
/*
	여행계획이 가능한지 판별. -> 같은 도시가 root로써 존재하는가?
	
	그렇지 않으면 불가능한 여행계획(이어져 있지 않으므로) 
*/

int num[201]={0,};

int find(int n){
	// 본인이 루트노드. 
	if(n==num[n]) return n;
	// 본인이 루트노드가 아님. 
	else return num[n]=find(num[n]);
}

void u(int a,int b){
	int aroot=find(a);
	int broot=find(b);
	num[aroot]=broot;
}
int main(){
	int n;cin>>n;
	int m;cin>>m;
	
	for(int i=0;i<=n;i++) num[i]=i;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int connect;cin>>connect;
			if(connect==1) u(i,j);
		}
	}
	
	int city;cin>>city;
	int start=find(city);
	bool check=true;
	for(int i=1;i<m;i++){
		cin>>city;
		if(start!=find(city)) check=false; 
	}
	(check)?cout<<"YES":cout<<"NO";
}
