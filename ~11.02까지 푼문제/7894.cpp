#include<bits/stdc++.h>
using namespace std;
//고등학교 수학시간에 배웠던 것 같음..
// log(i!)의 자리수 =log(i) - - - +log(1) 들의 합 why? 로그가 자릿수를 나타내니까.. 
int main(){
	int t;cin>>t;
	while(t--){
		int m;cin>>m;
		double sum=0;
		for(int i=1;i<=m;i++){
			sum+=log10(i);
		}
		cout<<int(sum+1)<<"\n";
	}
}
