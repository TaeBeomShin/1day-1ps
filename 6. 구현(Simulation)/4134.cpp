#include<iostream>
#include<cmath>
typedef long long int ll;
using namespace std;

/**
* n���� ũ�ų� ���� �Ҽ� �� ���� ���� �Ҽ� 
* n�� ���� 40�� -> long long
*/

bool isPrime(ll targetNum);

int main(){
	int caseNum;cin>>caseNum;
	while(caseNum--){
		ll num;cin>>num;
		ll upperMinNum;
		for(ll i=num;;i++){
			if(isPrime(i)){
				upperMinNum=i;
				break;
			}
		}
		cout<<upperMinNum<<"\n";
	} 
}

bool isPrime(ll targetNum){
	bool isPrimeNum=true;
	int maxRange=sqrt(targetNum);
	
	if(targetNum==0||targetNum==1){
		isPrimeNum=false;
	}
	else{
		for(int i=2;i<=maxRange;i++){
			if(targetNum%i==0){
				isPrimeNum=false;
				break;
			}
		}	
	}
	
	return isPrimeNum;
}
