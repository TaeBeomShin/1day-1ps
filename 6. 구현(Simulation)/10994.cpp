#include<iostream>
using namespace std;

char starMap[401][401];
void star(int y,int x,int depth){
	if(depth==1){
		starMap[y][x]='*';
		return;
	}
	for(int i=0;i<4*(depth-1)+1;i++){
		if(i==0||i==4*(depth-1))
		{
			for(int j=0;j<4*(depth-1)+1;j++)
			{
				starMap[y+i][x+j]='*';
			}
			continue;
		}
		starMap[y+i][x]='*';
		starMap[y+i][x+4*(depth-1)]='*';
	}
	star(y+2,x+2,depth-1);
	return ;
}

int main(){
	int N;cin>>N;
	star(0,0,N);
	for(int i=0;i<4*(N-1)+1;i++){
		for(int j=0;j<4*(N-1)+1;j++)
		{
			char c=(starMap[i][j]=='*')?'*':' ';
			cout<<c;
		}
		cout<<"\n";
	}
}
