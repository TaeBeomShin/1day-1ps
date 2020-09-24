#include<bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#define fastio ios::sync_with_stdio(0),cin.tie(0)cout.tie(0)
using namespace std;

//문제풀이법 1.map 두개 사용하기 2.해싱사용 3.map + 이분 탐색. 
int main(){
	fastio;
	int n,m; 
	map <string, int> m1;
	map <int,string> m2;
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char s[21];
		scanf("%s",s);
		m1[s]=i;
		m2[i]=s;
	}
	
	for(int i=0;i<m;i++){
		char input[21];
		scanf("%s",input);
		
		if('0'<=input[0]&&input[0]<='9'){
			cout<<m2[stoi(input)]<<"\n";
		}
		else{	
			cout<<m1[input]<<"\n";
		}
		
	}
}
