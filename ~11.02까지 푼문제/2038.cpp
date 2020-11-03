#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	deque <int> Q;
	Q.push_back(1);
	int start=1,end=1,p=1,q=1;
	int ans=1;
	while(true){
		if(n<=end){
			cout<<ans;
			break;
		}
		if(!Q.empty()&&q>=Q.front()){
			Q.pop_front();
			q=1;
			p++;
		}
		else q++;
		start=end+1;
		end=start+p-1;
		Q.push_back(p);
		ans++;
	}
}
