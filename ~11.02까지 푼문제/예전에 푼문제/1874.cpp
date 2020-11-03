#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	int array[n];
	vector <char> answer;
	stack<int> s;
	
	for(int i=0;i<n;i++) cin>>array[i];
	
	int j=0;
	
	for(int i=1;i<=n;i++){
		s.push(i);
		answer.push_back('+');
		
		while(!s.empty()&&s.top()==array[j]){
			s.pop();
			answer.push_back('-');
			j++;
		}
	}
	
	if(!s.empty()) cout<<"NO";
	else{
		for(int i=0;i<answer.size();i++) cout<<answer[i]<<"\n";
	}
}
