#include<bits/stdc++.h>
using namespace std;

bool cmp(const pair<string,int>&a, const pair<string,int>&b){
	return a.second<b.second;
}
int main(){
	int k,l;cin>>k>>l;
	/*
		1. �ߺ��Ǵ� ��� ����(�տ� Ŭ���� �� ����.)-> map�ڷ��� �̿�. 
		2. �Ǿտ������� k�� ����. 
	*/
	map<string,int> m; 
	for(int i=0;i<l;i++){
		string num;cin>>num;
		m[num]=i;
	}
	
	vector<pair<string,int> > v(m.begin(),m.end());
	sort(v.begin(),v.end(),cmp);
	
	k=min(k,int(v.size()));
	for(int i=0;i<k;i++)
		cout<<v[i].first<<"\n";
	
}
