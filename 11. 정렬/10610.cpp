#include<bits/stdc++.h>
using namespace std;

int main(){
	string num;cin>>num; 
	/*
		BOJ 10610 30 (���� ����) 
		105���� ���ڷ� ����
		���ڵ��� ���� 30�� ����� �Ǵ� ���� ū ��.
		
		3�� ����̸鼭 10�� ���.
		-��� ������, 3�ǹ�� : ���ڸ� ������ ���� 3�� ���
		10�� ��� ���� �ڸ��� 0�μ�
		
		������ �����ϸ� ���� ������������ ���. 
	*/
	
	int sum=0;
	bool check=false;
	vector<int> v;
	for(int i=0;i<num.length();i++){
		int n=num[i]-'0';
		v.push_back(n);
		sum+=n;
		if(n==0) check=true;
	}
	sort(v.begin(),v.end(),greater<int>());
	if(check&&sum%3==0){
		for(int i=0;i<v.size();i++) cout<<v[i];
	}else{
		cout<<-1;
	}
}
