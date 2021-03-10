#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		//1. 값을 입력받아서 key 배열을 만듬. 
		map<string,int> M;
		for(int i=0;i<n;i++){
			string m;cin>>m;
			if(M[m]) M[m]+=1;
			else M[m]=1;
		}
		int size=M.size();
		
		int ans=1e8;
		vector<string> V;
		for(auto mbit:M){
			string k=mbit.first;
			int v=mbit.second;
			for(int i=0;i<min(3,v);i++) V.push_back(k);
		}
		vector<int> A;A.resize(V.size());
		A[0]=1;A[1]=1;A[2]=1;
		sort(A.begin(),A.end());
		
		do{
			vector<string> temp;
			for(int i=0;i<A.size();i++){
				if(A[i]==1) temp.push_back(V[i]);
			}
			
			int tcnt=0;
			for(int i=0;i<4;i++){
				string sA=temp[0],sB=temp[1],sC=temp[2];
				if(sA[i]!=sB[i]) tcnt++;
				if(sA[i]!=sC[i]) tcnt++;
				if(sB[i]!=sC[i]) tcnt++;
			}
			ans=min(tcnt,ans);
		}while(next_permutation(A.begin(),A.end()));
		cout<<ans<<"\n";
	}
} 
