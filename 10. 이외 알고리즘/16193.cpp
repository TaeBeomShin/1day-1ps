#include<bits/stdc++.h>
using namespace std;

int n;
long long getSum(vector<int> &v){
	long long sum=0;
	for(int i=0;i<n-1;i++)
		sum+=abs(v[i]-v[i+1]);
	return sum;
}
int main(){
	cin>>n;
	vector<int> v(n),MAX,MIN;
	for(int i=0;i<n;i++) cin>>v[i];
	sort(v.begin(),v.end());

	if(n%2==0){
		MAX.push_back(v[n/2-1]);
		MIN.push_back(v[n/2-1]);
	}else{
		MAX.push_back(v[n/2]);
		MIN.push_back(v[n/2]);
	}
	
	for(int i=0;i<n-1;i++){
		MAX.push_back(v[n-i-1]);
		MAX.push_back(v[i]);
	}
	
	for(int i=0;i<n-1;i++){
		MIN.push_back(v[i]);
		MIN.push_back(v[n-i-1]);
	}
	cout<<max(getSum(MIN),getSum(MAX));
}
