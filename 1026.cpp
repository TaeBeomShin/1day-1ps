#include<iostream>
#include<algorithm>

using namespace std;

bool compare (int a,int b){
	return a>b;
} 
int main(){
	int A[51]={0,};
	int B[51]={0,};
	
	int N;
	cin>>N;
	
	for(int i=1;i<=N;i++) cin>>A[i];
	for(int i=1;i<=N;i++) cin>>B[i];
	//A배열을 재배열하는 순수 경우의 수 50!=> 매우큰값
	//어떤 방법을 통해 재배열할 것인가?
	//B의 가장 큰값에 A의 가장작은 값을 배정하면될듯. 
	//B의 있는수도 재배열할 경우 매우 쉽게 풀수 있을듯 
	
	sort(A+1,A+N+1);
	sort(B+1,B+N+1,compare);
	
	long long s=0;
	for(int i=1;i<=N;i++){
		s+=A[i]*B[i];
	}
	
	cout<<s;
	return 0;
}
