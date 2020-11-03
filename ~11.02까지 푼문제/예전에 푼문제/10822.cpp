#include<bits/stdc++.h>
using namespace std;
int main(){
	string numbers;cin>>numbers;
	char* tok=strtok(numbers,",");
	int sum=0;
	while(tok!=NULL){
		sum+=tok-'0';
		tok=strok(NULL",");
	}
	cout<<sum;
}
