#include<bits/stdc++.h>
using namespace std;
/*
	BOJ 1541 �Ҿ���� ��ȣ
	 
	- ����, ���ÿ� ���� �����ڸ� ���� ���� -�� �ö����� ���� ��� ������ ���� ����.
	- �Է� ó���ϴ°� ���� �������.. 
*/
int main(){
	stack<string> S;
	string s;cin>>s;
	
	
	for(int i=0;i<s.length();i++){
		if(s[i]=='-'||s[i]=='+'){
			string temp=s.substr(i,1);
			S.push(temp);
		}else{
			int start=i;
			while(i<s.length()){
				if(s[i]=='-'||s[i]=='+'){
					i--;
					break;
				}else{
					i++;
				}
			}
			S.push(s.substr(start,i-start+1));
			
		}
	}
	int ans=0,sum=0;
	while(!S.empty()){
		if(S.top()=="-"){
			ans-=sum;
			sum=0;
		}else if(S.top()!="+"){
			sum+=stoi(S.top());
		}
		S.pop();
	}
	cout<<ans+sum;
}
