#include<iostream>

using namespace std;

bool check[10];
int m,n;
int list[10];
void go(int count){
	if(count==m){
		for(int i=0;i<m;i++){
			cout<<list[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	for(int i=1;i<=n;i++){
		if(check[i]) continue;
		else{
			check[i]=true;
			list[count]=i;
			go(count+1);
			check[i]=false;
		}
	}
	
}

int main(){
	cin>>n>>m;
	
	go(0);
	
	return 0;
}
