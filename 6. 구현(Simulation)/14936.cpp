#include<bits/stdc++.h>
using namespace std;
int n,m,arr[8]={};
int main(){
	cin>>n>>m;
	int odd=(n%2==0)?n/2:n/2+1,case3=(n-1)/3+1,c=0;
	arr[0]=0;arr[1]=n/2;arr[2]=n;arr[3]=odd;arr[4]=case3,arr[5]=case3+n,arr[6]=case3+n/2,arr[7]=case3+odd;
	if(n==1) (m==0)?c=1:c=2;
	else if(n==2) (m==0)?c=1:(m==1)?c=3:c=4;
	else{
		for(int i=0;i<8;i++)if(arr[i]<=m) c++;
	}
	cout<<c;
}
