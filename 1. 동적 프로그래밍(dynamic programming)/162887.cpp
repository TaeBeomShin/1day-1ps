#include<bits/stdc++.h>
using namespace std;

bool isTrue[799995];
int arr[5001];

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,w;
	
	cin>>w>>n;
	for(int i=1;i<=n;i++) cin>>arr[i];
	for(int i=0;i<=n;i++){
		for(int j=1;j<i-1;j++) isTrue[arr[i-1]+arr[j]]=1;
		for(int j=i+1;j<=n;j++){
			if(arr[i]+arr[j]>w) continue;
			if(isTrue[w-(arr[i]+arr[j])]){
				cout<<"YES";
				return 0;
			}
		}
	}
	cout<<"NO";
} 
