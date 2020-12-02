#include<bits/stdc++.h>
using namespace std;

int arr[51][51];
vector<pair<int,int> >house;
vector<pair<int,int> >chicken;
int main(){
	int n,m;cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
			if(arr[i][j]==1) house.push_back({i,j});
			if(arr[i][j]==2) chicken.push_back({i,j});
		}
	}
	int mn=1e9;
	vector<int> check(chicken.size(),1);
	fill(check.begin(),check.begin()+chicken.size()-m,0);
	do{
		int dist=0;
		for(auto h : house){
			int temp=1e9;
			for(int i=0;i<chicken.size();i++){
				if(check[i]==0) continue;
				temp=min(temp,abs(chicken[i].first-h.first)+abs(chicken[i].second-h.second));
			}
			dist+=temp;
		}
		mn=min(mn,dist);
	}while(next_permutation(check.begin(),check.end()));
	cout<<mn;
}
