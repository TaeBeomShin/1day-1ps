#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	// �ε����� ���� ����. B�� �ε����� ������ P[i]�� ��. 
	
	vector<pair<int,int>> v;
	for(int i=0;i<n;i++){
		int num; cin>>num;
		v.push_back({num,i});
	}
	sort(v.begin(),v.end());
	
	int P[n]={0,};
	for(int i=0;i<n;i++)
		P[v[i].second]=i;
	
	for(int i=0;i<n;i++)
		cout<<P[i]<<" ";
}
