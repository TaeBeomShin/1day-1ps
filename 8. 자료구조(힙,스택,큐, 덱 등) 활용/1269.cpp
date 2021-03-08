#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;cin>>n>>m;
	map<int,int> M;
	
	int num;
	for(int i=0;i<n;i++){
		cin>>num;
		M[num]=1;
	}
	
	for(int i=0;i<m;i++){
		cin>>num;
		if(M[num]==1) M.erase(num);
		else M[num]=1;
	}
	
	cout<<M.size();
}
