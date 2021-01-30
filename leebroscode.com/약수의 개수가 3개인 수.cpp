#include<bits/stdc++.h>
using namespace std;

bool checkDivisor(int num){
	int count=0;
	
	for(int i=1;i<=num;i++){
		if(num%i==0) count++;
	}
	return (count==3)?true:false;
	
}

int main(){
	int start,end;cin>>start>>end;
	
	int ans=0;
	for(int i=start;i<=end;i++){
		if(checkDivisor(i)) ans++;
	}
	cout<<ans;
}
