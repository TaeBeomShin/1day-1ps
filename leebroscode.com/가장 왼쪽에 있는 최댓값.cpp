#include<bits/stdc++.h>
using namespace std;


int main(){
	int n;cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	
	vector<int> ans;
	int maxidx=n;
	while(true){
		int maxnum=0,tempidx=0;
		//최대값과 인덱스. 
		for(int i=0;i<maxidx;i++){
			if(maxnum<v[i]){
				maxnum=v[i];
				tempidx=i;
			}
		}
		maxidx=tempidx;
		ans.push_back(maxidx);
		if(maxidx==0){
			break;
		}
	}
	for(int a :ans) cout<<a+1<<" "; 
	
}
