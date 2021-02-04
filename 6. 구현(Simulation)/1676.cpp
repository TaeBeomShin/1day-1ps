#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	
	int two=0,five=0;
	for(int i=1;i<=n;i++){
		int num=i;
		while(num%2==0){
			num=num/2;
			two++;
		}
		
		while(num%5==0){
			num=num/5;
			five++;
		}
	}
	cout<<min(two,five);
}
