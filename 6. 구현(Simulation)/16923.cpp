#include<bits/stdc++.h>
using namespace std;

int cnt[26]={0,};
char word[26]={0,};
int main(){
	string s; cin>>s;
	for(int i=0;i<s.length();i++){
		cnt[s[i]-'a']++;
		word[i]=s[i];
	}
	if(s.length()<26){//문자열의 길이가 26이하. 
		bool check=false;
		char w;
		for(int i=0;i<26;i++){
			if(cnt[i]==0){
				check=true;
				w='a'+i;
				break;
			}
		}
		(check)?cout<<s<<w:cout<<-1;
	}
	else{//문자열의 길이가 26이상. 
		(next_permutation(word,word+27))?cout<<word:cout<<-1;
	}
	
}
