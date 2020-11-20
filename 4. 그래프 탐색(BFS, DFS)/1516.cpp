#include<bits/stdc++.h>
using namespace std;

int main(){
	//�ʿ��� ���� �������, indegree ������ �迭, ���� ������ �迭. 
	int n;cin>>n;
	int time[500],result[500]={0};
	int indegree[500]={0};
	vector<int> adj[500];
	queue<int> Q;
	
	for(int i=0;i<n;i++){
		cin>>time[i];//���Ҹ� �Է¹޽��ϴ�.(i��ȣ �ǹ��� �������µ� �ɸ��½ð�) 
		while(true){
			int pre;
			cin>>pre;//i�ǹ��� �������� ���� ������ϴ� �ǹ�. 
			if(pre==-1) break;//-1�� ������ ����. 
			indegree[i]++;//indegree�� �ø�. 
			adj[pre-1].push_back(i);//������Ŀ� i�� ����ֽ��ϴ�. 
		}
		if(indegree[i]==0){//indegree�� 0�̸� 
			result[i]=time[i];//����� time[i[�� ����. 
			Q.push(i);//Q�� i�� �������. 
		}
	}
	for(int i=0;i<n;i++){
		int cur=Q.front();
		Q.pop();
		for(int next:adj[cur]){
			result[next]=max(result[next],result[cur]+time[next]);
			if(--indegree[next]==0) Q.push(next);
		}
	}
	
	for(int i=0;i<n;i++)
		cout<<result[i]<<"\n";
} 
