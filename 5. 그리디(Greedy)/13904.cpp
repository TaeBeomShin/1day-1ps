#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > v;

bool compare(pair<int,int> a,pair<int,int> b){
	if(a.first!=b.first){
		return a.first<b.first;
	}else{
		return a.second>b.second;
	}
}
int main(){
	int n;cin>>n;
	for(int i=0;i<n;i++){
		int d,w;cin>>d>>w;
		v.push_back({d,w});
	}
	
	sort(v.begin(),v.end(),compare);
	int beforeDay=v[0].first, score=v[0].second;
	
	if(n>1){
		for(int i=1;i<v.size();i++){
			if(beforeDay==v[i].first){
				continue;
			}else{
				beforeDay=v[i].first;
				score+=v[i].second;
			}
		}
	}
	
	cout<<score;
	
}
