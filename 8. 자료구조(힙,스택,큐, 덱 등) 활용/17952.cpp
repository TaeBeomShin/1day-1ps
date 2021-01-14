#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	stack<pair<int,int>> S;
	int score,time;
	int sum=0;
	for(int i=0;i<n;i++){
		int num;cin>>num;
		if(num==1){
			cin>>score>>time;
			S.push({score,time});
			S.top().second--;
		}else if(!S.empty()){
			S.top().second--;
		}
		if(!S.empty()&&S.top().second==0){
			sum+=S.top().first;
			S.pop();
		}
	}
	cout<<sum;
}
