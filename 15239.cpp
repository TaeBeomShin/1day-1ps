#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	
	string symbol="+_)(*&^%$#@!./,;{}";
	
	while(t--){
//	valid 조건 :
//	소문자가 적어도 한개, 
//	대문자가 적어도한개, 
//	숫자가 적어도 한개, 
//	특수문자가 적어도 한개, 
//	길이가 12이상. 
		int lower=0;
		int upper=0;
		int digit=0;
		int special=0;
		int num;
		bool pass=false;
		cin>>num;
		string s;
		cin>>s;
		
		if(num>=12){
			for(int i=0;i<s.length();i++){
				if(islower(s[i])) lower++;
				else if(isupper(s[i])) upper++;
				else if((s[i]-'0')>=0&&(s[i]-'0')<=9) digit++;
				
				for(int j=0;j<symbol.length();j++){
					if(s[i]==symbol[j]){;
						special++;
					}
				}
			}
		}
		
		pass=lower*upper*digit*special;
		
		if(pass) cout<<"valid\n";
		else cout<<"invalid\n";	
	}
}
