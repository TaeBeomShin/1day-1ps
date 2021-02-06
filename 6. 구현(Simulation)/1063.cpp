#include<bits/stdc++.h>
using namespace std;

int main(){
	pair<int,int> stone;
	pair<int,int> king;
	
	string s,k;int n;cin>>s>>k>>n;
	
	stone={int(s[0])-int('A'),stoi(s[1])};
	king={int(k[0])-int('A'),stoi(s[1])};
	
	while(n--){
		string command;cin>>command;
		int cx=stone[0],cy=stone[1];
		if(command=="R"){
			cx+=1;
		}else if(command=="L"){
			cx-=1;
		}else if(command=="B"){
			cy+=1;
		}else if(command=="T"){
			cy-=1;
		}else if(command=="RT"){
			cx+=1;cy-=1;
		}else if(command=="LT"){
			cx-=1;cy-=1;
		}else if(command=="RB"){
			cx+=1;cy+=1;
		}else if(command=="LB"){
			cx-=1;cy+=1;
		}
	}
} 
