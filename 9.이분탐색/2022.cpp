#include<bits/stdc++.h>
using namespace std;
/*
	BOJ2022 ��ٸ�Ÿ��
	�̺�Ž�� in �Ǽ� + ������ ���� 
	
	1. ������ �̿��ؼ� c�� �翷�� ���̿� ���� ������ �ٲ�
	2. �Ǽ� ���� ���� ������ ������ �̺�Ž�� ����.  
*/
int main(){
	double x,y,c;cin>>x>>y>>c;
	double l=0,r=min(x,y);
	
	while(abs(r-l)>1e-6){
		double mid=(l+r)/2;
		double lh=sqrt(x*x-mid*mid), rh=sqrt(y*y-mid*mid);
		double new_c=(lh*rh)/(lh+rh);
		if(new_c<=c) r=mid;
		else l=mid;
	}
	printf("%.3lf",r);
}
