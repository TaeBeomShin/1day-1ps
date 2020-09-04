#include<iostream>
#include<string>

using namespace std;

string Add(string &s1, string &s2){
	bool carry=false;
	string result(max(s1.size(),s2.size()),'0');
	
	for(int i=0;i<result.size();i++){
		int temp=carry;
		carry=false;
		
		if(i<s1.size()) temp+=s1[s1.size()-i-1]-'0';
		if(i<s2.size()) temp+=s2[s2.size()-i-1]-'0';
		if(temp>=10)
		{
			carry=true;
			temp-=10;
		}
		result[result.size()-i-1]=temp+'0';
	}
	
	if(carry)
		result.insert(result.begin(),'1'); //둘을 합쳤을때, 사이즈가 더커짐.
	return result; 
} 
int main(){
	int n;
	cin>>n;
	string a="0";
	string b="1";
	if(n>0) cout<<"1\n";
	else if(n==0) cout<<"0\n";
	else{
		cout<<"-1\n";
		n=-n;
	}

	if(n==0) cout<<a;
	else if(n==1) cout<<b;
	else{
		string result;
		for(int i=2;i<=n;i++){
			result=Add(a,b);
			a=b;
			b=result;
		}
		cout<<result;
	}
	
	return 0;
	//n은 매우 큰 수. n번째 피보나치수를 1000000으로 나눈 나머지 구하기. 
} 
