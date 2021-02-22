#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n,m;cin>>n>>m;
		//바뀌는 횟수 : 각수보다 작은 수가 오른쪽에 몇개나 있는가?
		//이 성질을 이용해서 dfs와 유사하게 실행. 
		bool visited[n+1]={false,};
		for(int i=n-1;i>=0;i--){
			if(m>=i){
				m-=i;
				cout<<i+1<<" ";
				visited[i+1]=true;
			}
		}
		for(int i=1;i<=n;i++){
			if(!visited[i]) cout<<i<<" ";
		}
		cout<<"\n";
	}
}
