#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<long long> num;
	for(int i=1;i<=1023;i++){
		long long number=0;
		int tmp_i=i;
		for(int idx=9;idx>=0;idx--){
			if(tmp_i%2==1)	number=10*number+idx;
			tmp_i/=2;
		}
		num.push_back(number);
	}
	sort(num.begin(),num.end());
	int n;
	cin>>n;
	if(n>1023) cout<<-1;
	else cout<<num[n-1];
} 
