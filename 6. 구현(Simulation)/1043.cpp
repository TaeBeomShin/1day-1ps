#include<bits/stdc++.h>
using namespace std;
/*
	union & find..?
	 
	check[i] �������� ���.
	check_party[i] �������� ����� �ִ� ��Ƽ. 
*/

int n,m,know,root[51];
bool check[51];

int find(int a){
	if(root[a]==a) return a;
	return root[a]=find(root[a]);
}

void merge(int a,int b){
	a=find(a);b=find(b);
	
	//�� ū ��尡 ��Ʈ�� �ǵ��� ��.
	if(a>b) swap(a,b); 
	root[b]=a;
	check[a] |=check[b];
}

int main(){
	cin>>n>>m;
	
	cin>>know;
	for(int i=0;i<know;i++){
		int num;cin>>num;
		check[num]=true;
	}
	
	vector<int> party[50];	
	for(int i=0;i<m;i++){
		int num;cin>>num;
		for(int j=0;j<num;j++){
			int p;cin>>p;
			party[i].push_back(p);
		}
	}
	
	for(int i=1;i<=n;i++) root[i]=i;
	for(int i=0;i<m;i++){
		if(party[i].size()<=1) continue;
		for(int j=1;j<party[i].size();j++) merge(party[i][0],party[i][j]);
	}
	
	int ans=0;
	for(int i=0;i<m;i++){
		bool flag=true;
		for(int j=0;j<party[i].size();j++){
			if(check[find(party[i][j])]) flag=false;
		}
		if(flag) ans++;
	}
	cout<<ans;
}
