#include<iostream>

using namespace std;

int num[1000001];
int find(int n){
	if(n==num[n])//루트 노드이면 인덱스와 루트가 일치함. 
		return n;
	else
		return num[n]=find(num[n]);//경로 압축안해주면 O(1)이 아니라 O(n)번 연산. 
}

void u(int a,int b){
	int aroot=find(a);
	int broot=find(b);
	num[aroot]=broot;
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	int n,m;
	cin>>n>>m;
	for(int i=0;i<=n;i++) num[i]=i;//각 노드를 초기화 시켜준다. 
	
	for(int i=0;i<m;i++){
		int t,a,b;
		cin>>t>>a>>b;
		if(t==0){
			u(a,b);
		}
		else{
			if(find(a)==find(b)) cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
	
	return 0;
} 
