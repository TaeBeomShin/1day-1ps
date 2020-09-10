#include<bits/stdc++.h>
using namespace std;

int n,s,sum,cnt;
int arr[20];

void dfs(int i,int sum){
	//dfs 융형. 
	/* 1.체크인 	
	 * 2.목적지인가? 	
	 * 3.갈 수 있는곳을 	
	 * 4.갈 수 있는가? 	
	 * 5.간다 		
	 * 6.체크아웃
	 */
	if(i==n) return;//종료조건. 
	if(sum+arr[i]==s) cnt++;//cnt를 증가시킬 조건. 
	
	dfs(i+1,sum);//1. 선택하지 않은경우. 
	dfs(i+1,sum+arr[i]);//2. 선택한 경우. 
}

int main(){
	cin>>n>>s;
	for(int i=0;i<n;i++) cin>>arr[i];
	
	cnt=0;
	dfs(0,0);
	
	cout<<cnt;
	
	return 0;	
}
