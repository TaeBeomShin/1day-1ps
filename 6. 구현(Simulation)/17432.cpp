#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n,m;cin>>n>>m;
		//�ٲ�� Ƚ�� : �������� ���� ���� �����ʿ� ��� �ִ°�?
		//�� ������ �̿��ؼ� dfs�� �����ϰ� ����. 
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
