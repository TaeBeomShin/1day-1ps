#include<bits/stdc++.h>

using namespace std;
//��Ʈ��ŷ + ���Թ����� ����
//���Թ����� ���� ������ ���� nCr�� ���ϰ� ���� ����ϴ� ��Ʈ��ŷ ���� �ʿ�. 
int n;
long long m,sum,d;
vector<int> v,picked;

void go(int start, int remain){
	if(remain==0){
		d=1;
		for(int i=0;i<picked.size();i++){
			d*=v[picked[i]];	
		} 
		if(picked.size()%2) sum+=m/d;
		else sum-=m/d;
		return;
	}
	for(int i=start+1;i<n;i++){
		picked.push_back(i);
		go(i,remain-1);
		picked.pop_back();
	}
}
int main(){
	cin>>n>>m;
	int a=n;
	while(a--){
		int temp;cin>>temp;
		v.push_back(temp);
	}
	
	//���Թ����� ������ �̿�.
	//n�� ������ ���� �޶���.
	sum=0;
	for(int i=1;i<=n;i++){//���� �Ҽ��� ����.
	//i=1, ������ A,B, ... i=2, ������ A&B,B&C,A&C,...�� ��. �����ϰ� ����. 
		go(-1,i);
	}
	cout<<sum;
	
	return 0;	
}
