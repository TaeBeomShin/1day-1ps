#include<iostream>

using namespace std;

int sosu[1001];
int main(){
	int n,k;
	cin>>n>>k;
	
	for(int i=2;i<=n;i++) sosu[i]=i;
	
	int count=0;
	for(int i=2;i<=n;i++){
		if(sosu[i]==0) continue;
		for(int j=i;j<=n;j+=i){
			if(sosu[j]==0) continue;
			sosu[j]=0;
			count++;
			if(count==k){
				cout<<j;
			}
		}
	}
	
	return 0;
}
