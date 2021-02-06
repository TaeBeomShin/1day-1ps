#include<bits/stdc++.h>
using namespace std;

int x[3],y[3];

int ccw(int a,int b,int c){
	int aa[2]={y[b]-y[a],x[b]-x[a]};
	int bb[2]={y[c]-y[a],x[c]-x[a]};
	int result={aa[0]*bb[1]-aa[1]*bb[0]};
	if(result<0) return 1;
	else if (result>0) return -1;
	else return 0;
}
int main(){
	for(int i=0;i<3;i++) cin>>x[i]>>y[i];
	cout<<ccw(0,1,2);
	return 0;
	
}
