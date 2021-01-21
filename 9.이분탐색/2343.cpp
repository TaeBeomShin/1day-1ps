#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;cin>>n>>m;
	
	
	int A[n]={0,},left=0,right=0;
	for(int i=0;i<n;i++){
		cin>>A[i];
		left=max(left,A[i]);
		right+=A[i];
	}
	
	// LEFT 블루레이의 최소크기(원소중 가장큰값)
	// RIGHT 블루레이의 최대크기(모든 블루레이를 합친값. 
	while(left<=right){
		int mid=(left+right)/2;
		
		int count=1,sum=0; 
		for(int i=0;i<n;i++){
			if(sum+A[i]<=mid){
				sum+=A[i];	
			}else{//sum에 더했을때 블루레이의 크기를 넘는 경우. 
				sum=A[i];
				count++;
			}
		}
		if(count<=m){//블루레이의 개수가 더 작을 경우-> 크기를 줄인다. 
			right=mid-1; 
		}else{
			left=mid+1;
		}
	}
	cout<<left;
}
