#include<bits/stdc++.h>
#include<string.h>
using namespace std;

string n;
int minn=1e9,maxn=0,s_size;
int mcnt=0;

void dfs(string s,int ans){
	int cnt=0;
	for(int i=0;i<s.length();i++){
		int num=s[i]-'0';
		if(num%2==1) cnt++;
	}
	
	if(s.length()==1){
		maxn=max(ans+cnt,maxn);
		minn=min(minn,ans+cnt);
		return;
	}
	
	if(s.length()==2){
		int result=0;
		result+=s[0]-'0';
		result+=s[1]-'0';
		string new_s=to_string(result);
		dfs(new_s,ans+cnt);
	}

	if(s.length()>=3){
		for(int i=1;i<=s.length()-2;i++){
			for(int j=i+1;j<=s.length()-1;j++){
				int num1=stoi(s.substr(0,i)),
				num2=stoi(s.substr(i,j-i)),
				num3=stoi(s.substr(j,s.length()-j));
				int sum=num1+num2+num3;
				dfs(to_string(sum),ans+cnt);
			}
		}
		
	}
}
int main(){
	cin>>n;
	
	s_size=n.length();
	dfs(n,0);
	cout<<minn<<" "<<maxn;
}
