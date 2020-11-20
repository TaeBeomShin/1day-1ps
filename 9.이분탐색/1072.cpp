#include<bits/stdc++.h>
#define fastio;
using namespace std;

int main(){
	fastio;
	long long x,y,target;cin>>x>>y;
	target=y*100/x+1;
	
	if(target==100||target==101){
		printf("-1");
		return 0;
	}
	
	int l=0,r=1000000000;
	int ans=-1;
	while(l<=r){
		long long mid=(l+r)/2;//이겨야하는 경기의 수. 
		long long result=(mid+y)*100/(mid+x);
		if(target<=result){
			r=mid-1;
			ans=mid;
			
		}else{
			l=mid+1;
		}
	}
	cout<<ans;
}
