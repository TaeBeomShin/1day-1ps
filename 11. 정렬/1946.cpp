#include<bits/stdc++.h>
using namespace std;
/*
	BOJ1946 - ���Ի��
	
	pair�� ���� + �ణ�� ����.
	�Է¹��� ������ ���������� �������� �������� ����.
	�����ڵ��� ���ʷ� ���ϸ� �ְ� ���������� ����.
	
	���� �����ϴ� ������ ��� �߰�. 
*/
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		vector<pair<int,int>> v(n);
		for(int i=0;i<n;i++) cin>>v[i].first>>v[i].second;
		sort(v.begin(),v.end());
		
		int minb=v[0].second;
		int count=1;
		for(int i=1;i<v.size();i++){
			if(v[i].second<minb) count++;
			minb=min(minb,v[i].second);
		}
		cout<<count<<"\n";
	}
}
