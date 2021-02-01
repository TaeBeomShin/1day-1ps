#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	vector<pair<int,int> > A(n);
	for(int i=0;i<n;i++){
		int num;cin>>num;
		A[i]={num,i};
	}
	
	sort(A.begin(),A.end(),less<pair<int,int>>());
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(A[j].second==i){
				cout<<j+1<<" ";
			}
		}
	}
}
