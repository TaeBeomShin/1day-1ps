#include<iostream>
#include<math.h>

using namespace std;

long long GCD(long long a,long long b){
	
	if(a%b==0) return b;
	
	return GCD(b,a%b);
}
int main(){
	
	long long A,B;

	cin>>A>>B;
	long long result=GCD(A,B);
	
	for(int i=0;i<result;++i){
		cout<<1;
	}

	return 0;
}
