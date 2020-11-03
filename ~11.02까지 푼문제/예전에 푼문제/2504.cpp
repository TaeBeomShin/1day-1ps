#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

int main(){
	stack<char> s;
	string input;
	cin>>input;
	
	long long result=0;
	int temp=1;
	bool flag=false;
	for(int i=0;i<input.size();i++){
		if(input[i]=='('){
			temp*=2;
			s.push('(');
		}
		else if(input[i]=='[')
		{
			temp*=3;
			s.push('[');
		}
		else if(input[i]==')'&&(s.empty()||s.top()!='('))
		{
			flag=true;
			break;
		}
		else if(input[i]==']'&&(s.empty()||s.top()!='['))
		{
			flag=true;
			break;
		}
		else if(input[i]==')')
		{
			if(input[i-1]=='(')
				result+=temp;
			s.pop();
			temp/=2;
		}else if(input[i]==']')
		{
			if(input[i-1]=='[')
				result+=temp;
			s.pop();
			temp/=3;
		}
	}
	if(flag||!s.empty())
		cout<<0<<"\n";
	else
		cout<<result<<"\n";
		
	return 0;
}
