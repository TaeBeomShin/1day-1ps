#include<iostream>
using namespace std;
int dice[7]={0,};
int main(){
	
	for(int i=0;i<=2;i++){
		int temp; cin>>temp;
		dice[temp]++;		
	}
	int value=0;
	int max=0;
	for(int i=1;i<=6;i++){
//		cout<<dice[i]<<"\n";
		if(dice[i]==3){
			value=10000+i*1000;
			break;
		}
		if(dice[i]==2){
			value=1000+i*100;
			break;
		}
		else if(dice[i]==1&&i>max){
			value=100*i;
			max=i;
		}
	}
	cout<<value;
	
	return 0;
}
