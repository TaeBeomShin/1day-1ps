#include<iostream>
#include<math.h>

using namespace std;

int main(){
//	D일동안 다이어트.
//	다이어트 전 체중:W, 에너지 섭취량:l, 기초대사량 :l 활동대사량:A=0
//	다이어트 기간 에너지 섭취량: l 활동 대사량 LA
//	체중 : 섭취량 - 소비량 g/kcal 만큼 줄어듬. 소비량 : l+ 활동 대사량(A)
//	
//	기초대사량 변화 abs(에너지 섭취량- 에너지 소비량)>T, 기초대사량 l+= (에너지 섭취량 - 에너지 소비량) /2
//	
//	예외 케이스, 체중이 0g이하이거나, 기초대사량이 0kcal 이하이면 사망한다. 
//	
//	output: 1. 다이어트후 기초대사량 변화 고려했을때와 하지않았을때의 체중과 기초 대사량 
//			2. 원래 생활로 돌아가면 요요현상이 일어날 것 인가. (기초 대사량이 줄었는가?)-> YES / NO 
//			3. 예외 케이스의 경우 Danger Diet 출력. 
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
