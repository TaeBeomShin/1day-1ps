#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n,m,r,board[300][300];

int gcd(int a, int b){
	while(b!=0){
		int r = a%b;
		a= b;
		b= r;
	}
	return a;
}

int lcm(int a, int b){
    return a * b / gcd(a,b);
}

void rotate(int x1,int y1,int x2,int y2){
	int temp=board[x1][y1];
	for(int j=y1;j<y2;j++) board[x1][j]=board[x1][j+1];
	for(int i=x1;i<x2;i++) board[i][y2]=board[i+1][y2];
	for(int j=y2;j>y1;j--) board[x2][j]=board[x2][j-1];
	for(int i=x2;i>x1;i--) board[i][y1]=board[i-1][y1];
	board[x1+1][y1]=temp;
}

void rotate(){
	int x1=0,y1=0,x2=n-1,y2=m-1;
	while(x1<x2&&y1<y2) rotate(x1++,y1++,x2--,y2--);
}

int main(){
	fastio;
	cin>>n>>m>>r;
	for (int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>board[i][j];
	
	int temp,mr=1;
	for(int i=0;;i++){
		temp=2*(m-2*i)+2*(n-2*i)-4;
		if(temp<0) break;
		mr=lcm(mr,temp);
	}
	r=r%mr;
	// 밖에있는건 (2*m+2*n -4) 번하면 1회 회전, 그안의 건 (2*(m-2)+2*(n-2)-4)번 ---) 
	while(r--) rotate();
	for (int i=0;i<n;i++){for(int j=0;j<m;j++)	cout<<board[i][j]<<" ";cout<<"\n";}
}
