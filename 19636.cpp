#include<iostream>
#include<math.h>

using namespace std;

int main(){
//	D�ϵ��� ���̾�Ʈ.
//	���̾�Ʈ �� ü��:W, ������ ���뷮:l, ���ʴ�緮 :l Ȱ����緮:A=0
//	���̾�Ʈ �Ⱓ ������ ���뷮: l Ȱ�� ��緮 LA
//	ü�� : ���뷮 - �Һ� g/kcal ��ŭ �پ��. �Һ� : l+ Ȱ�� ��緮(A)
//	
//	���ʴ�緮 ��ȭ abs(������ ���뷮- ������ �Һ�)>T, ���ʴ�緮 l+= (������ ���뷮 - ������ �Һ�) /2
//	
//	���� ���̽�, ü���� 0g�����̰ų�, ���ʴ�緮�� 0kcal �����̸� ����Ѵ�. 
//	
//	output: 1. ���̾�Ʈ�� ���ʴ�緮 ��ȭ ����������� �����ʾ������� ü�߰� ���� ��緮 
//			2. ���� ��Ȱ�� ���ư��� ��������� �Ͼ �� �ΰ�. (���� ��緮�� �پ��°�?)-> YES / NO 
//			3. ���� ���̽��� ��� Danger Diet ���. 
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
		
		cout<<weight1<<" "<<weight2<<" "<<consume<<"\n";
		
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
	
	return 0; 
}
