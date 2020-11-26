#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int money[100001];
int main(){
	fastio;
	int n,m,count;cin>>n>>m;
	int ans,l=0,r=int(1e9);
	for(int i=0;i<n;i++) cin>>money[i];
	
	while(l<=r){
		bool check=false;
		int mid= (l+r)/2,temp=0,count=0;
		
		for(int i=0;i<n;i++){
			if(mid<money[i]){
				check=true;
				break;
			}
			if(temp<money[i]||m-count==n-i){
				count++;
				temp=mid;
			}
			temp-=money[i];
		}
		if(count>m||check){
			l=mid+1;
		}else if(count<m){
			r=mid-1;
		}else{
			ans=mid;
			r=mid-1;
		}
	}
	cout<<ans;
}
