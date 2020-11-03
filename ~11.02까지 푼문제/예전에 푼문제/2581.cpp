#include<iostream>

using namespace std;

int sosu[10001];
int main(){
	int m,n;
	cin>>m>>n;
	
	for(int i=2;i<=n;i++) sosu[i]=i;
	
	for(int i=2;i<=n;i++){
		if(sosu[i]==0) continue;
		for(int j=2*i;j<=n;j+=i) sosu[j]=0;
	}
	
	int minvalue=n+1;
	int sum=0;
	
	for(int i=m;i<=n;i++){
		if(sosu[i]!=0){
			if(minvalue>sosu[i]) minvalue=sosu[i];
			sum+=sosu[i];
		}
	}
	
	if(sum) cout<<sum<<"\n"<<minvalue;
	else cout<<"-1";
	
	return 0;
}

