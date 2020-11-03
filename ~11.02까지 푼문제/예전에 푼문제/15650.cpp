#include<iostream>

using namespace std;

int m,n;
bool check[10];
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
			if(check[i]) continue;
			else{
					check[i]=true;
					list[count]=i;
					go(i,count+1);
					check[i]=false;
				}
			}
		}
	}

int main(){
	cin>>n>>m;
	
	go(1,0);
	
	return 0;
}
