#include<iostream>

using namespace std;

int m,n;
int list[10];

void go(int index, int count){
	if(count==m){
		for(int i=0;i<m;i++){
			cout<<list[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	else{
		for(int i=index;i<=n;i++){
			list[count]=i;
			go(i,count+1); 
		}
	}
}

int main(){
	cin>>n>>m;
	
	go(1,0);
	
	return 0;
}
