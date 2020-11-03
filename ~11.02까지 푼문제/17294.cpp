#include<bits/stdc++.h>
using namespace std;

int number[19];
vector <int> v;
int main(){
	string num;cin>>num;
	
	for(int i=0;i<num.length();i++) number[i]=num[i]-'0';
	
	for(int i=0;i<num.length()-1;i++) v.push_back(number[i+1]-number[i]);
	
	int first=v[0];
	bool check =true;
	for(int i=0;i<v.size();i++){
		if(v[i]!=first) check=false;
	}
	
	(check)?cout<<"?(?????)?..¡Æ¢½ ²î¿ä¹Ì!!":cout<<"ÈïÄ©»×!! <(£þ ? £þ)>";
	
}
