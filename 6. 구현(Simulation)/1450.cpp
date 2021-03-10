#include<bits/stdc++.h>
using namespace std;

int n,s,threshold,A[30];
long long sum,sum2;
map<long long,int> cnt1;
map<long long,int> cnt2;

void dfs1(int pos){//pos:현재 탐색중인 인덱스. 
	if(pos==threshold){
		auto iter=cnt1.find(sum);
		if(iter!=cnt1.end()) ++iter->second;
		else cnt1[sum]=1;
		return;
	}
	dfs1(pos+1);
	sum+=A[pos];
	dfs1(pos+1);
	sum-=A[pos];
}

void dfs2(int pos){
	if(pos==n){
		auto iter=cnt2.find(sum2);
		if(iter!=cnt2.end()) ++iter->second;
		else cnt2[sum2]=1;
		
		return;
	}
	dfs2(pos+1);
	sum2+=A[pos];
	dfs2(pos+1);
	sum2-=A[pos];
}
int main(){
	//n개의 물건, 최대 c만큼 넣을 수 있음. 
	cin>>n>>s;
	for(int i=0;i<n;i++) cin>>A[i];
	threshold=n/2;
	
	dfs1(0);
	dfs2(threshold);
	
	long long result=0;
	for(auto m : cnt1){
		long long mk=m.first,mv=m.second;
		if(mk>s) continue;
		if(cnt2[s-mk]) result+=mv*cnt2[s-mk];
	}
	if(result!=1) result++;
	cout<<result;
}
