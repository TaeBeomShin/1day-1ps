//������ ����
//������ ���Կ� ����(���Կ� ������ ������ ��ü�� ����) 
//K���� ���� �� ������ ���Դٸ�, �ִ� �Ѱ��� ����. 
//��ĥ �� �ִ� ������ �ִ밡�� ���ϱ�.
//how? ������ �����غ��� ���.
//������ ������ �������� ����.(1.����, 2����)
//������ ���Ը� ������������. 
//
//������ �������� �����ϰ�,���Ը� �������� �����Ѵ�.
//������濡 ���� ����ִ´�. ���Զ����� ���ִ°� �ִٸ� �ٽ� ����?

//�������� ��� Ȱ���� �� ������? �켱���� ť ����. 
//
//ť���� �ϳ��� ������鼭 ���� ����� ���濡 �ִ´�.
//��� ������ �뷮���� ũ�ٸ� ������. 
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

pair<int,int> jewelry[300000];
priority_queue<int> pq;

int main(){
	int N,K;
//1. ���� �Է¹޴´�. 
	cin>>N>>K;
	int bag[K];
	int m,v;
	for(int i=0;i<N;i++){
		cin>>jewelry[i].first>>jewelry[i].second;	
}
	for(int i=0;i<K;i++){
		cin>>bag[i];
	}
	
	sort(bag,bag+K);
	sort(jewelry,jewelry+N);
	
	long long result=0;
	int idx=0;
	
	for(int i=0;i<K;i++){
		//�Ϲ����� �׸��� �˰��� �ڵ�. 
		while(idx<N&&jewelry[idx].first<=bag[i]){
		//while�� ��뿡 �ͼ�������. ������ �������� ��Ȳ���� ���� ����. 
		//i��° ���溸�� ������ �������� ��� ������ ����. 
			pq.push(jewelry[idx++].second);
		}
		if(!pq.empty()){
		//�켱���� ť�� �ִ������� �����߱⶧����, ���������� �� ���̽��� �ִ� ������������ �ȴ�. 
			result+=pq.top();
			pq.pop();
		}
	}
	cout<<result<<"\n";

	return 0;
	
}
 
