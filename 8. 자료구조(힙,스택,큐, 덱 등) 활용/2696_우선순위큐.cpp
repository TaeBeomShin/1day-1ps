#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
 
int main(){
	fastio;
	int t;cin>>t;
	
	while(t--){
		int m;cin>>m;
		//�켱���� ť 2���̿�, �ϳ��� �ִ���// �ϳ��� �ּ���. 
		priority_queue <int,vector<int>> Q1;//�ִ��� 
		priority_queue <int,vector<int>,greater<int>> Q2;//�ּ��� 
		vector<int>ans;
		//�߾Ӱ��� ���� ���. 
		if(m%2==1) cout<<m/2+1;
		else cout<<m/2;
		
		for(int _=1;_<=m;_++){
			int temp; cin>>temp;
			(Q1.size()>Q2.size())?Q2.push(temp):Q1.push(temp);
			if(!Q1.empty()&&!Q2.empty()&&Q1.top()>Q2.top()){//pq1�� �׻� �� �۵��ϸ����.
				int a=Q1.top();Q1.pop();
				int b=Q2.top();Q2.pop();
				Q1.push(b),Q2.push(a);
			}
			if(_&1)ans.push_back(Q1.top());
		}
		for(int i=0;i<ans.size();i++){
			if(i%10==0)cout<<"\n";
			cout<<ans[i]<<" "; 
		}
		cout<<"\n";
	}
}
