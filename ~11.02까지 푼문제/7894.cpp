#include<bits/stdc++.h>
using namespace std;
//����б� ���нð��� ����� �� ����..
// log(i!)�� �ڸ��� =log(i) - - - +log(1) ���� �� why? �αװ� �ڸ����� ��Ÿ���ϱ�.. 
int main(){
	int t;cin>>t;
	while(t--){
		int m;cin>>m;
		double sum=0;
		for(int i=1;i<=m;i++){
			sum+=log10(i);
		}
		cout<<int(sum+1)<<"\n";
	}
}
