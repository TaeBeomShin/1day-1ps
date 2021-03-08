#include<bits/stdc++.h>
using namespace std;

/*
	bfs + 역추적
	
	bfs수행하면서 이전의 값을 저장한다.
 	
 */
int before[1000001],cnt[1000001]={0,};
int dx[3]={3,2,1};
int main(){
	int n;cin>>n;
	
	queue<int> Q;
	Q.push(n);
	cnt[n]=0;
	before[n]=-1;
	
	while(!Q.empty()){
		int cur=Q.front();Q.pop();
		if(cur==1) break;
		for(int i=0;i<3;i++){
			if(i==2){
				int next=cur-1;
				if(next>0&&cnt[next]==0){
					Q.push(next);
					before[next]=cur;
					cnt[next]=cnt[cur]+1;
				}
			}else if(cur%dx[i]==0){
				int next=cur/dx[i];
				if(cnt[next]==0){
					Q.push(next);
					before[next]=cur;
					cnt[next]=cnt[cur]+1;
				}
			}
		}
	}
	cout<<cnt[1]<<"\n";
	int num=1;
	vector<int> ans={n};
	while(before[num]!=-1){
		ans.push_back(num);
		num=before[num];
	}
	
	sort(ans.begin(),ans.end(),greater<int>());
	for(int a:ans) cout<<a<<" ";
}
