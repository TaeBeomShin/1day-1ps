#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int main(){
	fastio;
	int n;cin>>n;
	int tower[n+1];
	stack <pair<int,int> > s;
	for(int i=1;i<=n;i++) cin>>tower[i];
	/*
		자기보다 큰 탑 중에 가장 가까이 있는 탑에 신호를 보낸다(스택의 가장 위에 있는 값.) 
		현재 들어온 값보다 높이가 작으면 더이상 신호를 못받는다-> 스택에서 제거한다. 
	*/
	for(int i=1;i<=n;i++){
		bool check=false;//왼쪽에 자신보다 큰 탑을 찾았는지 체크. 
		while(!s.empty()){
			if(s.top().second>=tower[i]){
				cout<<s.top().first<<" ";
				s.push({i,tower[i]});
				check=true;
				break;
			}
			else{
				s.pop();
			}
		}
		if(!check){
			s.push({i,tower[i]});
			cout<<0<<" ";
		}
	}
}
