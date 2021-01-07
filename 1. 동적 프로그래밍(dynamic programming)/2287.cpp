#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int n,k,t;
set<int> dp[9];

int check(int n){
	for(int i=1;i<=8;i++)
		if(dp[i].count(n)) return i;
	return 0;
}
int main(){
	fastio;
	cin>>k>>t;
	int num=0;
	for(int i=1;i<=8;i++){
		num=10*num+k;
		dp[i].insert(num);
	}
	
	for(int i=1;i<=8;i++){
		for(int j=1;j<=i;j++){
			int cnt=i+j;
			if(cnt>8) continue;
			for(int a : dp[i]){//i 번으로 만들 수 있는 수 
				for(int b : dp[j]){//j번으로 만들 수 있는 수. 
					dp[cnt].insert(a+b);
					dp[cnt].insert(abs(a-b));
					dp[cnt].insert(a*b);
					if(b!=0)dp[cnt].insert(a/b);
					if(a!=0)dp[cnt].insert(b/a);
				}
			}
		}
	}
	while(t--){
		cin>>n;
		int ret=check(n);
		if(ret) cout<<ret<<"\n";
		else cout<<"NO\n";
	}
	
}
