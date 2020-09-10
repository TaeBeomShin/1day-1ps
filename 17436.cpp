#include<bits/stdc++.h>

using namespace std;
//백트래킹 + 포함배제의 원리
//포함배제의 원리 공식을 위해 nCr을 구하고 값을 계산하는 백트래킹 과정 필요. 
int n;
long long m,sum,d;
vector<int> v,picked;

void go(int start, int remain){
	if(remain==0){
		d=1;
		for(int i=0;i<picked.size();i++){
			d*=v[picked[i]];	
		} 
		if(picked.size()%2) sum+=m/d;
		else sum-=m/d;
		return;
	}
	for(int i=start+1;i<n;i++){
		picked.push_back(i);
		go(i,remain-1);
		picked.pop_back();
	}
}
int main(){
	cin>>n>>m;
	int a=n;
	while(a--){
		int temp;cin>>temp;
		v.push_back(temp);
	}
	
	//포함배제의 원리를 이용.
	//n의 개수에 따라 달라짐.
	sum=0;
	for(int i=1;i<=n;i++){//고르는 소수의 개수.
	//i=1, 단일항 A,B, ... i=2, 교집합 A&B,B&C,A&C,...을 뺌. 유사하게 진행. 
		go(-1,i);
	}
	cout<<sum;
	
	return 0;	
}
