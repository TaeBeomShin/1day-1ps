#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	string answer;
	cin>>answer;
	for(int i=0;i<n-1;i++){
		string temp;cin>>temp;
		for(int j=0;j<answer.length();j++){
			if(answer[j]!=temp[j]) answer[j]='?';
		}
	}
	cout<<answer;
}
