#include<iostream>

using namespace std;

int coin[11];
int main(){
	int n,k;
	cin>>n>>k;
	//그리디 알고리즘.
	//K보다 작은 수 중 가장 큰 값을 갖는 동전을 포함시킨다(k에서 그 수 만큼 뺀다& 반복)
	for(int i=1;i<=n;i++){
		cin>>coin[i];
	}
	
	int count=0;
	while(k!=0){
		for(int i=1;i<=n;i++){
			if(k<coin[i]){
				count+=k/coin[i-1];
				k=k%coin[i-1];
				break;
			}else if(i==n){
				count+=k/coin[i];
				k=k%coin[i];
			}
		}
	}
	
	cout<<count;
	
	return 0;
}
