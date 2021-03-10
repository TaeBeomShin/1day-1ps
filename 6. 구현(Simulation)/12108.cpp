#include<bits/stdc++.h>
using namespace std;

int n,s,A[40],threshold,sum;
long long result;
map<long long,int> cnt;
/*
	BOJ 1208 - �κм����� ��
	
	meet in the middle �˰���
	
	������ �ɰ�� ������ �κ�����, �������� �κ������� ���� ����
	�����ش�.
	
	������ �κ� ������ dfs�� ���� map���� �����.
	
	 
*/
void dfs1(int pos){//pos:���� Ž������ �ε���. 
	if(pos==threshold){
		auto iter=cnt.find(sum);
		if(iter!=cnt.end()) ++iter->second;
		else cnt[sum]=1;
		return;
	}
	dfs1(pos+1);
	sum+=A[pos];
	dfs1(pos+1);
	sum-=A[pos];
}

void dfs2(int pos){
	if(pos==n){
		auto iter=cnt.find(s-sum);
		if(iter!=cnt.end()) result +=iter->second;
		return;
	}
	dfs2(pos+1);
	sum+=A[pos];
	dfs2(pos+1);
	sum-=A[pos];
}
int main(){
	//n���� ����, �ִ� c��ŭ ���� �� ����. 
	cin>>n>>s;
	for(int i=0;i<n;i++) cin>>A[i];
	threshold=n/2;
	
	dfs1(0);
	dfs2(threshold);
	
	if(s==0) --result;
	cout<<result;
}
