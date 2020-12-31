#include<bits/stdc++.h>
using namespace std;

int MAX=10000000;
bool check[10000000];
int main(){
	int k;cin>>k;
	fill(check,check+MAX,1);
	check[0]=0;check[1]=0;
	
	vector<int> v;
	for(int i=2;i<MAX;i++){
		if(check[i]){
			v.push_back(i);
			for(int j=i;j<=MAX;j+=i) check[j]=0;
		}
	}
	
	cout<<v[k-1];
}
