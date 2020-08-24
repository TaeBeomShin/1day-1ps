#include<iostream>

using namespace std;

bool sosu[1000001]={1,1};

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	
	for(int i=2;i*i<=1000000;i++){//100만의 루트까지
		for(int j=2*i;j<1000000;j+=i){
			sosu[j]=true;//원소가 0이면 소수가 아니다. 
		}
	}
	while(cin>>n&&n!=0){
//골드바흐의 추측
//두 소수의 합으로 숫자 나타내기(어자피 2가아닌 소수는 모두 홀수임, 1은 소수아님.)
//작은 소수부터 하나씩 빼고, 남은 값이 소수이지 판정한다.
//1. 1000000 까지의 수들에 대해 소수여부를 판정하는 배열을 생성하자.
//2. sosu[j]=false인 것들을 순회하면서 주어진 값에서 빼고 sosu인지 확인하고 맞으면 저장
		int num1=0,num2=0;
		for(int i=3;i<n;i++){
			if(!sosu[i]&&!sosu[n-i]){//둘다 소수아니면. 
				num1=i,num2=n-i;
				break;
			}
		}
		if(num1+num2==n){
			cout<<n<<" = "<<num1<<" + "<<num2<<"\n";
		}
		else{
			cout<<"Goldbach's conjecture is wrong.\n";
		}
 
	}

//	for(int i=1;i<100;i++){
//		cout<<i<<" "<<sosu[i]<<"\n";
//	}
	return 0;
}
