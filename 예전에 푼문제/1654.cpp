#include<iostream>
using namespace std;

int k,n;//k:가지고 있는 랜선의 개수, n: 만들고 싶은 랜선의 개수.
int line[10001];

long long binarysearch(long long start,long long end){
	
	while(start<=end){
		long long m=(start+end)/2;
		long v=0;
		
		for(int i=0;i<k;i++) v+=line[i]/m;
		
		if(v>=n) start=m+1;
		else end=m-1;
	
	}
	return end;
} 

int main(){
	cin>>k>>n;
	
	int max=0;
	for(int i=0;i<k;i++){
		cin>>line[i];
		if(line[i]>max) max=line[i];
	}
	
	(n==1)?cout<<max:cout<<binarysearch(1,max);
		
	return 0;
}
