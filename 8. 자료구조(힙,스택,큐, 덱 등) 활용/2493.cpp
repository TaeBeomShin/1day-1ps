#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int main(){
	fastio;
	int n;cin>>n;
	int tower[n+1];
	stack <pair<int,int> > s;
	for(int i=1;i<=n;i++) cin>>tower[i];
	/*
		�ڱ⺸�� ū ž �߿� ���� ������ �ִ� ž�� ��ȣ�� ������(������ ���� ���� �ִ� ��.) 
		���� ���� ������ ���̰� ������ ���̻� ��ȣ�� ���޴´�-> ���ÿ��� �����Ѵ�. 
	*/
	for(int i=1;i<=n;i++){
		bool check=false;//���ʿ� �ڽź��� ū ž�� ã�Ҵ��� üũ. 
		while(!s.empty()){
			if(s.top().second>=tower[i]){
				cout<<s.top().first<<" ";
				s.push({i,tower[i]});
				check=true;
				break;
			}
			else{
				s.pop();
			}
		}
		if(!check){
			s.push({i,tower[i]});
			cout<<0<<" ";
		}
	}
}
