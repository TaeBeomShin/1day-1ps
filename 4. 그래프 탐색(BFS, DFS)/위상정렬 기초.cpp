#include<bits/stdc++.h>
using namespace std;

int main(){//��������, DAG ������ �׷������� �������� ����. 
	int n,m,indegree[1000]={0};
	vector<int> adj[1000];
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int k,prev,curr;
		cin>>k;
		if(k==0) continue;
		
		cin>>prev;
		for(int i=1;i<k;i++){
			cin>>curr;
			indegree[curr-1]++;
			adj[prev-1].push_back(curr-1);
			prev=curr;
		}
	}
	int result[1000];
	queue<int> Q;
	for(int i=0;i<n;i++)//indegree�� 0�� ������ ť�� ��� �ִ´�. 
		if(indegree[i]==0) Q.push(i);
	
	for(int i=0;i<n;i++){//������ ������ŭ �ൿ�� �ݵ�. 
		if(Q.empty()){
			puts.("0");
			return 0;
		}
		int curr=Q.front();
		Q.pop();//ť�� front ���Ҹ� ���� �� �������� ������ ������ ��λ���. 
		result[i]=curr+1;//ť���� ���� ���� ������ �������� ���. 
		for(int nex:adj[curr])
			if(--indegree[next]==0) Q.push(next);//indegree�� 0�� ���� ����� Q�� ����. 
	}
	
	for(int i=0;i<n;i++)
		cout<<result[i]<<"\n";
} 
