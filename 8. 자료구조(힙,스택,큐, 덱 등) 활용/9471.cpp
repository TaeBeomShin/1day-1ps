#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;
	
	while(t--){
		int n,m;cin>>n>>m;
		vector<int> fibo={0,1,1};
		int idx=2;
		while(true){
			if(fibo[idx]==0&&fibo[idx-1]==1) break;
			int value=(fibo[idx]+fibo[idx-1])%m;
			fibo.push_back(value);
			idx++;
		}
		cout<<n<<" "<<idx<<"\n";
	}
}
