#include<iostream>
using namespace std;

int k,n;//k:������ �ִ� ������ ����, n: ����� ���� ������ ����.
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
