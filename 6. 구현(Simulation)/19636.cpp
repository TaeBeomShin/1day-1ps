#include<bits/stdc++.h>

using namespace std;

int main(){
	int weight,energy1,consume,T;
	int day,energy2,activity;
	cin>>weight>>energy1>>T;
	cin>>day>>energy2>>activity;
	
	int weight1=weight;//���ʴ�緮 ��ȭX 
	int weight2=weight;
	consume=energy1;
	while(day--){//D�� ���� ���̾�Ʈ�� �Ѵ�, ���� ��緮 ��ȭX 
		weight1+=(energy2-(energy1+activity));//ü�� : ���뷮 - �Һ�.
		weight2+=(energy2-(consume+activity));
		
		if(abs(energy2-(consume+activity))>T) consume+=(energy2-(consume+activity))/2;
	}
	
	if(weight1>0&&energy1>0)
		cout<<weight1<<" "<<energy1<<"\n";
	else
		cout<<"Danger Diet"<<"\n";
		
	if(weight2>0&&consume>0){
		cout<<weight2<<" "<<consume<<" ";
		if(consume<energy1) cout<<"YOYO";
		else cout<<"NO";
	}
	else
		cout<<"Danger Diet";
	
}
