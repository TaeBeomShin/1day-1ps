#include<bits/stdc++.h>
using namespace std;

int budget[100001];
int n,m;

int binarysearch(int start, int end){
	while(start<=end){
		int mid=(start+end)/2; int total=0;
	
		for(int i=0;i<n;i++) (budget[i]<=mid)?total+=budget[i]:total+=mid;
		
		(total<=m)?start=mid+1:end=mid-1;
	}
	return end;
} 
int main(){
	cin>>n;// 나누어줄 곳의 개수.3<=N<=10000;
	int max=0,sum=0;
	for(int i=0;i<n;i++){
		cin>>budget[i];//분배해야할 양.
		sum+=budget[i];
		if(budget[i]>max) max=budget[i];
	}
	cin>>m;// 가지고 있는 예산. 
	
	(sum<=m)?cout<<max:cout<<binarysearch(1,max);
}
