#include<bits/stdc++.h>
using namespace std;

int n,m;
int arr[300001]={0,};
bool check(int mid){
	int num=0;
	for(int i=0;i<m;i++){
		num+=arr[i]/mid;
		if(arr[i]%mid) num++;
	}
	
	return n>=num;
}
int main(){
	cin>>n>>m;
	
	int l=1,r;
	for(int i=0;i<m;i++){
		cin>>arr[i];
		r=max(r,arr[i]);
	}
	
	int ans=1e9;
	while(l<=r){
		//나눠줄 보석 개수 기준 
		int mid=(l+r)/2;
		if(check(mid)){
			ans=min(ans,mid);
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	cout<<ans;
}
