#include<bits/stdc++.h>
#define P pair<int,int>
using namespace std;
/*
	BOJ 1966 - ������ť.
	
	��Ǯ��. Prioirty queue �� Queue�� ������ Ȱ���Ͽ� ����.
	�ٸ� ��� Ǯ��. �� ���͸� �����ؼ� �Ѻ��͸� ������ �� for���� ������ Ȱ���Ͽ� ����. 
	
	�Ƹ� ���� �ǵ��� ��Ǯ�̿� ������ ������... 
	 
*/
int main(){
	int t;cin>>t;
	
	while(t--){
		int n,m;cin>>n>>m;
		queue<pair<int,int>> Q;
		priority_queue<int,vector<int>,less<int>> PQ;
		for(int i=0;i<n;i++){
			int num;cin>>num;
			Q.push({num,i});
			PQ.push(num);
		}
		
		int ans=0;
		bool check=false;
		while(true){
			int value=Q.front().first,idx=Q.front().second;
			if(PQ.top()!=value){
			//�� ū���� �����ϴ� ���. ���ٰ� �־���. 
				Q.pop();
				Q.push({value,idx});
			}else{
			//�� ū���� ���� ���. �μ���. 
				Q.pop();PQ.pop();
				ans++;
				if(idx==m)check=true;
			}
			if(check) break;
		}
		cout<<ans<<"\n";
	}
}
