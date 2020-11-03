#include<iostream>
#include<cstring>

using namespace std;

int findString(string parent, string pattern){
	int parentSize = parent.size();
	int patternSize =pattern.size();
	int parentHash=0,patternHash=0,power=1;
	int match=0;
	for(int i=0;i<=parentSize - patternSize;i++){
		if(i==0){
			for(int j=0;j<patternSize;j++){
				parentHash=parentHash+parent[patternSize-1-j]*power;
				patternHash=patternHash+pattern[patternSize-1-j]*power;
				if(j<patternSize-1) power=power*403;
			}
		}
		else{
			parentHash=403*(parentHash-parent[i-1]*power)+parent[patternSize-1+i];
		}
		if(parentHash==patternHash){
			match++;
		}
	}
	return match;
}

int main(){
	string parent="ababacabacaabacaaba";
	string pattern="abacaaba";
	cin>>parent>>pattern;
	if(findString(parent,pattern)) cout<<"1";
	else cout<<"0";
	
	return 0;
}
//https://m.blog.naver.com/PostView.nhn?blogId=ndb796&logNo=221240679247&proxyReferer=https:%2F%2Fwww.google.com%2F
//의 라빈카프 소스코드 이용.
