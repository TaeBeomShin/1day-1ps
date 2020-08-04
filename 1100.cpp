#include<iostream>

using namespace std;

int main(){
	int count =0;
	
	char temp;
	for(int i=0;i<64;++i){
		cin>>temp;
		if((i/8)%2==0&i%2==0&temp=='F'){
			count++;
		}
		if((i/8)%2==1&i%2==1&temp=='F'){
			count++;
		}
	}
	cout<<count;
	return 0;
}
