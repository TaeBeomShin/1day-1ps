#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,a,num;
	cin>>t;
	
	while(t--){
		int dp[10001]={0,};
		cin>>a;
		int temp;
		vector<int>q; //������ ������ ����. 
		
		for(int i=0;i<a;i++){
			cin>>temp;
			q.push_back(temp);
		}
		cin>>num;//�������� �ݾ�.
		
		for(int i=0;i<=num;i++){
			if(i%q[0]==0) dp[i]++;
		}
		
		for(int i=1;i<a;i++)
			for(int j=q[i];j<=num;j++)
				dp[j]+=dp[j-q[i]];
			
		cout<<dp[num]<<"\n";
	}
}
