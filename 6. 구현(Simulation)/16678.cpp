#include<bits/stdc++.h>
using namespace std;

// 예제에 낚여서 생각을 이상하게함... 
int arr[100001]={0,},n,m=1;
long long hacker=0;
int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	sort(arr,arr+n);
	
	for(int i=0;i<n;i++){
		if(arr[i]>=m){
			hacker+=arr[i]-m;
			m++;
		}
	}
	cout<<hacker;
}
