#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
/*
	BOJ 14889 ��ŸƮ�� ��ũ - ���� ���� ����.
	
	* ó���� ������ȣ�� ��� �־ ���� ���� -> �ð��ʰ� �߻�. 
	* �� ��ȣ���� ������ �����ϴ��� ���θ� �������� ���� -> �ð��ʰ� ������.
	
	next_permutation ����ϱ� ����, ������ ����Ǽ��� ���� ����ϱ�
	
	��������
	
	1. ���(?)�� ���Կ��θ� ��Ÿ�� v ���� �ʱ�ȭ
	2. next_permutation�� ���� �� ����, ���� �Ǵ� ��� �ֿ����� �ɷ�ġ �ձ���
	3. �ּ��� �ɷ�ġ ���. 
*/
int main(){
	fastio;
	int n;cin>>n;
	int arr[n+1][n+1]={0,};
	vector<int> v;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>arr[i][j];
	for(int i=0;i<n/2;i++){
		v.push_back(0);
		v.push_back(1);
	}
	
	int minn=1e9;
	do{
		int start=0,link=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(v[i]+v[j]==2) start+=arr[i][j];
				else if(v[i]+v[j]==0) link+=arr[i][j];
			}
		}
		minn=min(abs(start-link),minn);
	}while(next_permutation(v.begin(),v.end()));
	
	cout<<minn;
} 
