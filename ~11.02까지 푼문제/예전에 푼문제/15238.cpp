#include<iostream>
#include<algorithm>
using namespace std;

int alpha[26];
int main(){
	int n;
	char s;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		alpha[s-'a']++;
	}
	
	int max=0;
	int index;
	for(int i=0;i<26;i++){
		if(alpha[i]>max){
		max=alpha[i];
		index=i;
		}
	}
	
	char result = index+'a';
	cout<<result<<" "<<alpha[index];
	return 0;
	
}
