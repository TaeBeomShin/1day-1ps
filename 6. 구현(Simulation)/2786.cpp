#include<bits/stdc++.h>
using namespace std;

int compare(const pair<int,int> &a,const pair<int,int> &b){
	return a.second<b.second;
}

int arr[500001];

int main(){
	int n;cin>>n;
	vector<pair<int,int>> v(n);
	
	for(int i=0;i<n;i++) cin>>v[i].first>>v[i].second;
	sort(v.begin(),v.end(),compare);

	
	long long sum=0;
	int idx=0;
	
	arr[n]=2e9;
	for(int i=n-1;i>=0;i--) arr[i]=min(v[i].first,arr[i+1]);
	for(int i=0;i<n;i++){
		if(v[idx].second-v[idx].first<v[i].second-v[i].first) idx=i;
		sum+=(long long)v[i].second;
		cout<<(long long)min(sum-v[idx].second+v[idx].first,sum-v[i].second+arr[i])<<"\n";
	}
}
