#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	
	int N,M;
	cin>>N;
	int A[N+1]={0,};
	for(int i=0;i<N;i++) cin>>A[i];
	
	sort(A,A+N);
	
	cin>>M;
	int temp;
	for(int i=0;i<M;i++){
		cin>>temp;
		if(binary_search(A,A+N,temp)) cout<<"1"<<" ";
		else cout<<"0"<<" ";
	}
	
	return 0;
}
