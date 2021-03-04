#include<bits/stdc++.h>
using namespace std;
/*
	BOJ1038 �����ϴ¼� - BFS
	
	�����ڸ� �� ���� ���ʴ�� bfs�� �����ϸ鼭 �����ϴ� ������ �����ϴ�
	���� �ִ´�.
	
	�����ϴ� ������ ���� ���͸� �������� ���� ����Ѵ�. 
*/
int main(){
	int n;cin>>n;
	queue<long long> Q;
	
	for(long long i=0;i<10;i++) Q.push(i);
	
	vector<long long> numbers;
	while(!Q.empty()){
		long long cur=Q.front();
		numbers.push_back(cur);
		Q.pop();
		
		for(long long i=0;i<cur%10;i++){
			long long nextnum=cur*10+i;
			Q.push(nextnum);
		}
	}
	sort(numbers.begin(),numbers.end());
	(n<numbers.size())?cout<<numbers[n]:cout<<-1;
}
