#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	
	string num="1";
	
	while(n--){
		string temp;
		stack <char> S;
		int count=0;
		for(int i=0;i<num.length();i++){
			char number=num[i];
			cout<<number<<"\n";
			if(S.empty()){
				S.push(number);
				count++;
			}else{
				if(S.top()==number){//�� ���� �ִ� ���� ������. 
					count++;
				}else{//�� ���� �ִ� ���� �ٸ���. 
					temp.push_back(S.top());
					char num=count;
					temp.push_back(num);
					S.pop();
					S.push(number);
					count=1;
				}
			}
		}
		num=temp;
	}
	cout<<num;
}
