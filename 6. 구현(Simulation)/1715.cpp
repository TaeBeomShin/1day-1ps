#include<bits/stdc++.h>
using namespace std;
/*
	���� ���� �� ������ ��ģ��. �̰� �ݺ�. -> �켱���� ť �ڷᱸ���� �̿�. 
*/
int main(){
	int n;cin>>n;
	priority_queue <int,vector<int>,greater<int>> Q;
	long long sum=0;
	for(int i=0;i<n;i++){
		int num;cin>>num;
		Q.push(num);
	}
	if(Q.size()!=1){
		while(true){
			int a=Q.top();Q.pop();
			int b=Q.top();Q.pop();
			int temp=a+b;
			Q.push(temp);
			sum+=temp;
			if(Q.size()==1) break;
		}
	}
	cout<<sum;
}
