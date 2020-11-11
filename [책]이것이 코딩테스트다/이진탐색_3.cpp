#include<bits/stdc++.h>
using namespace std;

int arr[1000001];
int main(){
	int n,m;cin>>n>>m;
	for(int i=0;i<n;i++) cin>>arr[i];
	sort(arr,arr+n);
	int start=arr[0];
	int end=arr[n-1];
	int answer=0;
	while(start<=end){
		long long mid=(start+end)/2;
		long long total=0;
		for(int i=0;i<n;i++){
			if(arr[i]>mid) total+=arr[i]-mid;
		}
		if(m==total){
			answer=mid;
			break;
		}
		else if(total<m){
			end=mid-1;
		}else{
			start=mid+1;
		}
	}
	cout<<answer;
}
