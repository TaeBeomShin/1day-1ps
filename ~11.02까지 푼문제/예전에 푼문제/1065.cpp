#include<iostream>

using namespace std;

int main(){
	int N;
	cin>>N;

	int count=0;
	for(int i=1;i<=N;i++){
		if(i/10<=9){
			count++;
		}
		else if(i/10<=99){
			if(i/100-(i/10)%10==(i/10)%10-i%10){
				count++;
			}
		}
		
	}
	cout<<count;
} 
