#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int main(){
	int n;cin>>n;
	int numbers[n];
	stack<pair<int,int> > s;
	
	for(int i=0;i<n;i++) cin>>numbers[i];
	//���� �ڷᱸ���� �̿��Ͽ� Ǫ�¹�? 
	
	for(int i=0;i<n;i++){
		bool check=false;
		while(!s.empty()){
			if(s.top().second>=numbers[i]){
				cout<<s.top().first<<" ";
				s.push(make_pair(i+1,numbers[i]));
				check=true;
				break;
			}
			else{
				s.pop();
			}
		}
		if (!check){
			s.push(make_pair(i+1,numbers[i]));
			cout<<0<<" ";
		}
	}

}
