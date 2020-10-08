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
			if(dq[i]==num){//dq는 인덱싱을 통한 호출이가능하다. 
				index=i;
				break;
			}
		}
		
		if(dq.size()-index>index){//오른쪽 부분이 더 길면
			for (;;) {
	                if (dq.front() == num) {
	                    dq.pop_front();
	                    break;
					}
			count++;//2번연산을 수행한다.
			dq.push_back(dq.front());
			dq.pop_front();
			}
		}
		else{//왼쪽 부분이 더 길면. 
			for (;;) {
	                if (dq.front() == num) {
	                    dq.pop_front();
	                    break;
	                }
			count++;//2번연산을 수행한다.
			dq.push_front(dq.back());
			dq.pop_back();
			}
		}
	}
	cout<<count;
} 
