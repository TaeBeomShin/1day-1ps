#include<bits/stdc++.h>
using namespace std;
/*
	�����ȹ�� �������� �Ǻ�. -> ���� ���ð� root�ν� �����ϴ°�?
	
	�׷��� ������ �Ұ����� �����ȹ(�̾��� ���� �����Ƿ�) 
*/

int num[201]={0,};

int find(int n){
	// ������ ��Ʈ���. 
	if(n==num[n]) return n;
	// ������ ��Ʈ��尡 �ƴ�. 
	else return num[n]=find(num[n]);
}

void u(int a,int b){
	int aroot=find(a);
	int broot=find(b);
	num[aroot]=broot;
}
int main(){
	int n;cin>>n;
	int m;cin>>m;
	
	for(int i=0;i<=n;i++) num[i]=i;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int connect;cin>>connect;
			if(connect==1) u(i,j);
		}
	}
	
	int city;cin>>city;
	int start=find(city);
	bool check=true;
	for(int i=1;i<m;i++){
		cin>>city;
		if(start!=find(city)) check=false; 
	}
	(check)?cout<<"YES":cout<<"NO";
}
