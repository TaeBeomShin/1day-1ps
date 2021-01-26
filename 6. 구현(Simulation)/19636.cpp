#include<bits/stdc++.h>

using namespace std;

int main(){
	int weight,energy1,consume,T;
	int day,energy2,activity;
	cin>>weight>>energy1>>T;
	cin>>day>>energy2>>activity;
	
	int weight1=weight;//기초대사량 변화X 
	int weight2=weight;
	consume=energy1;
	while(day--){//D일 동안 다이어트를 한다, 기초 대사량 변화X 
		weight1+=(energy2-(energy1+activity));//체중 : 섭취량 - 소비량.
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
