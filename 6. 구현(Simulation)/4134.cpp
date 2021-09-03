#include<iostream>
#include<cmath>
typedef long long int ll;
using namespace std;

/**
* n보다 크거나 같은 소수 중 가장 작은 소수 
* n의 범위 40억 -> long long
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
