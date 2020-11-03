#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int N;
	cin>>N;
	
	int num[N];
	
	for(int i=0;i<N;i++) cin>>num[i];
	sort(num,num+N);
	
	int result =num[0]*num[N-1];
	
	cout<<result;
	
	return 0;
}
