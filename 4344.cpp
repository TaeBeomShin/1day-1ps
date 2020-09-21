#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int array[n]={0,};
		int sum=0;
		for(int i=0;i<n;i++){
			cin>>array[i];
			sum+=array[i];
		}
		double average=sum/n;
		int count=0;
		for(int i=0;i<n;i++){
			if(array[i]>average) count++;
		}
		double result=double(count)/double(n) *100;
		printf("%.3lf%\n",result);
	}
}
