#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	vector<int> v(n),MAX,MIN;
	for(int i=0;i<n;i++) cin>>v[i];
	sort(v.begin(),v.end());
	
	long long result,sum;
	int count;
	if(n%2==0){
		MAX.push_back(v[n/2-1]);
		for(int i=0;i<n-1;i++){
			MAX.push_back(v[n-i-1]);
			MAX.push_back(v[i]);
		}
		sum=0;
		for(int i=0;i<n-1;i++)
			sum+=abs(MAX[i]-MAX[i+1]);
		result=sum;
		MIN.push_back(v[n/2-1]);
		for(int i=0;i<n-1;i++){
			MIN.push_back(v[i]);
			MIN.push_back(v[n-i-1]);
		}
		sum=0;
		for(int i=0;i<n-1;i++)
			sum+=abs(MIN[i]-MIN[i+1]);
		result=max(sum,result);
	}else{
		MAX.push_back(v[n/2]);
		for(int i=0;i<n-1;i++){
			MAX.push_back(v[n-i-1]);
			MAX.push_back(v[i]);
		}
		sum=0;
		for(int i=0;i<n-1;i++)
			sum+=abs(MAX[i]-MAX[i+1]);
		result=sum;
		MIN.push_back(v[n/2]);
		for(int i=0;i<n-1;i++){
			MIN.push_back(v[i]);
			MIN.push_back(v[n-i-1]);
		}
		sum=0;
		for(int i=0;i<n-1;i++)
			sum+=abs(MIN[i]-MIN[i+1]);	
		result=max(sum,result);
	}
	cout<<result;
}
