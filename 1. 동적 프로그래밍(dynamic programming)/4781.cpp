#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int main(){
	
	fastio;
	int n;float m;
	
	while(true){
		cin>>n>>m;
		if(n==0) break;
		
		int budget=100*m;
		int dp[10001]={0,};
		vector<pair<int,int> > candy;
		
		for(int i=0;i<n;i++){
			int c;float p;
			cin>>c>>p;
			int price=p*100;
			candy.push_back({c,price});
		}

		for(int i=1;i<=budget;i++){
			for(int j=0;j<candy.size();j++){
				if(i-candy[j].second>=0) 
					dp[i]=max(dp[i],dp[i-candy[j].second]+candy[j].first);
			}
		}
		cout<<dp[budget]<<"\n";
	}
}
