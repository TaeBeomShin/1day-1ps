#include<bits/stdc++.h>
using namespace std;


int main(){
	int n,m;cin>>n>>m;
	
	deque <int> dq;

	for(int i=1;i<=n;i++) dq.push_back(i);
	
	int count=0;
	for(int i=0;i<m;i++){
		int num;
		cin>>num;
		int index;
		for(int i=0;i<dq.size();i++){
			if(dq[i]==num){//dq�� �ε����� ���� ȣ���̰����ϴ�. 
				index=i;
				break;
			}
		}
		
		if(dq.size()-index>index){//������ �κ��� �� ���
			for (;;) {
	                if (dq.front() == num) {
	                    dq.pop_front();
	                    break;
					}
			count++;//2�������� �����Ѵ�.
			dq.push_back(dq.front());
			dq.pop_front();
			}
		}
		else{//���� �κ��� �� ���. 
			for (;;) {
	                if (dq.front() == num) {
	                    dq.pop_front();
	                    break;
	                }
			count++;//2�������� �����Ѵ�.
			dq.push_front(dq.back());
			dq.pop_back();
			}
		}
	}
	cout<<count;
} 
