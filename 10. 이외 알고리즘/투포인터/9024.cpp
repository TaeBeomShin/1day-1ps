#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	int t;cin>>t;
	while(t--){
		int n,k;cin>>n>>k;
		
		vector<int> v(n);
		for(int i=0;i<n;i++) cin>>v[i];
		sort(v.begin(),v.end());
		
		int left,right,sum,mnum,count=0;
		mnum=2e9;
		
		for(int i=0;i<n-1;i++){
			left=i+1,right=n-1;
			
			while(left<=right){
				int mid=(left+right)/2;
				sum=v[i]+v[mid];
				
				if(sum>k) right=mid-1;
				else if(sum<=k) left=mid+1;
				
				if(abs(k-sum)<mnum){
					count=1;
					mnum=abs(k-sum);
				}else if(abs(k-sum)==mnum) count++;
			}
		}
		cout<<count<<"\n";
	}
}
