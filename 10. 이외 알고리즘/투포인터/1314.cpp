#include<bits/stdc++.h>
using namespace std;

int arr[100001]={0,};
int cnt[100001]={0,};

int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>arr[i];
	
	long long ans=0;
	
	for(int start=1,end=0;start<=n;start++){
		while(end+1<=n&&cnt[arr[end+1]]==0){
			end++;
			cnt[arr[end]]++;
		}
		ans+=end-start+1;
		cnt[arr[start]]--;
	}
	cout<<ans;
}
