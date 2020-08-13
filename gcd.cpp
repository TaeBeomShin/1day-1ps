#include<iostream>
using namespace std;


//gcd(a,b)->gcd(b,r), r=a%b;
int gcd(int a,int b){
	while(b!=0){
		int r=a%b;
		a=b;
		b=r;
	}
	return a;
}

int A[1000001]={0,};
int gcdLR[1000001]={1,};
int gcdRL[1000001]={1,};
int main(){
	int N;
	cin>>N;
	for(int i=1;i<=N;i++) cin>>A[i];
	
	gcdLR[1]=gcd(A[1],A[1]);gcdRL[N]=gcd(A[N],A[N]);
	
	for(int i=2;i<=N;i++){
		gcdLR[i]=gcd(A[i],gcdLR[i-1]);
		gcdRL[N-i+1]=gcd(A[N-i+1],gcdRL[N-i+2]);

	}
	
//	for(int i=1;i<=N;i++){
//		cout<<gcdLR[i]<<" "<<gcdRL[i]<<"\n";
//	}

	int max=0,maxnum=0;
	
	for(int i=1;i<=N;i++){
		int temp=0;
		if(i==1){
			temp=gcdRL[2];
		}
		else if(i==N){
			temp=gcdLR[N-1];
		}
		else{
			temp=gcd(gcdLR[i-1],gcdRL[i+1]);
		}
		
		if(temp>max){
			if(A[i]%temp!=0){
				max=temp;maxnum=A[i];
			}
		}
	}
	if(max==0){
		cout<<"-1";
	}else{
		cout<<max<<" "<<maxnum;
	}
	return 0;
}
