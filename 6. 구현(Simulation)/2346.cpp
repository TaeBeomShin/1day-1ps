#include<bits/stdc++.h>
using namespace std;
/*

	BOJ 2346 ǳ�� ��Ʈ���� 
	- �似Ǫ�� ������ ����, NHN ���� �߿��� ���ǵ����� �־��µ� �װ͵� �̷� �����̿��� �ɷ� �����(�� �����ϱ�����)
	- ���� : ���Ϳ��� �ε����� ��ⷯ ó���� vector �ڷ����� ���� ����(erase �޼ҵ� �̿�) 
	- �׸��鼭 �ϸ� ���򰥸�. �Ӹ��θ� Ǫ�����ϸ� �Ǽ������ϴ� ����. 
	
*/
int main(){
	int N;cin>>N;
	vector<pair<int,int>> v(N);
	vector<int> ans;
	
	for(int i=0;i<N;i++){
		int num;cin>>num;
		v[i]={i+1,num};
		
	}
	
	int idx=0,temp=N;
	
	for(int i=0;i<temp;i++){
		cout<<v[idx].first<<" ";
		int move=v[idx].second;
		if(move>0) move--;
		v.erase(v.begin()+idx);
		idx+=move;
		if(--N==0) break;
		
		idx=(idx>=0)?idx:N+idx%N;
		idx%=N;
	}
	
}
