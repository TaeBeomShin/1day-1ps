#include<bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

//����Ǯ�̹� 1.map �ΰ� ����ϱ� 2.�ؽ̻�� 3.map + �̺� Ž��. 
int main(){
	fastio;
	int n,m; cin>>n>>m;
	map <int,string> m1;
	map <string, int> m2;
	
	for(int i=1;i<=n;i++){
		char s[21]; cin>>s;
		m1[i]=s;
		m2[s]=i;
	}
	
	while(m--){
		char input[21];cin>>input;
		
		if('0'<=input[0]&&input[0]<='9') cout<<m1[stoi(input)]<<"\n";
		else cout<<m2[input]<<"\n";
		
	}
}
