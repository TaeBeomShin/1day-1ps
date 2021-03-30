#include<bits/stdc++.h>
using namespace std;

/*
	모든 경우의 수 탐색하기. 
	채널 N으로 이동하기 위해 버튼을 최소 몇 번 눌러야 하는가?
	
	0~9, +와 -
	
	0에서 -를 누르면 채널 안변함
	채널은 무한대 만큼.
	
	N으로 이동하기위해 몇번 눌러야하는가?
	
	모든 경우의 수 탐색하기. 
*/
int n,m,ans=500001;
bool impossible[10];
int main(){
	cin>>n;cin>>m;
	
	for(int i=0;i<m;i++){
		int num;cin>>num;
		impossible[num]=true;
	}
	//1.현재 숫자(100)에서 ++,--이동
	ans=min(ans,abs(n-100)); 
	
	//2.먼저 숫자 버튼을 누른뒤, ++ -- 이용. 
	for(int i=0;i<=999999;i++){
		bool possible=true;
		string num=to_string(i);
		for(int i=0;i<num.length();i++){
			if(impossible[num[i]-'0']){
				possible=false;
				break;
			}
		}
		if(!possible) continue;
		ans=min(ans,abs(i-n)+int(num.length()));
	}
	
	cout<<ans;
}
