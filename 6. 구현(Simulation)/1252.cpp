#include<bits/stdc++.h>
using namespace std;
const int maxn=81;//이진수의 길이. 

int main(){
	bitset<maxn> x,y,ans;//길이가 81인 비트셋을 선언한다. 
	cin>>x>>y;
	bool d=0;int l=0;
	for(int i=0;i<maxn;i++){
		ans[i]=x[i]^y[i]^d;
		d=x[i]+y[i]+d>1;
		if(ans[i]) l=i;
	}
	while(l+1) cout<<ans[l--];
}
