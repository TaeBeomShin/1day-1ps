#include<bits/stdc++.h>

using namespace std;

int number[1000001];
int seq[1000001];
long long dp[1000001]={0,};
int n,k,q;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=0;i<k;i++){//O(n*k);
		cin>>number[i];
	}
	
	sort(number,number+k);//수행할 쿼리들을 오름차순으로 정렬시킴.
	 
	for(int i=0;i<k;){//쿼리를 한번에 모아서 수행한다. 
	/*
	i=0; temp=number[0]; cnt=0;
	  
	*/ 
		int temp=number[i];
		int cnt=0;
		
		for(;i<k&&number[i]==temp;i++) cnt++;
		
		for(int i=0;i<n;i+=temp)
			seq[i]+=cnt;
	} 
	
	dp[1]=0;
	for(int i=1;i<=n;i++){//O(n) 
		dp[i]=dp[i-1]+seq[i-1];
	}
	cin>>q;
	
	while(q--){//O(n)
		int start,end;
		cin>>start>>end;
		cout<<dp[end+1]-dp[start]<<"\n";
	}
	
	return 0;
}
